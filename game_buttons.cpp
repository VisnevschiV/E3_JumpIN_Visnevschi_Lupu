#include "game_buttons.h"


void back_button_click(int mouse_X , int mouse_Y, int mat[5][5], int mat_prev[5][5],int step){
   int i,j;
   if(mouse_X > 639 && mouse_X<715){
            if(mouse_Y>300 && mouse_Y<375){
                step --;
                for(i=0;i<6;i++){
                    for(j=0;j<6;j++){
                        if(mat[i][j] != mat_prev[i][j]){
                            mat[i][j] = mat_prev[i][j];
                        }
                    }
                }
            }
    }

}



void back_button_action(int mat_prev[5][5], int mat[5][5]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(mat[i][j] != mat_prev[i][j]){
                if(mat[i][j] != 7){
                    mat_prev[i][j] = mat[i][j];
                }
            }
        }
    }

}



