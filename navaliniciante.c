#include <stdio.h>

#define TAMANHO 10   // tamanho fixo do tabuleiro
#define NAVIO 3      // valor que representa navio
#define AGUA 0       // valor que representa água
#define TAM_NAVIO 3  // tamanho fixo dos navios

// Função para posicionar navio horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (coluna + i < TAMANHO && tabuleiro[linha][coluna + i] == AGUA) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

// Função para posicionar navio vertical
void posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha + i < TAMANHO && tabuleiro[linha + i][coluna] == AGUA) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para posicionar navio diagonal (↘)
void posicionarDiagonalPrincipal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha + i < TAMANHO && coluna + i < TAMANHO && tabuleiro[linha + i][coluna + i] == AGUA) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    }
}

// Função para posicionar navio diagonal (↙)
void posicionarDiagonalSecundaria(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha + i < TAMANHO && coluna - i >= 0 && tabuleiro[linha + i][coluna - i] == AGUA) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

   // Posiciona os quatro navios
    posicionarHorizontal(tabuleiro, 2, 4);        // navio horizontal
    posicionarVertical(tabuleiro, 5, 7);          // navio vertical
    posicionarDiagonalPrincipal(tabuleiro, 0, 0); // navio diagonal ↘
    posicionarDiagonalSecundaria(tabuleiro, 0, 9);// navio diagonal ↙

    // Exibe o tabuleiro
    imprimirTabuleiro(tabuleiro);


    return 0;
}
