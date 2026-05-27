#include <jni.h>
#include <string>
#include <DxLib.h>
#include <GLES3/gl3.h>
#include "MyDxlib.h"
#include "Manager/ObjectManager.h"
#include "Manager/SceneManager.h"
#include "Debug/ImGUI/imgui.h"
#include "Debug/ImGUI/imgui_impl_android.h"
#include "Debug/ImGUI/imgui_impl_opengl3.h"

float DELTA_TIME = 0.0f;

namespace {
    float beforeTime = 0.0f;
    float afterTime = 0.0f;
}

int initApp();
void exitApp();
int32_t AndroidInputCallback( AInputEvent *InputEvent, void *Data );

int android_main() {
    if (initApp() == -1) {
        exitApp();
    }

    beforeTime = GetNowCount();
    afterTime = GetNowCount();

    while (true) {
        ClearDrawScreen();

        afterTime = GetNowCount();
        DELTA_TIME = (afterTime - beforeTime) / 1000.0f;
        beforeTime = afterTime;

        ImGui_ImplAndroid_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        int touch = GetTouchInputNum();
        auto& io = ImGui::GetIO();

        SceneManager::UpdateCurrentScene();
        ObjectManager::UpdateAllObjects();
        SceneManager::DrawCurrentScene();
        ObjectManager::DrawAllObjects();

        ImGui::Render();
        ImDrawData* draw_data = ImGui::GetDrawData();

        for (int n = 0; n < draw_data->CmdListsCount; n++) {
            ImDrawList* cmd_list = draw_data->CmdLists[n];

            for (int v = 0; v < cmd_list->VtxBuffer.Size; v++) {
                cmd_list->VtxBuffer[v].pos.y =
                        io.DisplaySize.y - cmd_list->VtxBuffer[v].pos.y;
            }

            for (int c = 0; c < cmd_list->CmdBuffer.Size; c++) {
                ImDrawCmd& cmd = cmd_list->CmdBuffer[c];
                float leftUpY = cmd.ClipRect.y; // 左上y座標
                float rightDownY = cmd.ClipRect.w; // 右下y座標

                cmd.ClipRect.y = io.DisplaySize.y - rightDownY; //例：1980（ディスプレイサイズ）- 1000(右下のy座標) = 左上のy座標
                cmd.ClipRect.w = io.DisplaySize.y - leftUpY; //例：1980（ディスプレイサイズ）- 500(左上のy座標) = 右下のy座標
            }
        }


        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        ScreenFlip();
        WaitTimer(16);
        if (ProcessMessage() == -1) {
            break;
        }
    }

    return 0;
}

int initApp() {
    // ＤＸライブラリ初期化処理
    SetGraphMode(1280, 720, 32); //仮の解像度
    SetBackgroundColor(DxLibParams::BACKGROUND_COLOR[0], DxLibParams::BACKGROUND_COLOR[1], DxLibParams::BACKGROUND_COLOR[2]);

    if (DxLib_Init() == -1) {
        DxLib_End();
        return -1;
    }
    SetDrawScreen(DX_SCREEN_BACK);
    SetAlwaysRunFlag(TRUE);
    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);

    int width = 1280, height = 720;
    DxLib::GetAndroidDisplayResolution(&width, &height); //android用の解像度取得関数
    SetGraphMode(width, height, 32);
    DxLibParams::ChangeFontSize(3.0);

    // MyDxlibの初期化
    ObjectManager::InitManager();
    SceneManager::InitManager();

    //ImGUIを初期化
    ImGui::CreateContext();
    auto& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(3.0f);
    io.FontGlobalScale = 3.0f;

    ImGui::StyleColorsDark();
    ImGui_ImplAndroid_Init(const_cast<ANativeWindow*>(GetNativeWindow()));
    ImGui_ImplOpenGL3_Init();
    SetAndroidInputEventFookFunction( AndroidInputCallback, NULL );

    return 0;
}

void exitApp() {
    DxLib_End();
    return;
}

int32_t AndroidInputCallback( AInputEvent *InputEvent, void *Data ) {
    ImGui_ImplAndroid_HandleInputEvent(InputEvent);
    return 0;
}