#include "game_prog_help.h"


void vfox_go(int col, int line, int mat[5][5]){
    int f= line;
    int h= line;
    f--;
    h++;
    while(mat[col][f] == 0 && f>-1){
        mat[col][f] = 7;
        f--;
    }
    while(mat[col][h] == 0 && h<5){
        mat[col][h] = 7;
        h++;
    }
    mat[col][line] = 7;
}



void ofox_go(int col, int line, int mat[5][5]){
    int f= col;
    int h= col;

    f--;
    h++;
    while(mat[f][line] == 0 && f>-1){
        mat[f][line] = 7;
        f--;
    }
    while(mat[h][line] == 0 && h<5){
        mat[h][line] = 7;
        h++;
    }
    mat[col][line] = 7;
}



void rab_mov(int col,int line, int mat[5][5]){
    int t=line;
    int b=line;
    int l=col;
    int r=col;
    do{
        t--;
    }while(mat[col][t]>0);
    if(t>-1 && t<line-1){
        mat[col][t] = 7;
    }
    do{
        b++;
    }while(mat[col][b]>0);
    if(b<5 && b>line+1){
        mat[col][b] = 7;
    }
    do{
        l--;
    }while(mat[l][line]>0);
    if(l>-1 && l<col-1){
        mat[l][line] = 7;
    }
    do{
        r++;
    }while(mat[r][line]>0);
    if(r<5 && r>col+1){
        mat[r][line] = 7;
    }

}



void program_moving_help(int mat[5][5],int col_nr, int line_nr){

    if(mat[col_nr][line_nr] >1 && mat[col_nr][line_nr] < 5){
        rab_mov(col_nr,line_nr, mat);
        mat[col_nr][line_nr]=7;
    }else if (mat[col_nr][line_nr] == 6){
        if(mat[col_nr + 1][line_nr] ==6){
            mat[col_nr + 1][line_nr] = 0;
        }else if(mat[col_nr -1][line_nr] ==6){
            mat[col_nr - 1][line_nr] = 0;
        }
        ofox_go(col_nr,line_nr, mat);
    }else if(mat[col_nr][line_nr] == 5){
        if(mat[col_nr ][line_nr + 1] == 5){
            mat[col_nr ][line_nr + 1] = 0;
        }else if( mat[col_nr ][line_nr - 1] == 5){
            mat[col_nr ][line_nr - 1] = 0;
        }
            vfox_go(col_nr,line_nr, mat);
    }else{
        mat[col_nr][line_nr] = 0;
    }

}
