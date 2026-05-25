//
// Created by user on 2026/03/13.
//

#ifndef MYDXLIB_ANDROID_MYDXLIB_H
#define MYDXLIB_ANDROID_MYDXLIB_H

#include <vector>
#include <__filesystem/directory_iterator.h>

extern float DELTA_TIME;

namespace {

    /// <summary>
    /// Android版のDxLibには無いフォント一覧を取得する関数
    /// <summary>
    inline std::vector<std::string> GetSystemFonts() {
        const char* fontPath = "/system/fonts/"; //フォントの場所
        std::vector<std::string> fonts;
        for (const auto& entry : std::filesystem::directory_iterator(fontPath)) { // ディレクトリをループする
            if (entry.is_regular_file()) { //ディレクトリとかは無視（※ファイルのみを示す）
                fonts.push_back(entry.path().filename().string()); //フルパスではなく、○○.ttf でvectorに格納する
            }
        }
        return fonts;
    }

    /// <summary>
    /// スクリーンショットを保存する関数
    /// </summary>
    inline bool saveScreenShot(const char* savePath) {
        int width, height;
        GetDrawScreenSize(&width, &height);
        DATEDATA dateData;
        GetDateTime(&dateData);

        char path[1024];
        if (savePath == nullptr) {
            GetInternalDataPath(path, sizeof(path)); //内部ストレージのパスを取得する
        }
        else {
            strcpy(path, savePath); //引数がある場合は変数にコピー
        }

        char filename[256]; //形式の例：screenshort_2026-01-01_0001.png
        sprintf(filename, "%s/screenshot_%d-%d-%d_%d%d.png", path, dateData.Year, dateData.Mon, dateData.Day, dateData.Hour, dateData.Min);
        if (SaveDrawScreenToPNG(0, 0, width, height, filename) == -1) {
            return false;
        }
        else {
            return true;
        }
    }
}

/// <summary>
/// デフォルトのDxLibの設定。
/// </summary>
namespace DxLibParams {
    static const int FONT_TYPE = DX_FONTTYPE_ANTIALIASING_EDGE;
    static const int BACKGROUND_COLOR[3] = {255, 255, 255};
    static const float FONT_SCALE = 1.0f;

    inline void ChangeFontSize(float scale) {
        if (scale < 0.0f) return;
        SetFontSize(GetFontSize() * scale);
    }
}

#endif //MYDXLIB_ANDROID_MYDXLIB_H
