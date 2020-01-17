#ifndef MENU-ANIMATIONS_H_INCLUDED
#define MENU-ANIMATIONS_H_INCLUDED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;



void moving(int s,  SDL_Rect &pos);




void growmenu1(int s ,SDL_Rect &pos);




void buttongrow1(int s, SDL_Rect &pos);




void buttongrow2(int s, SDL_Rect &pos, int x);



void background_stop(int i, bool bgs, int &p);



#endif // MENU-ANIMATIONS_H_INCLUDED
