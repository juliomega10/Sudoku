#include <stdio.h>
#include "matrizSudoku.h"

//defines
#define ZERO '0'
#define UM '1'

#define CONST_QUANTIDADE_UNS 9
#define CONST_SOMATORIA_UM_A_NOVE 45

#define INDICE_QUANTIDADE_VALORES_POSSIVEIS 10
#define INDICE_VALOR_POSSIVEL 11
#define RESOLVIDO 2

//estruturas
struct Grade {

    int linha;
    int linhaLimite;
    int coluna;
    int colunaLimite;

};

// interfaces
void verificaValorNaLinha(Sudoku *p_sudoku, int linha, unsigned char valoresPossiveis[]);

void verificarValorNaColuna(Sudoku *p_sudoku, int coluna, unsigned char valoresPossiveis[]);

void verificarValorNaGrade(Sudoku *p_sudoku, const struct Grade *grade, unsigned char valoresPossiveis[]);

void gerarValoresDaGrade(struct Grade *grade, int linha, int coluna);

void resolverValoresPossiveis(Sudoku *p_sudoku, int linha, int coluna, unsigned char valoresPossiveis[]);

int resolverPorMetodoSingle(Sudoku *p_sudoku);

void construirValoresPossiveis(unsigned char valoresPossiveis[]);

// interface requerida
void mostrarPossiveis(Sudoku *, int, int);


//main
int main(int argc, char *argv[]) {

    Sudoku sudoku = {.nrCelulas = 10};

    lerMatriz(&sudoku);

    int resolvido;

    int contagem = 0;

    printf("\nInicio\n");

    mostrarMatriz(&sudoku);

    do {

        contagem = contagem + 1;

        resolvido = resolverPorMetodoSingle(&sudoku);

    }while(resolvido != RESOLVIDO && contagem <= 50);

    if(contagem <= 50){
      printf("Quantidade de vezes necessarias para resolver: %d\n", contagem);
      mostrarMatriz(&sudoku);
    }else {
        printf("\nQuantidade de vezes necessarias para resolver: %d\nSudoku impossivel de resolver.\n", contagem);
    }

    return 0;
}
//main


// Implementações

void construirValoresPossiveis(unsigned char valoresPossiveis[]){

    int indice;

    for(indice = 1; indice <= CONST_QUANTIDADE_UNS; indice++){
        valoresPossiveis[indice] = UM;
    }

    valoresPossiveis[0] = ZERO;
    valoresPossiveis[INDICE_QUANTIDADE_VALORES_POSSIVEIS] = CONST_QUANTIDADE_UNS;
    valoresPossiveis[INDICE_VALOR_POSSIVEL] = CONST_SOMATORIA_UM_A_NOVE;

}

inline void resolverValoresPossiveis(Sudoku *p_sudoku, int linha, int coluna, unsigned char valoresPossiveis[]) {

    int indice;

    int valorPossivel;

    indice = p_sudoku->G[linha][coluna] - ZERO;

    valorPossivel = valoresPossiveis[indice] - ZERO;

    valoresPossiveis[INDICE_QUANTIDADE_VALORES_POSSIVEIS] -= valorPossivel;

    valoresPossiveis[INDICE_VALOR_POSSIVEL] -= indice * valorPossivel;

    valoresPossiveis[indice] = ZERO;

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

   base : (1 + 3*a, 3*(a+1))          ; para a <= 2, a pertencente a N

   a = (L - 1)/ 3    ; L = linha         ; 1 <= L <= 9 ; L pertencente a N
   a = (C - 1)/ 3    ; C = coluna        ; 1 <= C <= 9 ; C pertencente a N

 */

    linha = (linha - 1) / 3;
    coluna = (coluna - 1) / 3;

    grade->linha = 1 + 3 * linha;
    grade->linhaLimite = 3 * (linha + 1);
    grade->coluna = 1 + 3 * coluna;
    grade->colunaLimite = 3 * (coluna + 1);

}

void verificaValorNaLinha(Sudoku *p_sudoku, int linha, unsigned char valoresPossiveis[]) {

    int coluna;

    for (coluna = 1; coluna < p_sudoku->nrCelulas; coluna = coluna + 1) {
        resolverValoresPossiveis(p_sudoku, linha, coluna, valoresPossiveis);
    }

}

void verificarValorNaColuna(Sudoku *p_sudoku, int coluna, unsigned char valoresPossiveis[]) {

    int linha;

    for (linha = 1; linha < p_sudoku->nrCelulas; linha = linha + 1) {
        resolverValoresPossiveis(p_sudoku, linha, coluna, valoresPossiveis);
    }

}

void verificarValorNaGrade(Sudoku *p_sudoku, const struct Grade *grade, unsigned char valoresPossiveis[]) {

    int linha, coluna;

    for (linha = grade->linha; linha <= grade->linhaLimite; linha = linha + 1) {
        for (coluna = grade->coluna; coluna <= grade->colunaLimite; coluna = coluna + 1) {
            resolverValoresPossiveis(p_sudoku, linha, coluna, valoresPossiveis);
        }
    }
}

int resolverPorMetodoSingle(Sudoku *p_sudoku) {

    unsigned char valoresPossiveis[INDICE_VALOR_POSSIVEL + 1];

    struct Grade grade;

    int linha, coluna;

    int resolvido;

    resolvido = RESOLVIDO;

    for (linha = 1; linha < p_sudoku->nrCelulas; ++linha) {

        for (coluna = 1; coluna < p_sudoku->nrCelulas; ++coluna) {

            if (p_sudoku->G[linha][coluna] == ZERO) {

                construirValoresPossiveis(valoresPossiveis);

                verificaValorNaLinha(p_sudoku, linha, valoresPossiveis);

                verificarValorNaColuna(p_sudoku, coluna, valoresPossiveis);

                gerarValoresDaGrade(&grade, linha, coluna);

                verificarValorNaGrade(p_sudoku, &grade, valoresPossiveis);

                /*
                 *
                 * f(quantidade, valor) = valor / (quantidade - 1 + valor);
                 * Dominio : {(quantidade,valor) € N² | 1 <= quantidade <= 9 e 1 <= valor <= 45}
                 * Image : {0,1}
                 *
                 * */


                resolvido = valoresPossiveis[INDICE_VALOR_POSSIVEL];

                resolvido = resolvido / (resolvido - 1 + valoresPossiveis[INDICE_QUANTIDADE_VALORES_POSSIVEIS]);

                p_sudoku->G[linha][coluna] = resolvido * valoresPossiveis[INDICE_VALOR_POSSIVEL] + ZERO;

            }

        }
    }

    return resolvido;

}

void mostrarPossiveis(Sudoku *p_sudoku, int linha, int coluna) {

}

// Implementações
