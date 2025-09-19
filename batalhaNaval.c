#include <stdio.h>

// Função para mostrar um tabuleiro genérico
void mostrarTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ----------------- NÍVEL NOVATO -----------------
void nivelNovato() {
    int tabuleiro[5][5] = {0};

    // Navio 1 - vertical (coluna 1, linhas 0 a 2)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][1] = 3;
        printf("Navio vertical em: (%d,%d)\n", i, 1);
    }

    // Navio 2 - horizontal (linha 4, colunas 2 a 4)
    for (int j = 2; j < 5; j++) {
        tabuleiro[4][j] = 3;
        printf("Navio horizontal em: (%d,%d)\n", 4, j);
    }

    printf("\nTabuleiro 5x5:\n");
    mostrarTabuleiro(5, 5, tabuleiro);
}

// ----------------- NÍVEL AVENTUREIRO -----------------
void nivelAventureiro() {
    int tabuleiro[10][10] = {0};

    // Navio horizontal
    for (int j = 0; j < 4; j++) {
        tabuleiro[0][j] = 3;
    }

    // Navio vertical
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][9] = 3;
    }

    // Navio diagonal principal
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio diagonal secundária
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    printf("\nTabuleiro 10x10:\n");
    mostrarTabuleiro(10, 10, tabuleiro);
}

// ----------------- NÍVEL MESTRE -----------------
void nivelMestre() {
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Cone
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            cone[i][j] = 1;
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // linha do meio
        cruz[i][2] = 1; // coluna do meio
    }

    // Octaedro
    octaedro[2][2] = 1;
    octaedro[1][2] = 1;
    octaedro[2][1] = 1;
    octaedro[2][3] = 1;
    octaedro[3][2] = 1;

    printf("\nCone:\n");
    mostrarTabuleiro(5, 5, cone);

    printf("\nCruz:\n");
    mostrarTabuleiro(5, 5, cruz);

    printf("\nOctaedro:\n");
    mostrarTabuleiro(5, 5, octaedro);
}

// ----------------- FUNÇÃO PRINCIPAL -----------------
int main() {
    int escolha;

    do {
        printf("\n=== BATALHA NAVAL - MATECHECK ===\n");
        printf("1 - Nivel Novato (5x5)\n");
        printf("2 - Nivel Aventureiro (10x10)\n");
        printf("3 - Nivel Mestre (habilidades)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                nivelNovato();
                break;
            case 2:
                nivelAventureiro();
                break;
            case 3:
                nivelMestre();
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
