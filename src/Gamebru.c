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
SDL_Window*window; //global variable
//*****Game init function*****
int Game_Init(char* title,int win_width,int win_height, WindowFlag win_flags ){

// =====SDL Init=====
if (SDL_Init(SDL_INIT_EVERYTHING)<0){
    printf("Failed to initialize Gamebru!\n");
    return -1;
}
    
 //===== Window creation=====
 // placing an abstraction on winposition, it's set to undefined on default, users don't need to worry about it
 // placing an abstraction on window flag
	window=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,win_width,win_height,win_flags);
	 if (window == NULL) {
        fprintf(stderr, "Error creating window\n");
        SDL_Quit();
        return -1;
    }
   
	return 0; // return's 0 if initializing and window creation is successful
}// Game init

//*****Game Delay function*****
void Game_Delay(int sec){
	// converts seconds to mili seconds
	int sec2=sec*1000;
	SDL_Delay(sec2);
}

//*****Game Quit function*****
void Game_Quit(){
	SDL_DestroyWindow(window);
	SDL_Quit();
}






















/// test run
int main ( ){
	Game_Init("Title",800,400,Window_Shown);
	Game_Delay(3); // in sec on milli sec !
	Game_Quit();
	return 0;
}