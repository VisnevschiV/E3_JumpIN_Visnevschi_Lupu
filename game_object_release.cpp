

#include "game_object_release.h"


void vertical_fox_release(int mat[5][5], int holding, int col_nr,int line_nr){

}
void orizontal_fox_release(int mat[5][5], int holding, int col_nr,int line_nr){

    if(mat[col_nr + 1][line_nr] == 7){
        mat[col_nr][line_nr] = 6;
        mat[col_nr + 1][line_nr] = 6;
        holding = 0;
    }else if(mat[col_nr - 1][line_nr] == 7){
        mat[col_nr][line_nr] = 6;
        mat[col_nr - 1][line_nr] = 6;
        holding = 0;
    }

}

void rabbit_release(int mat[5][5], int holding, int col_nr,int line_nr){

    if(mat[col_nr][line_nr] == 7){
        mat[col_nr][line_nr] = holding;
        holding = 0;
    }

}
