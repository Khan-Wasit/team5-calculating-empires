/**********************************************************************************************
*
*   raylib v6.5-dev - A simple and easy-to-use library to enjoy videogames programming (www.raylib.com)
*
*   FEATURES:
*       - NO external dependencies, all required libraries included with raylib
*       - Multiplatform: Windows, Linux, macOS, FreeBSD, Web, Android, Raspberry Pi, DRM native...
*       - Written in plain C code (C99) in PascalCase/camelCase notation
*       - Hardware accelerated with OpenGL (1.1, 2.1, 3.3, 4.3, ES2, ES3 - choose at compile)
*       - Software renderer optional, for systems with no GPU: [rlsw]
*       - Custom OpenGL abstraction layer (usable as standalone module): [rlgl]
*       - Multiple Fonts formats supported (TTF, OTF, FNT, BDF, Sprite fonts)
*       - Many texture formats supported, including compressed formats (DXT, ETC, ASTC)
*       - Full 3d support for 3d Shapes, Models, Billboards, Heightmaps and more!
*       - Flexible Materials system, supporting classic maps and PBR maps
*       - Animated 3D models supported (skeletal bones animation) (IQM, M3D, GLTF)
*       - Shaders support, including Model shaders and Postprocessing shaders
*       - Powerful math module for Vector, Matrix and Quaternion operations: [raymath]
*       - Audio loading and playing with streaming support (WAV, OGG, MP3, FLAC, QOA, XM, MOD)
*       - VR stereo rendering with configurable HMD device parameters
*       - Bindings to multiple programming languages available!
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2013-2026 Ramon Santamaria (@raysan5)
*
**********************************************************************************************/

#ifndef RAYLIB_H
#define RAYLIB_H

#include <stdarg.h>     // Required for: va_list - Only used by TraceLogCallback

#define RAYLIB_VERSION_MAJOR 6
#define RAYLIB_VERSION_MINOR 5
#define RAYLIB_VERSION_PATCH 0
#define RAYLIB_VERSION  "6.5-dev"

#if defined(_WIN32)
    #if defined(__TINYC__)
        #define __declspec(x) __attribute__((x))
    #endif
    #if defined(BUILD_LIBTYPE_SHARED)
        #define RLAPI __declspec(dllexport)
    #elif defined(USE_LIBTYPE_SHARED)
        #define RLAPI __declspec(dllimport)
    #endif
#else
    #if defined(BUILD_LIBTYPE_SHARED)
        #define RLAPI __attribute__((visibility("default")))
    #endif
#endif

#ifndef RLAPI
    #define RLAPI
#endif

#ifndef PI
    #define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif

#if defined(__cplusplus)
    #define CLITERAL(type)      type
#else
    #define CLITERAL(type)      (type)
#endif

#if !defined(_MSC_VER) && (defined(__cplusplus) && __cplusplus < 201103L)
    #error "C++11 or later is required. Add -std=c++11"
#endif

#define LIGHTGRAY  CLITERAL(Color){ 200, 200, 200, 255 }
#define GRAY       CLITERAL(Color){ 130, 130, 130, 255 }
#define DARKGRAY   CLITERAL(Color){ 80, 80, 80, 255 }
#define YELLOW     CLITERAL(Color){ 253, 249, 0, 255 }
#define GOLD       CLITERAL(Color){ 255, 203, 0, 255 }
#define ORANGE     CLITERAL(Color){ 255, 161, 0, 255 }
#define PINK       CLITERAL(Color){ 255, 109, 194, 255 }
#define RED        CLITERAL(Color){ 230, 41, 55, 255 }
#define MAROON     CLITERAL(Color){ 190, 33, 55, 255 }
#define GREEN      CLITERAL(Color){ 0, 228, 48, 255 }
#define LIME       CLITERAL(Color){ 0, 158, 47, 255 }
#define DARKGREEN  CLITERAL(Color){ 0, 117, 44, 255 }
#define SKYBLUE    CLITERAL(Color){ 102, 191, 255, 255 }
#define BLUE       CLITERAL(Color){ 0, 121, 241, 255 }
#define DARKBLUE   CLITERAL(Color){ 0, 82, 172, 255 }
#define PURPLE     CLITERAL(Color){ 200, 122, 255, 255 }
#define VIOLET     CLITERAL(Color){ 135, 60, 190, 255 }
#define DARKPURPLE CLITERAL(Color){ 112, 31, 126, 255 }
#define BEIGE      CLITERAL(Color){ 211, 176, 131, 255 }
#define BROWN      CLITERAL(Color){ 127, 106, 79, 255 }
#define DARKBROWN  CLITERAL(Color){ 76, 63, 47, 255 }
#define WHITE      CLITERAL(Color){ 255, 255, 255, 255 }
#define BLACK      CLITERAL(Color){ 0, 0, 0, 255 }
#define BLANK      CLITERAL(Color){ 0, 0, 0, 0 }
#define MAGENTA    CLITERAL(Color){ 255, 0, 255, 255 }
#define RAYWHITE   CLITERAL(Color){ 245, 245, 245, 255 }

typedef struct Vector2 { float x; float y; } Vector2;
typedef struct Vector3 { float x; float y; float z; } Vector3;
typedef struct Vector4 { float x; float y; float z; float w; } Vector4;
typedef Vector4 Quaternion;
typedef struct Matrix { float m0, m4, m8, m12; float m1, m5, m9, m13; float m2, m6, m10, m14; float m3, m7, m11, m15; } Matrix;
typedef struct Color { unsigned char r; unsigned char g; unsigned char b; unsigned char a; } Color;
typedef struct Rectangle { float x; float y; float width; float height; } Rectangle;

#ifdef __cplusplus
extern "C" {
#endif

RLAPI void InitWindow(int width, int height, const char *title);
RLAPI void CloseWindow(void);
RLAPI bool WindowShouldClose(void);
RLAPI void BeginDrawing(void);
RLAPI void EndDrawing(void);
RLAPI void ClearBackground(Color color);
RLAPI void SetTargetFPS(int fps);
RLAPI void DrawText(const char *text, int posX, int posY, int fontSize, Color color);
RLAPI void DrawRectangle(int posX, int posY, int width, int height, Color color);
RLAPI void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
RLAPI bool IsKeyPressed(int key);

#ifdef __cplusplus
}
#endif

#endif // RAYLIB_H