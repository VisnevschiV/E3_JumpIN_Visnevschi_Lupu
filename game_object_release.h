#ifndef GAME_OBJECT_RELEASE_H_INCLUDED
#define GAME_OBJECT_RELEASE_H_INCLUDED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;


void vertical_fox_release(int mat[5][5], int holding, int col_nr,int line_nr);


void orizontal_fox_release(int mat[5][5], int holding, int col_nr,int line_nr);


void rabbit_release(int mat[5][5], int holding, int col_nr,int line_nr);


#endif // GAME_OBJECT_RELEASE_H_INCLUDED
