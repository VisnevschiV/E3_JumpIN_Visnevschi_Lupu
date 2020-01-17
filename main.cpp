#include "menu-animations.h"
#include "game-positions.h"
#include "game_prog_help.h"
#include "game_buttons.h"
#include <fstream>


// Menu Variables
    int  i=0,p=0,h=0,m=0,j=0, men =0, smt = 300, limba = 0, tut = 0;
    int x,y;
    bool bgs = true, prez = false, nomusic = false, nosound = false;
    bool game = false;
    bool won = false;


//Game variables
  int level;
  int mat[5][5] = {0};
  int mat_prev[5][5] = {0};
  int the_map[8][5][5];
  int mat_start[5][5];
  bool m1 = false, m2 = false, m3 = false;
  bool r1 = false, r2 = false, r3 = false;
  bool vfox = false, ofox = false, once = true;
  int mouse_X, mouse_Y;
  int help_col, help_line;
  int gob = 0;
  int step =0;
  int holding = 0;
  bool autoplay = false;
  int mission;
  int star;
  int hold_in_mind;
  int AI_timer = 0;
  int prev_mov ,prev_prev_mov;

//Variabile ajutatoare

  int line_nr,col_nr;
  ifstream maps ("maps.txt");


// Game Functions



void help_reset(){

    if(holding == 0){
    for(col_nr=0;col_nr<5;col_nr++){
        for(line_nr=0; line_nr<5;line_nr++){
            if(mat[col_nr][line_nr]==7){
                mat[col_nr][line_nr] = 0;
            }
        }
    }
    }

}

void maps_read(int mat[8][5][5], int n){
    int i,j;
        for(j=0;j<5;j++){
            for(i=0;i<5;i++){
                maps>>mat[n][i][j];
            }
        }



    }

void mat_choose(int n){
if(h>1000){
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            mat[i][j] = the_map[n][i][j];
            mat_start[i][j] = mat[i][j];
        }
    }
game = true;
}
}

void win_check(){

  if(r1 == true){
        if(mat[0][0] == 2 || mat[4][0] == 2 || mat[0][4] == 2 || mat[4][4] == 2 || mat[2][2] == 2){
            if(r2 == true){
                if(mat[0][0] == 3 || mat[4][0] == 3 || mat[0][4] == 3 || mat[4][4] == 3 || mat[2][2] == 3){
                    if(r3 == true){
                        if(mat[0][0] == 4 || mat[4][0] == 4 || mat[0][4] == 4 || mat[4][4] == 4 || mat[2][2] == 4){
                            won = true;
                        }
                    }else{
                        won = true;
                    }
                }
            }else{
                won = true;
            }
        }
    }

}

void vfox_release(int col_nr, int line_nr, int mat[5][5]){
                            if(mat[col_nr][line_nr + 1] == 7){
                                mat[col_nr][line_nr] = 5;
                                mat[col_nr][line_nr + 1] = 5;
                            }else if(mat[col_nr][line_nr - 1] == 7){
                                mat[col_nr][line_nr] = 5;
                                mat[col_nr][line_nr - 1] = 5;
                            }
}

void ofox_release(int col_nr, int line_nr, int mat[5][5]){

                            if(mat[col_nr + 1][line_nr] == 7){
                                mat[col_nr][line_nr] = 6;
                                mat[col_nr + 1][line_nr] = 6;
                            }else if(mat[col_nr - 1][line_nr] == 7){
                                mat[col_nr][line_nr] = 6;
                                mat[col_nr - 1][line_nr] = 6;
                            }

}

void rab_check(int r_past[2],int x, int i , int j){
    int i2,j2,i3,j3;
    bool moved = false;

                hold_in_mind = x;
                rab_mov(i,j,mat);

                for(j2 = 0;j2<5;j2++){
                    for(i2=0;i2<5;i2++){
                        if(mat[i2][j2] == 7){
                            if(i2 == 0 && j2 == 0 && moved == false){
                                mat[i][j] = 0;
                                mat[i2][j2] = hold_in_mind;
                                prev_mov = hold_in_mind;
                                moved = true;

                            }else if (i2 == 4 && j2 == 0 && moved == false){
                                mat[i][j] = 0;
                                mat[i2][j2] = hold_in_mind;
                                prev_mov = hold_in_mind;
                                moved = true;

                            }else if(i2 == 2 && j2 == 2 && moved == false){
                                mat[i][j] = 0;
                                mat[i2][j2] = hold_in_mind;
                                prev_mov = hold_in_mind;
                                moved = true;

                            }else if(i2 == 0 && j2 ==4 && moved == false){
                                mat[i][j] = 0;
                                mat[i2][j2] = hold_in_mind;
                                prev_mov = hold_in_mind;
                                moved = true;
                            }else if(i2 ==4 && j2 ==4 && moved == false){
                                mat[i][j] = 0;
                                mat[i2][j2] = hold_in_mind;
                                prev_mov = hold_in_mind;
                                moved = true;
                            }else{
                            }

                        }
                    }
                }
                if(moved == false){
                                for(j3 = 0; j3<5; j3++){
                                    for(i3 =0; i3<5; i3++){
                                        if(mat[i3][j3] == 7 && moved == false && mat_start[i3][j3] != 2){
                                            mat[i][j] = 0;
                                            mat[i3][j3] = hold_in_mind;
                                            prev_mov = hold_in_mind;
                                            moved = true;
                                        }
                                    }
                                }
                }
                r_past[0] = i;
                r_past[1] = j;
                if(moved == false){
                    mat[i][j] = hold_in_mind;
                }
}

void vfox_check(int i, int j){
    int i2,j2;
    bool neded = false;

        mat[i][j] = mat[i][j+1] = 0;
        vfox_go(i,j,mat);
        for(i2=0;i2<5;i2++){
            if(mat[i][i2] == 7){
                if( mat[i+1][i2] == 2 || mat[i+1][i2] == 3 ||mat[i+1][i2] == 4 || mat[i-1][i2] == 2 || mat[i-1][i2] == 3 ||mat[i-1][i2] == 4){

                    mat[i][i2] = 5;
                    if(mat[i][i2+1] == 7 && i2<4){
                        mat[i][i2-1] = 5;
                        neded = true;

                    }else
                    if(i2>0 ){
                        mat[i][i2-1] = 5;
                        neded = true;
                    }
                }


            }
        }
}


void ofox_check(int i, int j){
    int i2,j2;
        mat[i][j] = mat[i+1][j] = 0;
        ofox_go(i,j,mat);
        for(i2=0;i2<5;i2++){
            if(mat[i2][j] == 7){
                if(mat[i2][j-1] == 2 || mat[i2][j-1] == 3 ||mat[i2][j-1] == 4 || mat[i2][j+1] == 2 || mat[i2][j+1] == 3 ||mat[i2][j+1] == 4){

                    mat[i2][j] = 6;
                    if(mat[i2+1][j] == 7 && i2<4){
                        mat[i2+1][j] = 6;

                    }else
                    if(i2>0 ){
                        mat[i2-1][j] = 6;
                    }
                }
            }
        }

}

void AI(){
    int i,j;
     int r1_past[2], r2_past[2], r3_past[2], vf_past[2], of_past[2];
     hold_in_mind = 0;
     back_button_action(mat_prev,mat);
    for (j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(mat[i][j] == 2 && prev_mov != 2){
                if(mat[i+1][j]>0 || mat[i-1][j]>0 || mat[i][j+1]>0 || mat[i][j-1]>0){
                    rab_check(r1_past, 2, i, j);
                }
            }
        }
    }
    for (j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(mat[i][j] == 3 && prev_mov !=3 && hold_in_mind == 0){
                if(mat[i+1][j]>0 || mat[i-1][j]>0 || mat[i][j+1]>0 || mat[i][j-1]>0){
                    rab_check(r1_past, 3, i, j);
                }
            }
        }
    }
    for (j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(mat[i][j] == 4 && prev_mov !=4 && hold_in_mind == 0){
                if(mat[i+1][j]>0 || mat[i-1][j]>0 || mat[i][j+1]>0 || mat[i][j-1]>0){
                    rab_check(r1_past, 4, i, j);
                }
            }
        }
    }
    for (j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(mat[i][j] == 5 && mat[i][j+1] == 5 && prev_mov != 5 && hold_in_mind == 0){
                prev_mov = 5;
                vfox_check(i,j);
            }
        }
    }
    for (j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(mat[i][j] == 6 && mat[i+1][j] == 6 && prev_mov != 6 && hold_in_mind == 0){
                prev_mov = 6;
                ofox_check(i,j);

            }
        }
    }
    if(prev_mov == prev_prev_mov){
        prev_mov = 0;
        r1_past[0] = r1_past[1] = r2_past[0] = r2_past[1] = r3_past[0] = r3_past[1] = 0;
    }
    prev_prev_mov = prev_mov;

    win_check();

}


int main(int argc, char* argv[])
{


    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("menu",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800,600,0);
    SDL_Renderer* render = SDL_CreateRenderer(window,-1,0);
    SDL_Event e;

    SDL_Texture * land = IMG_LoadTexture(render , "menu-img/bgr.png");

    for(i=0;i<8;i++){
    maps_read(the_map,i);
    }
while(1){
if(game == false){
//Menu sizes
    SDL_Texture * menui = IMG_LoadTexture(render , "menu-img/menu.png");
    SDL_Texture * buttondef1 = IMG_LoadTexture(render , "menu-img/buttondef.png");
    SDL_Texture * buttondef2 = IMG_LoadTexture(render , "menu-img/buttondef.png");
    SDL_Texture * buttondef3 = IMG_LoadTexture(render , "menu-img/buttondef.png");
    SDL_Texture * buttonhov1 = IMG_LoadTexture(render , "menu-img/buttonhov.png");
    SDL_Texture * buttonhov2 = IMG_LoadTexture(render , "menu-img/buttonhov.png");
    SDL_Texture * buttonhov3 = IMG_LoadTexture(render , "menu-img/buttonhov.png");
    SDL_Texture * Playe = IMG_LoadTexture(render , "menu-img/PLAY.png");
    SDL_Texture * Optionse = IMG_LoadTexture(render , "menu-img/OPTIONS.png");
    SDL_Texture * Howtoe = IMG_LoadTexture(render , "menu-img/HOWTO.png");
    SDL_Texture * Playr = IMG_LoadTexture(render , "menu-img/JOACA.png");
    SDL_Texture * Optionsr = IMG_LoadTexture(render , "menu-img/OPTIUNI.png");
    SDL_Texture * Howtor = IMG_LoadTexture(render , "menu-img/REGULI.png");
    SDL_Texture * Playf = IMG_LoadTexture(render , "menu-img/JOUER.png");
    SDL_Texture * Optionsf = IMG_LoadTexture(render , "menu-img/OPTIONS.png");
    SDL_Texture * Howtof = IMG_LoadTexture(render , "menu-img/COMMENT.png");



    SDL_Texture * menui2 = IMG_LoadTexture(render , "menu-img/stage.png");
    SDL_Texture * butn1 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn2 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn3 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn4 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn5 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn6 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn7 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * butn8 = IMG_LoadTexture(render , "menu-img/minbut.png");
    SDL_Texture * buthov = IMG_LoadTexture(render , "menu-img/minbuthov.png");

    SDL_Texture * num1 = IMG_LoadTexture(render , "menu-img/1.png");
    SDL_Texture * num2 = IMG_LoadTexture(render , "menu-img/2.png");
    SDL_Texture * num3 = IMG_LoadTexture(render , "menu-img/3.png");
    SDL_Texture * num4 = IMG_LoadTexture(render , "menu-img/4.png");
    SDL_Texture * num5 = IMG_LoadTexture(render , "menu-img/5.png");
    SDL_Texture * num6 = IMG_LoadTexture(render , "menu-img/6.png");
    SDL_Texture * num7 = IMG_LoadTexture(render , "menu-img/7.png");
    SDL_Texture * num8 = IMG_LoadTexture(render , "menu-img/8.png");


    SDL_Texture * input = IMG_LoadTexture(render , "menu-img/input.png");
    SDL_Texture * music = IMG_LoadTexture(render , "menu-img/music.png");
    SDL_Texture * info = IMG_LoadTexture(render , "menu-img/info.png");
    SDL_Texture * sound = IMG_LoadTexture(render , "menu-img/sound.png");
    SDL_Texture * notmus = IMG_LoadTexture(render , "menu-img/not.png");
    SDL_Texture * notsound = IMG_LoadTexture(render , "menu-img/not.png");
    SDL_Texture * Romana = IMG_LoadTexture(render , "menu-img/Romana.png");
    SDL_Texture * English = IMG_LoadTexture(render , "menu-img/English.png");
    SDL_Texture * French = IMG_LoadTexture(render , "menu-img/French.png");


    SDL_Texture * imtut1 = IMG_LoadTexture(render , "menu-img/Jumpin-1.png");
    SDL_Texture * imtut2 = IMG_LoadTexture(render , "menu-img/Jumpin-2.png");
    SDL_Texture * imtut3 = IMG_LoadTexture(render , "menu-img/Jumpin-3.png");
    SDL_Texture * tut1e = IMG_LoadTexture(render , "menu-img/Step1e.png");
    SDL_Texture * tut1r = IMG_LoadTexture(render , "menu-img/Step1r.png");
    SDL_Texture * tut1f = IMG_LoadTexture(render , "menu-img/Step1f.png");
    SDL_Texture * tut2e = IMG_LoadTexture(render , "menu-img/Step2e.png");
    SDL_Texture * tut2r = IMG_LoadTexture(render , "menu-img/Step2r.png");
    SDL_Texture * tut2f = IMG_LoadTexture(render , "menu-img/Step2f.png");
    SDL_Texture * tut3e = IMG_LoadTexture(render , "menu-img/Step3e.png");
    SDL_Texture * tut3r = IMG_LoadTexture(render , "menu-img/Step3r.png");
    SDL_Texture * tut3f = IMG_LoadTexture(render , "menu-img/Step3f.png");

    SDL_Rect play , howto, options;
    SDL_Rect button1, button2, button3;
    SDL_Rect menu, menu2;
    SDL_Rect backg;
    SDL_Rect but1 , but2 , but3 , but4 , but5 , but6 , but7 , but8;
    SDL_Rect nr1 , nr2 , nr3 , nr4 , nr5 , nr6 , nr7 , nr8;
    SDL_Rect imput;
    SDL_Rect muz , son, inf;
    SDL_Rect notm ,nots;
    SDL_Rect lang;
    SDL_Rect tutimg,tuttxt;


    tuttxt.h = tuttxt.w = 200;
    tuttxt.x = 430;
    tutimg.h = tutimg.w = 270;
    tutimg.x = 130;
    tutimg.y = tuttxt.y = 170;
    muz.w = notm.w = son.w = nots.w =inf.w = 60;
    muz.y = notm.y= son.y = nots.y = inf.y = 280;
    but1.h = but2.h = but3.h = but4.h = but5.h = but6.h = but7.h = but8.h = 100;
    but1.w = but2.w = but3.w = but4.w = but5.w = but6.w = but7.w = but8.w = 100;
    but1.y = but2.y = but3.y = but4.y = 180;
    but5.y = but6.y = but7.y = but8.y = son.x = nots.x =330;
    but1.x = but5.x = 145;
    but2.x = but6.x = 285;
    but3.x = but7.x = 425;
    but4.x = but8.x = 555;
    nr1.h = nr2.h = nr3.h = nr4.h = nr5.h = nr6.h = nr7.h = nr8.h = menu2.x = muz.h = notm.h =50;
    nr1.w = nr2.w = nr3.w = nr4.w = nr5.w = nr6.w = nr7.w = nr8.w = son.h = inf.h = nots.h = 50;
    nr1.y = nr2.y = nr3.y = nr4.y = 210;
    nr5.y = nr6.y = nr7.y = nr8.y = 360;
    nr1.x = nr5.x = 170;
    nr2.x = nr6.x = 310;
    nr3.x = nr7.x = 450;
    nr4.x = nr8.x = 580;
    menu2.h= 550;
    menu2.w= 700;
    menu2.y= 30;
    howto.h = options.h = play.h = 35;
    howto.w = options.w = 180;
    howto.x = options.x = options.y = 310;
    button1.h = button1.w = menu.h  = menu.w = backg.x = backg.y = 0;
    button1.x = menu.x = 400;
    button2.h = button3.h = imput.h = 75;
    button2.x =  button3.x = 275;
    button2.y = button3.y = imput.y = 190;
    button2.w = button3.w = imput.x = imput.w = muz.x = notm.x = 250;
    howto.y = inf.x = 410;
    play.w= 150;
    play.x= 330;
    play.y= 210;
    button1.y = 212;
    menu.y = 300;
    lang.x = 310;
    lang.y = 215;
    lang.h = 25;
    lang.w = 150;
    backg.h=600;
    backg.w=8000;




    won = false;

while(game == false){
    SDL_GetMouseState(  &x,  &y);
    if (SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            SDL_Quit();
        }
    }

    i++;
    growmenu1(i,menu);


    background_stop(i,bgs,p);
    moving(p,backg);
    SDL_RenderClear(render);
    SDL_RenderCopy(render, land,NULL,&backg);
    if(men==0){
        SDL_RenderCopy(render, menui,NULL,&menu);
        //Menu-animatoins
        if(i>600){
            h++;
            buttongrow1(h, button1);
            SDL_RenderCopy(render, buttondef1,NULL,&button1);
            if (h>200){
                m++;
                if(m%2==0){
                    buttongrow2(j, button2,1);
                    buttongrow2(j, button3,2);
                    j++;
                }
                SDL_RenderCopy(render, buttondef2,NULL,&button2);
                SDL_RenderCopy(render, buttondef3,NULL,&button3);
                if(x>275 && x<520){
                    if(y > 175 && y<250){
                        SDL_RenderCopy(render, buttonhov1,NULL,&button1);
                        if(e.type==SDL_MOUSEBUTTONDOWN){
                            men = 1;
                            prez = true;
                            h=0;
                        }
                    }else if (y > 290 && y < 365){
                        SDL_RenderCopy(render, buttonhov2,NULL,&button2);
                        if(e.type==SDL_MOUSEBUTTONDOWN){
                            men = 2;
                            prez = true;
                        }
                    }else if (y > 390 && y < 465){
                        SDL_RenderCopy(render, buttonhov3,NULL,&button3);
                        if(e.type==SDL_MOUSEBUTTONDOWN){
                            men = 3;
                            prez= true;
                        }
                    }
                }
                if(limba == 0){
                    SDL_RenderCopy(render, Playe,NULL,&play);
                    if(j>150){
                        SDL_RenderCopy(render, Optionse,NULL,&options);
                        if(j>200){
                            SDL_RenderCopy(render, Howtoe,NULL,&howto);
                        }
                    }
                }else if(limba == 1){
                    SDL_RenderCopy(render, Playr,NULL,&play);
                    if(j>150){
                        SDL_RenderCopy(render, Optionsr,NULL,&options);
                        if(j>200){
                            SDL_RenderCopy(render, Howtor,NULL,&howto);
                        }
                    }
                }else if (limba == 2){
                    SDL_RenderCopy(render, Playf,NULL,&play);
                    if(j>150){
                        SDL_RenderCopy(render, Optionsf,NULL,&options);
                        if(j>200){
                            SDL_RenderCopy(render, Howtof,NULL,&howto);
                        }
                    }
                }
            }
        }
    }else if(men==1){
        h++;

        SDL_RenderCopy(render, menui2,NULL,&menu2);


        SDL_RenderCopy(render, butn1,NULL,&but1);
        SDL_RenderCopy(render, butn2,NULL,&but2);
        SDL_RenderCopy(render, butn3,NULL,&but3);
        SDL_RenderCopy(render, butn4,NULL,&but4);
        SDL_RenderCopy(render, butn5,NULL,&but5);
        SDL_RenderCopy(render, butn6,NULL,&but6);
        SDL_RenderCopy(render, butn7,NULL,&but7);
        SDL_RenderCopy(render, butn8,NULL,&but8);
        if(y>180 && y <280){
            if(x>145 && x<245){
                SDL_RenderCopy(render, buthov,NULL,&but1);
                if(e.type == SDL_MOUSEBUTTONDOWN){
                mission = 1;
                mat_choose(0);
                }

            }else if(x>285 && x<385){
                SDL_RenderCopy(render, buthov,NULL,&but2);
                if(e.type == SDL_MOUSEBUTTONDOWN){
                mission = 2;
                mat_choose(1);
                }

            }else if(x>425 && x<525){
                SDL_RenderCopy(render, buthov,NULL,&but3);
                if(e.type == SDL_MOUSEBUTTONDOWN){

                        mission = 3;
                        mat_choose(2);


                }
            }else if(x>555 && x<655){
                SDL_RenderCopy(render, buthov,NULL,&but4);
                if(e.type == SDL_MOUSEBUTTONDOWN){
                mission = 4;
                mat_choose(3);}
            }
        }else if(y>330 && y<480){
            if(x>145 && x<245){
                SDL_RenderCopy(render, buthov,NULL,&but5);
                if(e.type == SDL_MOUSEBUTTONDOWN){

                mission = 5;
                mat_choose(4);}
            }else if(x>285 && x<385){
                SDL_RenderCopy(render, buthov,NULL,&but6);
                if(e.type == SDL_MOUSEBUTTONDOWN){
                mission = 6;
                mat_choose(5);}
            }else if(x>425 && x<525){
                SDL_RenderCopy(render, buthov,NULL,&but7);
                if(e.type == SDL_MOUSEBUTTONDOWN){

                mission = 7;
                mat_choose(6);}
            }else if(x>555 && x<655){
                SDL_RenderCopy(render, buthov,NULL,&but8);
                if(e.type == SDL_MOUSEBUTTONDOWN){

                mission = 8;
                mat_choose(7);}
            }
        }
        SDL_RenderCopy(render, num1,NULL,&nr1);
        SDL_RenderCopy(render, num2,NULL,&nr2);
        SDL_RenderCopy(render, num3,NULL,&nr3);
        SDL_RenderCopy(render, num4,NULL,&nr4);
        SDL_RenderCopy(render, num5,NULL,&nr5);
        SDL_RenderCopy(render, num6,NULL,&nr6);
        SDL_RenderCopy(render, num7,NULL,&nr7);
        SDL_RenderCopy(render, num8,NULL,&nr8);
        if(e.type == SDL_MOUSEBUTTONDOWN){
            if(x>675 && x< 750 && y> 30 && y<100){
                men = 0;
            }
        }
    }else if(men == 2){
        SDL_RenderCopy(render, menui,NULL,&menu);



        SDL_RenderCopy(render, input,NULL,&imput);
        SDL_RenderCopy(render, sound,NULL,&son);
        SDL_RenderCopy(render, music,NULL,&muz);
        SDL_RenderCopy(render, info,NULL,&inf);

        if(limba == 0){
            SDL_RenderCopy(render, English,NULL,&lang);
        }else if ( limba == 1){
            SDL_RenderCopy(render, Romana,NULL,&lang);
        }else if ( limba == 2){
            SDL_RenderCopy(render, French,NULL,&lang);
        }

        if(e.type == SDL_MOUSEBUTTONDOWN){
            if(x>565 && x< 635 && y> 60 && y<110){
                men = 0;
            }else if(smt>290){
                if(y>280 && y< 320 ){
                    if(x>250 && x<310){
                        if(nomusic == true){
                            nomusic = false;
                            smt = 0;
                        }else{
                            nomusic = true;
                            smt = 0;
                        }
                    }else if(x>330 && x<390){
                        if(nosound == true){
                            nosound = false;
                            smt = 0;
                        }else{
                            nosound = true;
                            smt = 0;
                        }
                    }
                }else if(x>250 && x< 500 && y>190 && y<265){
                    if(limba == 0){
                        limba = 1;
                        smt = 0;
                    }else if (limba == 1){
                        limba = 2;
                        smt = 0;
                    }else if (limba == 2){
                        limba = 0;
                        smt = 0;
                    }
                }
            }
        }
        if(nomusic == true){
            SDL_RenderCopy(render, notmus,NULL,&notm);
        }
        if(nosound == true){
            SDL_RenderCopy(render, notsound,NULL,&nots);
        }
    }else if(men == 3){
        SDL_RenderCopy(render, menui2,NULL,&menu2);
        if(e.type == SDL_MOUSEBUTTONDOWN){
            if(x>675 && x< 750 && y> 30 && y<100){
                men = 0;
            }
        }
        if(tut == 0){
            SDL_RenderCopy(render, imtut1,NULL,&tutimg);
            if(limba == 0){
                SDL_RenderCopy(render, tut1e,NULL,&tuttxt);
            }else if (limba == 1){
                SDL_RenderCopy(render, tut1r,NULL,&tuttxt);
            }else if (limba == 2){
                SDL_RenderCopy(render, tut1f,NULL,&tuttxt);
            }
            if(e.type ==SDL_MOUSEBUTTONDOWN && smt > 100){
                if(x > 500 && x<610 && y>485 && y<580){
                    tut++;
                    smt = 0;
                }
            }
        }else if (tut == 1){
            SDL_RenderCopy(render, imtut2,NULL,&tutimg);
            if(limba == 0){
                SDL_RenderCopy(render, tut2e,NULL,&tuttxt);
            }else if (limba == 1){
                SDL_RenderCopy(render, tut2r,NULL,&tuttxt);
            }else if (limba == 2){
                SDL_RenderCopy(render, tut2f,NULL,&tuttxt);
            }
            if(e.type ==SDL_MOUSEBUTTONDOWN && smt > 100){
                if(x > 500 && x<610 && y>485 && y<580){
                    tut++;
                    smt = 0;
                }
            }
            if(e.type ==SDL_MOUSEBUTTONDOWN && smt > 100){
                if(x > 180 && x<295 && y>485 && y<580){
                    tut--;
                    smt = 0;
                }
            }
        }else if (tut == 2){
            SDL_RenderCopy(render, imtut3,NULL,&tutimg);
            if(limba == 0){
                SDL_RenderCopy(render, tut3e,NULL,&tuttxt);
            }else if (limba == 1){
                SDL_RenderCopy(render, tut3r,NULL,&tuttxt);
            }else if (limba == 2){
                SDL_RenderCopy(render, tut3f,NULL,&tuttxt);
            }
            if(e.type ==SDL_MOUSEBUTTONDOWN && smt > 100){
                if(x > 180 && x<295  && y>485 && y<580){
                    tut--;
                    smt = 0;
                }
            }
        }
    }
    smt++;
    SDL_ShowCursor(SDL_ENABLE);
    SDL_RenderPresent(render);
    }



}
if(game == true){
    Uint32 prev;
 bool start = true;

    SDL_Texture * wood = IMG_LoadTexture(render , "gameimg/wood.png");

//images for game
    SDL_Texture* curs = IMG_LoadTexture(render, "gameimg/hand.png");
    SDL_Texture* curs1 = IMG_LoadTexture(render, "gameimg/hand1.png");
    SDL_Texture* bg = IMG_LoadTexture(render, "gameimg/bg.png");
    SDL_Texture* ms = IMG_LoadTexture(render, "gameimg/mus.png");
    SDL_Texture* go = IMG_LoadTexture(render, "gameimg/go.png");
    SDL_Texture* gr = IMG_LoadTexture(render, "gameimg/gr.png");
    SDL_Texture* wr = IMG_LoadTexture(render, "gameimg/wr.png");
    SDL_Texture* br = IMG_LoadTexture(render, "gameimg/br.png");
    SDL_Texture* fv = IMG_LoadTexture(render, "gameimg/vfox.png");
    SDL_Texture* fo = IMG_LoadTexture(render, "gameimg/ofox.png");

    //images for the mini-table
    SDL_Texture* timer_folder = IMG_LoadTexture(render, "gameimg/folder.png");
    SDL_Texture* back_button = IMG_LoadTexture(render, "gameimg/back.png");
    SDL_Texture* pause_play = IMG_LoadTexture(render, "gameimg/pause.png");
    SDL_Texture* Home = IMG_LoadTexture(render,"gameimg/home.png");
    SDL_Texture* n0 = IMG_LoadTexture(render, "gameimg/num0.png");
    SDL_Texture* n1 = IMG_LoadTexture(render, "gameimg/num1.png");
    SDL_Texture* n2 = IMG_LoadTexture(render, "gameimg/num2.png");
    SDL_Texture* n3 = IMG_LoadTexture(render, "gameimg/num3.png");
    SDL_Texture* n4 = IMG_LoadTexture(render, "gameimg/num4.png");
    SDL_Texture* n5 = IMG_LoadTexture(render, "gameimg/num5.png");
    SDL_Texture* n6 = IMG_LoadTexture(render, "gameimg/num6.png");
    SDL_Texture* n7 = IMG_LoadTexture(render, "gameimg/num7.png");
    SDL_Texture* n8 = IMG_LoadTexture(render, "gameimg/num8.png");
    SDL_Texture* n9 = IMG_LoadTexture(render, "gameimg/num9.png");


//Winner images

    SDL_Texture* winner = IMG_LoadTexture(render, "gameimg/winner.png");
    SDL_Texture* stars = IMG_LoadTexture(render, "gameimg/star.png");



//game sizes
    SDL_Rect dimbg;
    SDL_Rect cursor;
    SDL_Rect one_blockg , one_blockg1, one_blockg2, one_blockg3, one_blockg4;
    SDL_Rect one_blockm1, one_blockm2, one_blockm3;
    SDL_Rect one_blockr1, one_blockr2, one_blockr3;
    SDL_Rect foxv, foxv1, foxo, foxo1;
    SDL_Rect wodie;
    SDL_Rect win, win_bg;
    SDL_Rect star1 , star2;


//mini-table sizes
    SDL_Rect t_f,b_b,p_p,home;
    SDL_Rect nr1, nr2, nr3, nr11, nr21, nr31;

    nr11.x = 670;
    nr11.w =  nr21.w = nr31.w = 20;
    nr1.h = nr2.h = nr3.h = nr11.h = nr21.h = nr31.h = 60;
    nr1.w = nr2.w = nr3.w = 40;
    nr1.x = nr21.x = 660;
    nr1.y = nr2.y = nr3.y = nr11.y = nr21.y = nr31.y = 120;
    nr2.x = 630;
    nr3.x = nr31.x = 690;
    t_f.w = 200;
    t_f.x = 580;
    t_f.y = t_f.h = 100;
    p_p.w = 150;
    p_p.x = 600;
    p_p.y = 220;
    b_b.h = b_b.w = p_p.h = home.h = home.w = 75;
    b_b.x = home.x = 640;
    b_b.y = 300;
    home.y = 400;

    cursor.h =  cursor.w = 50;
    dimbg.h=500;
    dimbg.w=500;
    dimbg.x=60;
    dimbg.y=75;
    wodie.x = wodie.y = win_bg.x = win_bg.y = 0;
    wodie.h = win_bg.h = 600;
    wodie.w = win_bg.w = 800;
    star1.h = star1.w = star2.h = star2.w =100;
    star1.x = 302;
    star1.y = 150;
    star2.x = 392;
    star2.y = 192;

    one_blockg.h = one_blockg.w = one_blockg1.h = one_blockg1.w = 70;
    one_blockg2.h = one_blockg2.w = one_blockg3.h = one_blockg3.w = one_blockg4.h = one_blockg4.w = 70;
    one_blockm1.h = one_blockm1.w = one_blockm2.h = one_blockm2.w = one_blockm3.h = one_blockm3.w = 70;
    one_blockr1.h = one_blockr1.w = one_blockr2.h = one_blockr2.w = one_blockr3.h = one_blockr3.w = 70;
    foxv.w = foxv1.w = foxo.h = foxo.h = 70;
    foxv.h = foxv1.h = foxo.w = foxo.w = 140;


    win.h = 600;
    win.w = 400;
    win.x = 150;
    win.y = 0;



    while(game == true){

    if (SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            SDL_Quit();
        }
    }

    SDL_ShowCursor(SDL_DISABLE);
    hold(cursor);


    if(won == true){

            if(mission == 1){
                if(step < 3){
                    star = 3;
                }else if (step<5){
                    star = 2;
                }else{star = 1;}
            }
            if(mission == 2){
                if(step == 3){
                    star = 3;
                }else if(step<5){
                    star = 2;
                }else{
                    star = 1;
                }
            }
            if(mission == 3){
                if(step == 4){
                    star = 3;
                }else if(step<7){
                    star = 2;
                }else{
                    star = 1;
                }
            }
            if(mission == 4){
                if(step < 5){
                    star = 3;
                }else if(step < 7){
                    star = 2;
                }else{
                    star = 1;
                }
            }
            if(mission == 5){
                if(step  < 5){
                    star = 3;
                }else if(step < 98){
                    star = 2;
                }else{
                    star = 1;
                }
            }
            if(mission == 6){
                if(step == 8){
                    star = 3;
                }else if(step<12){
                    star = 2;
                }else{
                    star = 1;
                }
            }
            if(mission == 7){
                if(step == 6){
                    star = 3;
                }else if(step<9){
                    star = 2;
                }else{
                    star = 1;
                }
            }
            if(mission == 8){
                star = 3;
            }

        step = 0;
        }

    if(e.type==SDL_MOUSEBUTTONDOWN && prev!=SDL_MOUSEBUTTONDOWN){
        SDL_GetMouseState(&mouse_X,&mouse_Y);
        once = true;

        back_button_click(mouse_X,mouse_Y,mat,mat_prev,step);

        if(mouse_Y > 200 & mouse_Y<295){
            if(mouse_X> 610 && mouse_X <670){
                autoplay = true;
            }
            if(mouse_X> 680 && mouse_X < 750){
                autoplay = false;
            }
        }

        if(mouse_X>640 && mouse_Y<715){
            if(mouse_Y>400 && mouse_Y<480){
                game = false;

            }
        }


    if(autoplay == false){
        if(won == true){

            if(mouse_Y > 420 && mouse_Y < 480){
                if(mouse_X > 225 && mouse_X<340){
                    won = false;
                    game = false;
                }
                if(mouse_X > 365 && mouse_X<485){
                    won = false;
                    for(i=0;i<5;i++){
                        for(j=0;j<5;j++){
                            mat[i][j] = mat_start[i][j];
                        }
                    }

                }
            }

        }else{
        for(col_nr=0;col_nr<5;col_nr++){
            if(mouse_X>get_col_nr(col_nr) && mouse_X<get_col_nr(col_nr+1)){
                for(line_nr=0; line_nr<5;line_nr++){
                    if(mouse_Y>get_line_nr(line_nr) && mouse_Y<get_line_nr(line_nr+1)){




                        if(holding == 0){

                            back_button_action(mat_prev,mat);


                            if(mat[col_nr][line_nr]>1){

                                holding = mat[col_nr][line_nr];


                                program_moving_help(mat, col_nr, line_nr);


                            }
                        }else if (holding == 5){
                            step ++;
                            vfox_release(col_nr,line_nr,mat);
                            holding = 0;
                        }else if (holding == 6){
                            step++;
                            holding = 0;
                            ofox_release(col_nr,line_nr,mat);




                        }else if(holding>1 && holding<5){
                            step++;
                            if(mat[col_nr][line_nr] == 7){
                                mat[col_nr][line_nr] = holding;
                                holding = 0;
                            }

                        }

                    }
                }
            }
        }
    }
    }}
    if(autoplay == true && won == false){
        if(AI_timer>1000){
            AI();
            AI_timer = 0;
        }else{AI_timer ++;}

    }
    if(won == true){
        autoplay = false;
    }


    if(holding == 2){
        hold(one_blockr1);
        r1 = true;
    }else if(holding == 3){
        hold(one_blockr2);
        r2 = true;
    }else if(holding == 4){
        hold(one_blockr3);
        r3 = true;
    }else if(holding == 5){
        hold_v_fox(foxv);
        vfox = true;
    }else if(holding == 6){
        hold_o_fox(foxo);
        ofox = true;

    }

    for(col_nr=0;col_nr<5;col_nr++){
                        if(once == true){cout<<endl;}
        for(line_nr=0; line_nr<5;line_nr++){
                        if(once == true){cout<<mat[line_nr][col_nr]<<" ";}
            switch(mat[col_nr][line_nr]){

                case 1:
                    if(m1 == false){
                        position(col_nr,line_nr,one_blockm1);
                        m1 = true;
                    }else if (m2 == false ){
                        position(col_nr,line_nr,one_blockm2);
                        m2 = true;
                    }else{
                        position(col_nr,line_nr,one_blockm3);
                        m3 = true;
                    }
                break;


                case 2:
                    position(col_nr,line_nr,one_blockr1);
                    r1 = true;
                break;

                case 3:
                    position(col_nr,line_nr,one_blockr2);
                    r2 = true;
                break;

                case 4:
                    position(col_nr,line_nr,one_blockr3);
                    r3 = true;
                break;

                case 5:
                    if(mat[col_nr][line_nr - 1] != 5 && mat[col_nr][line_nr + 1] == 5){
                        position(col_nr,line_nr,foxv);
                        vfox = true;
                    }
                break;

                case 6:
                    if(mat[col_nr - 1][line_nr] != 6 && mat[col_nr + 1][line_nr] == 6){
                        position(col_nr,line_nr,foxo);
                        ofox = true;

                    }
                break;

                case 7:
                    switch(gob){
                    case 0:
                        position(col_nr,line_nr,one_blockg);
                        gob=1;
                    break;

                    case 1:
                        position(col_nr,line_nr,one_blockg1);
                        gob=2;
                    break;

                    case 2:
                        position(col_nr,line_nr,one_blockg2);
                        gob=3;
                    break;

                    case 3:
                        position(col_nr,line_nr,one_blockg3);
                        gob=4;
                    break;

                    case 4:
                        position(col_nr,line_nr,one_blockg4);
                        gob=5;
                    break;
                    }
                break;
            }
        }
    }

    win_check();

    SDL_RenderClear(render);
    SDL_RenderCopy(render,wood,NULL,&wodie);
    SDL_RenderCopy(render, bg,NULL,&dimbg);


    if(m1 == true){
        SDL_RenderCopy(render, ms,NULL,&one_blockm1);
    }
    if(m2 == true){
        SDL_RenderCopy(render, ms,NULL,&one_blockm2);
    }
    if(m3 == true){
        SDL_RenderCopy(render, ms,NULL,&one_blockm3);
    }
    if(r1 == true){
        SDL_RenderCopy(render, gr,NULL,&one_blockr1);
    }
    if(r2 == true){
        SDL_RenderCopy(render, wr,NULL,&one_blockr2);
    }
    if(r3 == true){
        SDL_RenderCopy(render, br,NULL,&one_blockr3);
    }
    if(ofox == true){
        SDL_RenderCopy(render, fo,NULL,&foxo);

    }
    if(vfox == true){
        SDL_RenderCopy(render, fv,NULL,&foxv);
    }
    if(gob >0 ){
        SDL_RenderCopy(render, go,NULL,&one_blockg);
    }
    if(gob >1){
        SDL_RenderCopy(render, go,NULL,&one_blockg1);
    }
    if(gob >2){
        SDL_RenderCopy(render, go,NULL,&one_blockg2);
    }
    if(gob >3){
        SDL_RenderCopy(render, go,NULL,&one_blockg3);
    }
    if(gob > 4){
        SDL_RenderCopy(render, go,NULL,&one_blockg4);
    }
// mini-table


    SDL_RenderCopy(render, timer_folder,NULL,&t_f);
    SDL_RenderCopy(render, pause_play,NULL,&p_p);
    SDL_RenderCopy(render, back_button,NULL,&b_b);
    SDL_RenderCopy(render, Home,NULL,&home);
    if(step<10){
        switch(step){
            case 0:
                SDL_RenderCopy(render, n0,NULL,&nr1);
            break;

            case 1:
                SDL_RenderCopy(render, n1,NULL,&nr11);
            break;

            case 2:
                SDL_RenderCopy(render, n2,NULL,&nr1);
            break;

            case 3:
                SDL_RenderCopy(render, n3,NULL,&nr1);
            break;

            case 4:
                SDL_RenderCopy(render, n4,NULL,&nr1);
            break;

            case 5:
                SDL_RenderCopy(render, n5,NULL,&nr1);
            break;

            case 6:
                SDL_RenderCopy(render, n6,NULL,&nr1);
            break;

            case 7:
                SDL_RenderCopy(render, n7,NULL,&nr1);
            break;

            case 8:
                SDL_RenderCopy(render, n8,NULL,&nr1);
            break;

            case 9:
                SDL_RenderCopy(render, n9,NULL,&nr1);
            break;
        }
    }else if(step<20){
            SDL_RenderCopy(render, n1,NULL,&nr21);
            switch(step%10){

            case 0:
                SDL_RenderCopy(render, n0,NULL,&nr3);
            break;

            case 1:
                SDL_RenderCopy(render, n1,NULL,&nr31);
            break;

            case 2:
                SDL_RenderCopy(render, n2,NULL,&nr3);
            break;

            case 3:
                SDL_RenderCopy(render, n3,NULL,&nr3);
            break;

            case 4:
                SDL_RenderCopy(render, n4,NULL,&nr3);
            break;

            case 5:
                SDL_RenderCopy(render, n5,NULL,&nr3);
            break;

            case 6:
                SDL_RenderCopy(render, n6,NULL,&nr3);
            break;

            case 7:
                SDL_RenderCopy(render, n7,NULL,&nr3);
            break;

            case 8:
                SDL_RenderCopy(render, n8,NULL,&nr3);
            break;

            case 9:
                SDL_RenderCopy(render, n9,NULL,&nr3);
            break;

            }
    }else if (step<30){
            SDL_RenderCopy(render, n2,NULL,&nr2);
            switch(step%10){

            case 0:
                SDL_RenderCopy(render, n0,NULL,&nr3);
            break;

            case 1:
                SDL_RenderCopy(render, n1,NULL,&nr31);
            break;

            case 2:
                SDL_RenderCopy(render, n2,NULL,&nr3);
            break;

            case 3:
                SDL_RenderCopy(render, n3,NULL,&nr3);
            break;

            case 4:
                SDL_RenderCopy(render, n4,NULL,&nr3);
            break;

            case 5:
                SDL_RenderCopy(render, n5,NULL,&nr3);
            break;

            case 6:
                SDL_RenderCopy(render, n6,NULL,&nr3);
            break;

            case 7:
                SDL_RenderCopy(render, n7,NULL,&nr3);
            break;

            case 8:
                SDL_RenderCopy(render, n8,NULL,&nr3);
            break;

            case 9:
                SDL_RenderCopy(render, n9,NULL,&nr3);
            break;

            }
    }


    if(won == true){
        SDL_RenderCopy(render, go ,NULL, &win_bg);
        SDL_RenderCopy(render, winner,NULL, &win);
        if(star > 1){
            SDL_RenderCopy(render, stars,NULL, &star1);
        }
        if(star == 3){
            SDL_RenderCopy(render, stars,NULL, &star2);
        }
    }

//cursor
    if(holding==0){
        SDL_RenderCopy(render, curs,NULL,&cursor);
    }else{
        SDL_RenderCopy(render, curs1,NULL,&cursor);
    }
    if(once == true){
        cout<<endl;
    }



    SDL_RenderPresent(render);

    help_reset();


    prev= e.type;
    m1 = m2 = m3 = false;
    r1 = r2 = r3 = false;
    ofox = vfox = once =false;
    gob = 0;
    }



}
}}


