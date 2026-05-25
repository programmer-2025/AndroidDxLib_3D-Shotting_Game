# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

include_directories(C:/ProgramData/DxLib_Android/Lib_AndroidStudio/${ANDROID_ABI} )
link_directories(C:/ProgramData/DxLib_Android/Lib_AndroidStudio/${ANDROID_ABI} )

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("AndroidDxLib_Shotting_Game")
find_library(log-lib log)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        Manager/ObjectManager.cpp
        Manager/SceneManager.cpp
        Object/Enemy.cpp
        Object/BaseObject.cpp
        Scene/BootScene.cpp
        Scene/TitleScene.cpp
        Scene/PlayScene.cpp
        Scene/ClearScene.cpp
        Debug/ImGUI/imgui.cpp
        Debug/ImGUI/imgui_draw.cpp
        Debug/ImGUI/imgui_demo.cpp
        Debug/ImGUI/imgui_impl_android.cpp
        Debug/ImGUI/imgui_tables.cpp
        Debug/ImGUI/imgui_widgets.cpp
        Debug/ImGUI/imgui_impl_opengl3.cpp)

target_compile_definitions(native-lib PRIVATE IMGUI_IMPL_OPENGL_ES2)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_MODE)
endif()

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries( # Specifies the target library.
        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        android
        GLESv1_CM
        EGL
        GLESv2
        OpenSLES
        m
        DxLib
        DxUseCLib
        jpeg
        png
        zlib
        tiff
        theora_static
        vorbis_static
        vorbisfile_static
        ogg_static
        bullet
        opus )