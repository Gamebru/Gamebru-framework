#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<Gamebru.h>
SDL_Window*window; //global variable
//*****Game init function*****
int Game_Init(char* title,int win_width,int win_height, int win_flag ){

// =====SDL Init=====
if (SDL_Init(SDL_INIT_EVERYTHING)<0){
    printf("Failed to initialize Gamebru!\n");
    return -1;
}
    
 //===== Window creation=====
 // placing an abstraction on winposition, it's set to undefined on default, users don't need to worry about it
	window=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,win_width,win_height,win_flag);
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
	Game_Init("happy window",800,400,SDL_WINDOW_SHOWN);
	Game_Delay(3); // in sec on milli sec !
	Game_Quit();
	return 0;
}