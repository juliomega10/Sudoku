#include <stdio.h>
#include "matrizSudoku.h"

//estruturas
struct Quadrante {

    unsigned i: 4;
    unsigned iLimite: 4;
    unsigned j: 4;
    unsigned jLimite: 4;

};

// interfaces
void verificaValorNaLinha       (Sudoku * p_sudoku, int linha, unsigned char valoresPossiveis[]);
void verificarValorNaColuna     (Sudoku * p_sudoku, int coluna, unsigned char valoresPossiveis[]);
void verificarValorNoQuadrante  (Sudoku * p_sudoku, struct Quadrante * quadrante, unsigned char valoresPossiveis[]);
void resolverPorMetodoSingle    (Sudoku * p_sudoku, struct Quadrante * quadrante);

// interface requerida
void mostrarPossiveis(Sudoku *, int, int);

//main
int main(int argc, char * argv[]){

    Sudoku sudoku;

    lerMatriz(&sudoku);

    // LOOP

    // Resolver Por Metodo Single¹ ()
    // mostrarPossiveis

    // RESOLVER SUDOKU
}
//main


// Implementações
void verificaValorNaLinha(Sudoku * p_sudoku, int linha, unsigned char valoresPossiveis[]){

}

void verificarValorNaColuna(Sudoku * p_sudoku, int coluna, unsigned char valoresPossiveis[]){

}

void verificarValorNoQuadrante(Sudoku * p_sudoku, struct Quadrante * quadrante, unsigned char valoresPossiveis[]){

}

void resolverPorMetodoSingle(Sudoku * p_sudoku, struct Quadrante * quadrante){

}

void mostrarPossiveis(Sudoku * p_sudoku, int linha, int coluna){

}
// Implementações

