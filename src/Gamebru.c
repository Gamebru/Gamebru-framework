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

//renderer flags aliases
typedef enum {
    Renderer_Software = SDL_RENDERER_SOFTWARE,
    Renderer_Accelerated = SDL_RENDERER_ACCELERATED,
    Renderer_PresentVsync = SDL_RENDERER_PRESENTVSYNC,
    Renderer_TargetTexture = SDL_RENDERER_TARGETTEXTURE
} RendererFlags;
//-----Global variables
// btw i Enclosed all global variables names with underscore to prevent conflict if someone try's to use those names unknowningly 
SDL_Window*_window_;
SDL_Renderer*_renderer_;
SDL_Texture*_texture_;
int _Red_=1, _Blue_=2, _Green_=3, _Yellow_=4,_Black_=5,_White_=6,_Orange_=7,_Purple_=8,_Pink_=9,_Brown_=10,_Cyan_=11,_Magenta_=12,_Gold_=13,_Silver_=14,_Violet_=15;
//*****Game init function*****
int Game_Init(char* title,int win_width,int win_height, WindowFlag win_flags, RendererFlags renderer_flag ){

// =====SDL Init=====
SDL_Init(SDL_INIT_EVERYTHING);
    
 //===== Window creation=====
 // placing an abstraction on winposition, it's set to undefined on default, users don't need to worry about it
 // placing an abstraction on window flag
	_window_=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,win_width,win_height,(Uint32)win_flags);
	_renderer_ = SDL_CreateRenderer(_window_, -1, (Uint32)renderer_flag);
	return 0; // return's 0 if initializing, rendering and window creation is successful
}// Game init

void Game_Delay(float sec){
    // converts seconds to milliseconds
    // so users can easily type 3 instead of 3000 and can type 0.003 if they wan'ts it in milli
    int msec = (int)(sec * 1000);
    SDL_Delay(msec);
}

//*****Game Quit function*****
void Game_Quit(){
	SDL_DestroyTexture(_texture_);
	SDL_DestroyRenderer(_renderer_);
	SDL_DestroyWindow(_window_);
	SDL_Quit();
}
//===== set render color=====
// i limited it from RGBA to just RGB besides nobody really cares about alpha so i set the value to 255 on default
void Set_Color_RGBA(int R, int G, int B, int A){
	SDL_SetRenderDrawColor(_renderer_, R, G, B, A);
}
void Set_Color(int Color_name){
	switch (Color_name){// Check line 42 on this file to see all color numbering
		case 1:	SDL_SetRenderDrawColor(_renderer_, 255, 0, 0, 255); //red
		break;
		case 2:	SDL_SetRenderDrawColor(_renderer_, 255, 0, 0, 255);//blue
		break;
		case 3:	SDL_SetRenderDrawColor(_renderer_, 255, 0, 0, 255);//Green
		break;
	}
}
// Draw shapes
typedef struct{
	int x;
	int y;
	int w;
	int h;
}Rect;

Rect Draw_Rectangle (int x, int y, int w, int h){
	Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	return rect;
}
// Fill color
void Color_Fill (const SDL_Rect *rect){
    SDL_RenderFillRect(_renderer_, rect);
}
void Refresh(){
	SDL_RenderPresent(_renderer_);
}





/// test run
int main ( ){
	Game_Init("Title",800,400,Window_Shown,Renderer_Accelerated);
	Rect shape = Draw_Rectangle(100, 100, 200, 150);
	Set_Color(_Red_);
    Color_Fill(&shape);
	Refresh ( );
	Game_Delay(70); // in sec on milli sec !
	Game_Quit();
	return 0;
}