#include "menu-animations.h"


void moving(int s,  SDL_Rect &pos){
    pos.x = -s;
}



void growmenu1(int s ,SDL_Rect &pos){
    if(s%2 == 0){
        if(pos.x>181){
            pos.x = pos.x - 1;
        }
        if(pos.y>50){
            pos.y = pos.y-1;
        }
    }
    if(pos.w<450){
        pos.w = pos.w +1;
    }
    if(pos.h<500){
        pos.h = pos.h+1;
    }
}



void buttongrow1(int s, SDL_Rect &pos){
if(s%2 == 0){
    if(pos.x>275){
        pos.x = pos.x - 1;
        }
    if(pos.y>190){
        pos.y = pos.y-1;
    }
}
    if(pos.w<250){
        pos.w = pos.w +1;
    }
    if(pos.h<75){
        pos.h = pos.h+1;
    }
}


void buttongrow2(int s, SDL_Rect &pos, int x){
    if(s<x*100){
        pos.y= pos.y + 1;
    }
}



void background_stop(int i, bool bgs, int &p){
    if(i%50 == 0){
        if(bgs == true){
            if(p < 7200){
                p++;
            }else{
                p--;
                bgs = false;
            }
        }else{
            if(p>1){
                p--;
            }else{
                p++;
                bgs = true;
            }
        }
    }

}
