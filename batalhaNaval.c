#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define H 10    // colunas
#define V 10    // linhas

int tabuleiro[H][V] = {0};  // tabuleiro

void DesenharTabuleiro()
{
    for(int y = 0; y < V; y++)  // percorre o array
    {
        for(int x = 0; x < H; x++)  // percorre o array
        {
            printf("%i ", tabuleiro[x][y]); // desenha o tabuleiro
        }
        printf("\n"); // espaço entre as celulas
    }
}

int VerificarPosicao(int x, int y, int dir) {
    if (dir == 0)   // verificar horizontal
    {
        if (x < 0 || x > H - 3 || y < 0 || y >= V) return 0;    // checa posição fora do tabuleiro
        for (int i = 0; i < 3; i++) // checa posição ocupada
        {
            if (tabuleiro[x + i][y] != 0) return 0;  // célula ocupada
        }
    } 
    else if (dir == 1)  // verificar vertical
    {
        if (x < 0 || x >= H || y < 0 || y > V - 3) return 0;    // checa posição fora do tabuleiro
        for (int i = 0; i < 3; i++) // checa posição ocupada
        {
            if (tabuleiro[x][y + i] != 0) return 0;  // célula ocupada
        }
    }
    else if (dir == 2)  // verificar diagonal direita
    {
        if (x < 0 || x > H - 3 || y < 0 || y > V - 3) return 0;    // checa posição fora do tabuleiro
        for (int i = 0; i < 3; i++) // checa posição ocupada
        {
            if (tabuleiro[x + i][y + i] != 0) return 0;  // célula ocupada
        }
    }
    else if (dir == 3)  // verificar diagonal esquerda
    {
        if (x < 2 || x >= H || y < 0 || y > V - 3) return 0;    // checa posição fora do tabuleiro
        for (int i = 0; i < 3; i++) // checa posição ocupada
        {
            if (tabuleiro[x - i][y + i] != 0) return 0;  // célula ocupada
        }
    }
    return 1;  // posição é válida
}

void PosicionarNavio(int x, int y, int dir)
{
    // Switch para checar a direção do navio
    switch(dir)
    {
        case 0: // horizontal
            if (!VerificarPosicao(x, y, dir))  // checar se a posição é válida
            {
                printf("Posição inválida!\n");
                return;
            }
            for (int i = 0; i < 3; i++) // marcar as posições no tabuleiro
            {
                tabuleiro[x + i][y] = 3;
            }
            break;
        case 1: // vertical
            if (!VerificarPosicao(x, y, dir))  // checar se a posição é válida
            {
                printf("Posição inválida!\n");
                return;
            }
            for (int i = 0; i < 3; i++) // marcar as posições no tabuleiro
            {
                tabuleiro[x][y + i] = 3;
            }
            break;
        case 2: // diagonal direita
            if (!VerificarPosicao(x, y, dir))  // checar se a posição é válida
            {
                printf("Posição inválida!\n");
                return;
            }
            for (int i = 0; i < 3; i++) // marcar as posições no tabuleiro
            {
                tabuleiro[x + i][y + i] = 3;
            }
            break;
        case 3: // diagonal esquerda
            if (!VerificarPosicao(x, y, dir))  // checar se a posição é válida
            {
                printf("Posição inválida!\n");
                return;
            }
            for (int i = 0; i < 3; i++) // marcar as posições no tabuleiro
            {
                tabuleiro[x - i][y + i] = 3;
            }
            break;
        default:    // a direção escolhida é inválida
            printf("Direção inválida!\n");
    }
}

void DesenharCone(int x, int y)
{
    int cone[3][5] = // array com a forma do cone
    {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    if (x >= 0 && x + 3 <= H && y >= 0 && y + 5 <= V) // checa se o cone cabe no tabuleiro
    {
        for (int i = 0; i < 3; i++) // percorre o array
        {
            for (int j = 0; j < 5; j++) // percorre o array
            {
                if (cone[i][j] == 1)    // checa se a posição é 1 no array
                {
                    tabuleiro[x + i][y + j] = 1;    // desenha o cone
                }
            }
        }
    }
    else
    {
        printf("O cone não cabe no tabuleiro.\n");    // não coube
    }
}

void DesenharOctaedro(int x, int y)
{
    int octaedro[5][5] = // array com a forma do octaedro
    {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    if (x >= 0 && x + 5 <= H && y >= 0 && y + 5 <= V)   // checa se o octaedro está dentro do tabuleiro
    {
        for (int i = 0; i < 5; i++) // percorre o array
        {
            for (int j = 0; j < 5; j++) // percorre o array
            {
                if(octaedro[i][j] == 0) continue;   // checa se a posição é 1 no array, se não, ignora
                tabuleiro[x + i][y + j] = octaedro[i][j];   // desenha o octaedro
            }
        }
    }
    else
    {
        printf("O octaedro não cabe no tabuleiro.\n");    // não coube
    }
}

void DesenharCruz(int x, int y)
{
    int cruz[3][3] = // array com a forma da cruz
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    if (x >= 0 && x + 3 <= H && y >= 0 && y + 3 <= V)   // checa o tamanho da cruz
    {
        for (int i = 0; i < 3; i++) // percorre o array
        {
            for (int j = 0; j < 3; j++) // percorre o array
            {
                if (cruz[i][j] == 1)    // checa se é 1 no array
                {
                    tabuleiro[x + i][y + j] = 1;    // desenha a cruz
                }
            }
        }
    }
    else    // não coube
    {
        printf("A cruz não cabe no tabuleiro.\n");
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    PosicionarNavio(6, 8, 0);   // navio horizontal
    PosicionarNavio(1, 6, 1);   // navio vertical

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    PosicionarNavio(1, 1, 2);   // navio diagonal
    PosicionarNavio(7, 3, 3);   // navio diagonal

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    DesenharCone(2, 5);
    DesenharOctaedro(3, 0);
    DesenharCruz(6, 6);
    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    DesenharTabuleiro();
    return 0;
}
