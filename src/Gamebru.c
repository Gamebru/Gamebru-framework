#include<stdio.h>
#include "../include/Gamebru.h"


int Bru_Init(char title,char win_posX, char win_posY, char win_resolutionX, char win_resolutionY, char window_flag ){
if (SDL_Init(SDL_INIT_EVERYTHING)<0){		printf("Failed to initialize Gamebru!\n");
    return -1;
}
	SDL_Window*window=(title, win_posX, win_posY,win_resolutionX,win_resolutionY,window_flag)
	 if (window == NULL) {
        fprintf(stderr, "Error creating window\n");
        SDL_Quit();
        return -1;
    }
	return 0;
}