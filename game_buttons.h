#ifndef GAME_BUTTONS_H_INCLUDED
#define GAME_BUTTONS_H_INCLUDED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;


void back_button_click(int mouse_X , int mouse_Y, int mat[5][5], int mat_prev[5][5],int step);


void back_button_action(int mat_prev[5][5], int mat[5][5]);


void auto_play_click(int mouse_X, int mouse_Y, bool autoplay);



#endif // GAME_BUTTONS_H_INCLUDED
