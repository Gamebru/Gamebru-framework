#ifndef GAMEBRU_H
#define GAMEBRU_H

#include <SDL2/SDL.h>

// Define abstracted window flags
typedef enum {
    Window_Fullscreen = SDL_WINDOW_FULLSCREEN,
    Window_Fullscreen_Desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    Window_OpenGL = SDL_WINDOW_OPENGL,
    Window_Shown = SDL_WINDOW_SHOWN,
    Window_Hidden = SDL_WINDOW_HIDDEN,
    Window_Borderless = SDL_WINDOW_BORDERLESS,
    Window_Resizable = SDL_WINDOW_RESIZABLE,
    Window_Minimized = SDL_WINDOW_MINIMIZED,
    Window_Maximized = SDL_WINDOW_MAXIMIZED,
    Window_Input_Grabbed = SDL_WINDOW_INPUT_GRABBED,
    Window_Input_Focus = SDL_WINDOW_INPUT_FOCUS,
    Window_Mouse_Focus = SDL_WINDOW_MOUSE_FOCUS,
    Window_Foreign = SDL_WINDOW_FOREIGN,
    Window_Allow_HighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
    Window_Mouse_Capture = SDL_WINDOW_MOUSE_CAPTURE,
    Window_Always_On_Top = SDL_WINDOW_ALWAYS_ON_TOP,
    Window_Skip_Taskbar = SDL_WINDOW_SKIP_TASKBAR,
    Window_Utility = SDL_WINDOW_UTILITY,
    Window_Tooltip = SDL_WINDOW_TOOLTIP,
    Window_Popup_Menu = SDL_WINDOW_POPUP_MENU,
} WindowFlag;

//renderer flags aliases
typedef enum {
    Renderer_Software = SDL_RENDERER_SOFTWARE,
    Renderer_Accelerated = SDL_RENDERER_ACCELERATED,
    Renderer_PresentVsync = SDL_RENDERER_PRESENTVSYNC,
    Renderer_TargetTexture = SDL_RENDERER_TARGETTEXTURE
} RendererFlags;


// Function declarations
int Game_Init(char* title, int win_width, int win_height, WindowFlag win_flags, RendererFlags renderer_flag );
void Game_Delay(float sec);
void Game_Quit();

#endif /* GAMEBRU_H */