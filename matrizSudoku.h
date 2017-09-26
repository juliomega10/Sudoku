//
// Created by Julio de Souza on 26/09/2017.
//

#ifndef _H_MATRIZ_SUDOKU_H
#define _H_MATRIZ_SUDOKU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

    unsigned char nrCelulas;

    unsigned char G[10][10];

}Sudoku;


//interfaces
void mostrarMatriz(Sudoku *);
void lerMatriz(Sudoku *);


void mostrarMatriz(Sudoku * p_sudoku){

}

void lerMatriz( Sudoku * p_sudoku ){

    unsigned char linha[10];
    size_t lin, i, n = 10;

    lin = 0;

    FILE * entrada = fopen("/temp/sudoku.txt", "r");

    if(entrada == NULL){
        fprintf(stderr,"Error: Nao foi encontrado o arquivo sudoku.txt na pasta temp");
        exit(-1);
    }else {
        while (fscanf(entrada, "%10s", linha) == 1) {

            n = strlen((char *) linha);
            lin = lin + 1;

            for (i = 1; i <= n; i++) {
                p_sudoku->G[lin][i] = linha[i];
            }

        }

        fclose(entrada);
    }
}



#endif //SUDOKUED1_MATRIZSUDOKU_H_H
