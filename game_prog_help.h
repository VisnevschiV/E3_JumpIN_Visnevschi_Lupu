#ifndef GAME_PROG_HELP_H_INCLUDED
#define GAME_PROG_HELP_H_INCLUDED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;



void vfox_go(int col, int line, int mat[5][5]);


void ofox_go(int col, int line, int mat[5][5]);


void rab_mov(int col,int line, int mat[5][5]);


void program_moving_help(int mat[5][5],int col_nr, int line_nr);


#endif // GAME_PROG_HELP_H_INCLUDED
