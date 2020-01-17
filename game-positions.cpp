#include "game-positions.h"


void hold (SDL_Rect &get){
   int a,b;
   SDL_GetMouseState(&a,&b);
   get.x = a - get.w/2;
   get.y = b - get.h/2;
}
void hold_v_fox(SDL_Rect &get){
   int a,b;
   SDL_GetMouseState(&a,&b);
   get.x = a - get.w/2;
   get.y = b - get.h/2.5;

}
void hold_o_fox(SDL_Rect &get){
   int a,b;
   SDL_GetMouseState(&a,&b);
   get.x = a - get.w/2.5;
   get.y = b - get.h/2;

}


void position (int line, int col, SDL_Rect &pos){
   pos.x=line*86 + 105;
   pos.y=col*86 + 115;
}



int get_col_nr (int col){
   col = col*86 +75;
   return col;
}



int get_line_nr (int line){
   line=line*86 + 125;
   return line;
}
