#include <stdio.h>
#include "matrizSudoku.h"

//defines
#define ZERO '0'
#define UM '1'

//estruturas
struct Quadrante {

        unsigned linha : 4;
        unsigned linhaLimite : 4;
        unsigned coluna : 4;
        unsigned colunaLimite : 4;

};

// interfaces
void verificaValorNaLinha      (Sudoku * p_sudoku, int linha, unsigned char valoresPossiveis[]);
void verificarValorNaColuna    (Sudoku * p_sudoku, int coluna, unsigned char valoresPossiveis[]);
void verificarValorNoQuadrante (Sudoku * p_sudoku, const struct Quadrante * quadrante, unsigned char valoresPossiveis[]);
void gerarValoresDoQuadrante   (struct Quadrante * quadrante, int linha, int coluna);
void resolverPorMetodoSingle   (Sudoku * p_sudoku);

// interface requerida
void mostrarPossiveis(Sudoku *, int, int);

//main
int main(int argc, char * argv[]){

        Sudoku sudoku = {.nrCelulas = 10};

        lerMatriz(&sudoku);

        // LOOP

        // Resolver Por Metodo Single¹ ()
        // mostrarPossiveis

        // RESOLVER SUDOKU
}
//main


// Implementações
void verificaValorNaLinha(Sudoku * p_sudoku, int linha, unsigned char valoresPossiveis[]){

        int coluna;
        int indice;

        for(coluna = 1; coluna < p_sudoku->nrCelulas; coluna = coluna + 1) {
                indice = p_sudoku->G[linha][coluna] - ZERO;
                valoresPossiveis[indice] = ZERO;
        }

}

void verificarValorNaColuna(Sudoku * p_sudoku, int coluna, unsigned char valoresPossiveis[]){

        int linha;
        int indice;

        for(linha = 1; linha < p_sudoku->nrCelulas; linha = linha + 1) {
                indice = p_sudoku->G[linha][coluna] - ZERO;
                valoresPossiveis[indice] = ZERO;
        }

}

void verificarValorNoQuadrante(Sudoku * p_sudoku,  const struct Quadrante * quadrante, unsigned char valoresPossiveis[]){

        int linha, coluna;

        for (linha = quadrante->linha; linha < quadrante->linhaLimite; linha = linha + 1) {
                for (coluna = quadrante->coluna; coluna < quadrante->colunaLimite; coluna = coluna + 1) {
                        /*TODO: Verificar valor em quadrante */
                }
        }
}

/*TODO: mapear quadrante conforme linha e coluna*/
void gerarValoresDoQuadrante(struct Quadrante * quadrante, int linha, int coluna){

/*

   Quadrante 1 <> coluna = [1,3] ; linha = [1,3]
   Quadrante 2 <> coluna = [1,3] ; linha = [4,6]
   Quadrante 3 <> coluna = [1,3] ; linha = [7,9]

   Quadrante 4 <> coluna = [4,6] ; linha = [1,3]
   Quadrante 5 <> coluna = [4,6] ; linha = [4,6]
   Quadrante 6 <> coluna = [4,6] ; linha = [7,9]

   Quadrante 7 <> coluna = [7,9] ; linha = [1,3]
   Quadrante 8 <> coluna = [7,9] ; linha = [4,6]
   Quadrante 9 <> coluna = [7,9] ; linha = [7,9]

 */

}

void resolverPorMetodoSingle(Sudoku * p_sudoku){

        unsigned char valoresPossiveis[] = {ZERO,UM,UM,UM,UM,UM,UM,UM,UM,UM};

        Quadrante quadrante;

}

void mostrarPossiveis(Sudoku * p_sudoku, int linha, int coluna){

}

// Implementações
