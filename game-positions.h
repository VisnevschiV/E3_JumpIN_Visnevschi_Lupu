#ifndef GAME-POSITIONS_H_INCLUDED
#define GAME-POSITIONS_H_INCLUDED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;



void hold (SDL_Rect &get);

void hold_v_fox(SDL_Rect &get);

void hold_o_fox(SDL_Rect &get);


void position (int line, int col, SDL_Rect &pos);



int get_col_nr (int col);



int get_line_nr (int line);


#endif // GAME-POSITIONS_H_INCLUDED
