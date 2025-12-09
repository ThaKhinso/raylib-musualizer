#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
//#if defined(PLATFORM_WEB)
//    #include <emscripten/emscripten.h>
//#endif


//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
static void sample(void) {

};

//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib game template");
    SetTargetFPS(60);
    SetExitKey(KEY_F3);

    InitAudioDevice();
    Music music = LoadMusicStream("ai_kotoba4.mp3");
    PlayMusicStream(music);
    
//#if defined(PLATFORM_WEB)
//    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
//#else
    
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyPressed(KEY_SPACE)) {
            if (IsMusicStreamPlaying(music))
            {
                PauseMusicStream(music);
            }
            else {
                ResumeMusicStream(music);
            }
        }
        UpdateMusicStream(music);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
//#endif
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
