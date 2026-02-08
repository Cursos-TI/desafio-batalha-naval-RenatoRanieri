#include <stdio.h>

#define TAMANHO 10   // tamanho fixo do tabuleiro
#define NAVIO 3      // valor que representa navio
#define AGUA 0       // valor que representa água
#define HABILIDADE 5 // valor que representa área de efeito
#define TAM_HAB 5    // tamanho fixo das matrizes de habilidade

// Função para inicializar tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para imprimir tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para construir matriz Cone
void construirCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Condicional: forma de cone (triângulo apontando para baixo)
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para construir matriz Cruz
void construirCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Condicional: linha central ou coluna central
            if (i == TAM_HAB/2 || j == TAM_HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para construir matriz Octaedro (losango)
void construirOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Condicional: distância de Manhattan <= centro
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Função para sobrepor matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);
                // Validação de limites
                if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO) {
                    // Marca área de efeito sem sobrescrever navio
                    if (tabuleiro[linhaTab][colunaTab] == AGUA)
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Exemplo: posicionar alguns navios fixos
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[2][6] = NAVIO;

    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicar habilidades em pontos de origem
    aplicarHabilidade(tabuleiro, cone, 1, 1);       // cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);  // octaedro no canto inferior direito

    // Exibir tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
