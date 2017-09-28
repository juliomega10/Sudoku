#include <stdio.h>
#include "matrizSudoku.h"

//defines
#define ZERO '0'
#define UM '1'

#define CONST_QUANTIDADE_UNS 9
#define CONST_SOMATORIA_UM_A_NOVE 45

#define INDICE_QUANTIDADE_VALORES_POSSIVEIS 10
#define INDICE_VALOR_UNICO 11

//estruturas
struct Grade {

    unsigned linha : 4;
    unsigned linhaLimite : 4;
    unsigned coluna : 4;
    unsigned colunaLimite : 4;

};

// interfaces
void verificaValorNaLinha(Sudoku *p_sudoku, int linha, unsigned char valoresPossiveis[]);

void verificarValorNaColuna(Sudoku *p_sudoku, int coluna, unsigned char valoresPossiveis[]);

void verificarValorNaGrade(Sudoku *p_sudoku, const struct Grade *grade, unsigned char *valoresPossiveis);

void gerarValoresDaGrade(struct Grade *grade, int linha, int coluna);

void resolverPorMetodoSingle(Sudoku *p_sudoku);

// interface requerida
void mostrarPossiveis(Sudoku *, int, int);

//main
int main(int argc, char *argv[]) {

    int i;

    unsigned char valoresPossiveis[] = {
            ZERO,
            UM, UM, UM, UM, UM, UM, UM, UM, UM,
            CONST_QUANTIDADE_UNS, CONST_SOMATORIA_UM_A_NOVE
    };

    Sudoku sudoku = {.nrCelulas = 10};

    lerMatriz(&sudoku);

    verificaValorNaLinha(&sudoku, 7, valoresPossiveis);

    for (i = 1; i <= INDICE_VALOR_UNICO; i++) {
        printf("%d,", valoresPossiveis[i]);
    }

    putchar('\n');

    verificarValorNaColuna(&sudoku, 9, valoresPossiveis);

    for (i = 1; i <= INDICE_VALOR_UNICO; i++) {
        printf("%d,", valoresPossiveis[i]);
    }

    putchar('\n');

    struct Grade grade;

    gerarValoresDaGrade(&grade,2,5);

    printf("linha:%d\nlinha limite:%d\ncoluna:%d\ncoluna limite:%d\n", grade.linha,grade.linhaLimite,grade.coluna,grade.colunaLimite);

    // LOOP

    // Resolver Por Metodo Single¹ ()
    // mostrarPossiveis

    // RESOLVER SUDOKU

    return 0;
}
//main


// Implementações
void verificaValorNaLinha(Sudoku *p_sudoku, int linha, unsigned char valoresPossiveis[]) {

    int coluna;
    int indice;
    int valorPossivel;

    for (coluna = 1; coluna < p_sudoku->nrCelulas; coluna = coluna + 1) {

        indice = p_sudoku->G[linha][coluna] - ZERO;

        valorPossivel = valoresPossiveis[indice] - ZERO;

        valoresPossiveis[INDICE_QUANTIDADE_VALORES_POSSIVEIS] -= valorPossivel;

        valoresPossiveis[INDICE_VALOR_UNICO] -= indice * valorPossivel;

        valoresPossiveis[indice] = ZERO;

    }

}

void verificarValorNaColuna(Sudoku *p_sudoku, int coluna, unsigned char valoresPossiveis[]) {

    int linha;
    int indice;
    int valorPossivel;

    for (linha = 1; linha < p_sudoku->nrCelulas; linha = linha + 1) {

        indice = p_sudoku->G[linha][coluna] - ZERO;

        valorPossivel = valoresPossiveis[indice] - ZERO;

        valoresPossiveis[INDICE_QUANTIDADE_VALORES_POSSIVEIS] -= valorPossivel;

        valoresPossiveis[INDICE_VALOR_UNICO] -= indice * valorPossivel;

        valoresPossiveis[indice] = ZERO;

    }

}

void verificarValorNaGrade(Sudoku *p_sudoku, const struct Grade *grade, unsigned char *valoresPossiveis) {

    int linha, coluna;

    for (linha = grade->linha; linha < grade->linhaLimite; linha = linha + 1) {
        for (coluna = grade->coluna; coluna < grade->colunaLimite; coluna = coluna + 1) {
            /*TODO: Verificar valor em grade */
        }
    }
}

void gerarValoresDaGrade(struct Grade *grade, int linha, int coluna) {

/*
              Análise do problema

   Grade 1 <> coluna = [1,3] ; linha = [1,3]
   Grade 2 <> coluna = [1,3] ; linha = [4,6]
   Grade 3 <> coluna = [1,3] ; linha = [7,9]

   Grade 4 <> coluna = [4,6] ; linha = [1,3]
   Grade 5 <> coluna = [4,6] ; linha = [4,6]
   Grade 6 <> coluna = [4,6] ; linha = [7,9]

   Grade 7 <> coluna = [7,9] ; linha = [1,3]
   Grade 8 <> coluna = [7,9] ; linha = [4,6]
   Grade 9 <> coluna = [7,9] ; linha = [7,9]

   V = { v1, v2, v3}

   v1 = (1,3)
   v2 = (4,6)
   v3 = (7,9)

   base : (1 + 3*a, 3*(a+1))

 */

 linha  = (linha  - 1) / 3;
 coluna = (coluna - 1) / 3;

 grade->linha = 1 + 3 * linha;
 grade->linhaLimite = 3 * (linha + 1);
 grade->coluna = 1 + 3 * coluna;
 grade->colunaLimite = 3 * (coluna + 1);

}

void resolverPorMetodoSingle(Sudoku *p_sudoku) {

    unsigned char valoresPossiveis[] = {
      ZERO,
      UM, UM, UM, UM, UM, UM, UM, UM, UM,
      CONST_QUANTIDADE_UNS,CONST_SOMATORIA_UM_A_NOVE
    };

    struct Grade quadrante;

}

void mostrarPossiveis(Sudoku *p_sudoku, int linha, int coluna) {

}

// Implementações
