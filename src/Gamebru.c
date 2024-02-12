#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<SDL2/SDL.h> 
// Define abstracted window flags
typedef enum {
    Window_Fullscreen=SDL_WINDOW_FULLSCREEN,
    Window_Fullscreen_Desktop=SDL_WINDOW_FULLSCREEN_DESKTOP,
    Window_OpenGL=SDL_WINDOW_OPENGL,
    Window_Shown=SDL_WINDOW_SHOWN,
    Window_Hidden=SDL_WINDOW_HIDDEN,
    Window_Borderless=SDL_WINDOW_BORDERLESS,
    Window_Resizable=SDL_WINDOW_RESIZABLE,
    Window_Minimized=SDL_WINDOW_MINIMIZED,
    Window_Maximized=SDL_WINDOW_MAXIMIZED,
    Window_Input_Grabbed=SDL_WINDOW_INPUT_GRABBED,
    Window_Input_Focus=SDL_WINDOW_INPUT_FOCUS,
    Window_Mouse_Focus=SDL_WINDOW_MOUSE_FOCUS,
    Window_Foreign=SDL_WINDOW_FOREIGN,
    Window_Allow_HighDPI=SDL_WINDOW_ALLOW_HIGHDPI,
    Window_Mouse_Capture=SDL_WINDOW_MOUSE_CAPTURE,
    Window_Always_On_Top=SDL_WINDOW_ALWAYS_ON_TOP,
    Window_Skip_Taskbar=SDL_WINDOW_SKIP_TASKBAR,
    Window_Utility=SDL_WINDOW_UTILITY,
    Window_Tooltip=SDL_WINDOW_TOOLTIP,
    Window_Popup_Menu=SDL_WINDOW_POPUP_MENU,
} WindowFlag;
//-----Global variables
SDL_Window*window;
SDL_Renderer*renderer;
//*****Game init function*****
int Game_Init(char* title,int win_width,int win_height, WindowFlag win_flags ){

// =====SDL Init=====
SDL_Init(SDL_INIT_EVERYTHING);
    
 //===== Window creation=====
 // placing an abstraction on winposition, it's set to undefined on default, users don't need to worry about it
 // placing an abstraction on window flag
	window=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,win_width,win_height,(Uint32)win_flags);
	return 0; // return's 0 if initializing and window creation is successful
}// Game init

void Game_Delay(float sec){
    // converts seconds to milliseconds
    // so users can easily type 3 instead of 3000 and can type 0.003 if they wan'ts it in milli
    int msec = (int)(sec * 1000);
    SDL_Delay(msec);
}

//*****Game Quit function*****
void Game_Quit(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
typedef enum {
    Renderer_Software = SDL_RENDERER_SOFTWARE,
    Renderer_Accelerated = SDL_RENDERER_ACCELERATED,
    Renderer_PresentVsync = SDL_RENDERER_PRESENTVSYNC,
    Renderer_TargetTexture = SDL_RENDERER_TARGETTEXTURE
} RendererFlags;

int Gfx_settings(RendererFlags renderer_flag){
    renderer = SDL_CreateRenderer(window, -1, (Uint32)renderer_flag);
    return 0;
}
















/// test run
int main ( ){
	Game_Init("Title",800,400,Window_Shown);
	Gfx_settings( Renderer_Accelerated);
	Game_Delay(0.3); // in sec on milli sec !
	Game_Quit();
	return 0;
}