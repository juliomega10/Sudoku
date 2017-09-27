//
// Created by Julio de Souza on 26/09/2017.
//

#ifndef _H_MATRIZ_SUDOKU_H
#define _H_MATRIZ_SUDOKU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//estrutura
typedef struct {

        unsigned char nrCelulas;

        unsigned char G[10][10];

}Sudoku;


//interfaces
void mostrarMatriz(Sudoku *);
void lerMatriz(Sudoku *);

//TODO: Implementar algo mais elegante
void mostrarMatriz(Sudoku * p_sudoku){

        int linha, coluna;

        printf ("\n");
        for (linha = 1; linha <= 9; linha++) {
                for (coluna = 1; coluna <= 9; coluna++) {
                        printf (" %c ", p_sudoku->G[linha][coluna]);
                }
                printf("\n\n");
        }
        printf ("\n");

}

void lerMatriz( Sudoku * p_sudoku ){

        unsigned char stringLinha[10];

        size_t linha, i, length;

        FILE * entrada = fopen("/tmp/sudoku.txt", "r");

        if(entrada == NULL) {
                fprintf(stderr,"Error: Nao foi encontrado o arquivo sudoku.txt na pasta temp\n");
                exit(-1);
        }

        linha = 0;

        while (fscanf(entrada, "%10s", stringLinha) == 1) {

                length = strlen((char *) stringLinha);

                linha = linha + 1;

                for (i = 1; i <= length; i++) {
                        p_sudoku->G[linha][i] = stringLinha[i-1];
                }

        }

        fclose(entrada);
}

#endif //SUDOKUED1_MATRIZSUDOKU_H_H
