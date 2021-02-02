/**
 * @file naval_battle.c
 * @author [Carlos Rafael](https://github.com/CarlosZoft)
 * @author [Herick Lima](https://github.com/hericklima22)
 * @brief [naval_battle](https://en.wikipedia.org/wiki/Battleship_(game))
 * implementation in C using only the stdio.h library.
 * @details  Naval battle is a game, to be played by two people. It consists of
 * knocking down the enemy ship, through shots , when hit the ship is
 * revealed with the respective number of its size. Example: size 3 = 3 3 3 on
 * the board.
 */
#include <stdio.h>

/* Function validaEntradaLinhaColuna
 * @param linha matrix row
 * @param coluna matrix column
 * @returns validates row and column entry of the board
 *
 */
int validaEntradaLinhaColuna(int linha, char coluna)
{
    if ((linha >= 1 && linha <= 10) && (coluna >= 65 && coluna <= 74))
    {
        return 1;
    }

    else
        return 0;
}
/**
 * Function validaPosicao
 * @param mat board
 * @param barco boat
 * @param linha matrix row
 * @param coluna matrix column
 * @returns checks if the position is valid
 *
 */
int validaPosicao(int mat[10][10], int barco, int linha, int coluna,
                  char orientacao)
{
    int cont = 0;
    int i, j;

    if (barco < 1 || barco > 3)
        return 0;
    if (orientacao != 'H' && orientacao != 'V')
        return 0;
    if ((linha < 0 || linha > 9) || (coluna < 0 || coluna > 9))
        return 0;

    if (orientacao == 'H')
    {
        if ((10 - coluna) < barco)
            return 0;

        else
        {
            for (j = coluna; j < (coluna + barco); j++)
            {
                if (mat[linha][j] == 0)
                    cont++;
            }
        }
    }

    if (orientacao == 'V')
    {
        if ((10 - linha) < barco)
            return 0;

        else
        {
            for (i = linha; i < (linha + barco); i++)
            {
                if (mat[i][coluna] == 0)
                    cont++;
            }
        }
    }

    if (cont == barco)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 * Function podeAtirar
 * @param mat board
 * @param linha matrix row
 * @param coluna matrix column
 * @returns checks if the position is valid for shooting
 *
 */

int podeAtirar(int mat[10][10], int linha, int coluna)
{
    if (mat[linha][coluna] == -2 || mat[linha][coluna] == 10 ||
        mat[linha][coluna] == 20 || mat[linha][coluna] == 30 ||
        mat[linha][coluna] == 50)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}
/**
 * Function posicionaBarco
 * @param mat board
 * @param barco boat
 * @returns(void) position the boat on the board
 *
 */
void posicionaBarco(int mat[10][10], int barco)
{
    int linha, j, i;
    char coluna, orientacao;

    if (barco == 1)
    {
        scanf("%d %c", &linha, &coluna);

        while (validaEntradaLinhaColuna(linha, coluna) != 1 ||
               validaPosicao(mat, barco, (linha - 1), (coluna - 65), 'H') != 1)
        {
            printf("Posicao indisponivel!\n");
            scanf("%d %c", &linha, &coluna);
        }
    }

    else
    {
        scanf("%d %c %c", &linha, &coluna, &orientacao);

        while (validaEntradaLinhaColuna(linha, coluna) == 0 ||
               validaPosicao(mat, barco, (linha - 1), (coluna - 65),
                             orientacao) == 0)
        {
            printf("Posicao indisponivel!\n");
            scanf("%d %c %c", &linha, &coluna, &orientacao);
        }
    }

    coluna -= 65;
    linha -= 1;

    if (barco == 1)
    {
        for (j = coluna; j < (coluna + barco); j++)
        {
            mat[linha][j] = barco;
        }

        for (int a = linha - 1; a < (linha + barco + 1); a++)
        {
            for (int b = coluna - 1; b < (coluna + barco + 1); b++)
            {
                if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                {
                    if (mat[a][b] != barco)
                        mat[a][b] = -1;
                }
            }
        }
    }

    if (orientacao == 'H')
    {
        for (j = coluna; j < (coluna + barco); j++)
        {
            mat[linha][j] = barco;
        }
        if (barco == 3)
        {
            for (int a = linha - 1; a < (linha + barco - 1); a++)
            {
                for (int b = coluna - 1; b < (coluna + barco + 1); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != barco)
                            mat[a][b] = -1;
                    }
                }
            }
        }

        else
        {
            for (int a = linha - 1; a < (linha + barco); a++)
            {
                for (int b = coluna - 1; b < (coluna + barco + 1); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != barco)
                            mat[a][b] = -1;
                    }
                }
            }
        }
    }

    if (orientacao == 'V')
    {
        for (j = linha; j < (linha + barco); j++)
        {
            mat[j][coluna] = barco;
        }
        if (barco == 3)
        {
            for (int a = linha - 1; a < (linha + barco + 1); a++)
            {
                for (int b = coluna - 1; b < (coluna + barco - 1); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != barco)
                            mat[a][b] = -1;
                    }
                }
            }
        }

        else
        {
            for (int a = linha - 1; a < (linha + barco + 1); a++)
            {
                for (int b = coluna - 1; b < (coluna + barco); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != barco)
                            mat[a][b] = -1;
                    }
                }
            }
        }
    }
}
/**
 * Functions imprimeMensagem and imprimeMensagemPontos
 * @param msg return msg with board
 * @returns prints visual matrix
 *
 */
void imprimeMensagem(char msg[1000])
{
    printf("************************\n");
    printf("*\n");
    printf("* %s\n", msg);
    printf("*\n");
    printf("************************\n");
}
void imprimeMensagemPontos(int pts1, int pts2)
{
    printf("************************\n");
    printf("*\n");
    printf("* PONTUACAO DO JOGADOR 1: %02d\n", pts1);
    printf("* PONTUACAO DO JOGADOR 2: %02d\n", pts2);
    printf("*\n");
    printf("************************\n");
}
/**
 * Function imprimeCelula
 * @param celula return of the logical matrix
 * @param etapa game step
 * @returns prints visual matrix
 *
 */
char imprimeCelula(int celula, int etapa)
{
    if (etapa == 0)
    {
        if (celula == 0)
            return '.';

        if (celula == -1)
            return '*';

        if (celula == 1)
            return '1';

        if (celula == 2)
            return '2';

        if (celula == 3)
            return '3';
    }

    if (etapa == 1)
    {
        if (celula == 0 || celula == -1 || celula == 1 || celula == 2 ||
            celula == 3)
            return '.';

        if (celula == -2)
            return 'x';

        if (celula == 10 || celula == 20 || celula == 30)
            return 'N';

        if (celula == 50)
            return 'A';
    }
}
/**
 * Function imprimeTabuleiro
 * @param mat board
 * @param etapa game step
 * @returns show board
 *
 */
void imprimeTabuleiro(int mat[10][10], int etapa)
{
    int celula;
    char imp;

    printf("     ");
    for (int i = 65; i < 75; i++)
    {
        printf("%c", i);
        if (i < 74)
            printf(" ");
    }
    printf("\n");

    for (int i = 0; i < 12; i++)
    {
        if (i > 0 && i < 11)
            printf("%02d ", i);
        else
            printf("   ");
        for (int j = 0; j < 12; j++)
        {
            if ((i > 0 && i < 11) && (j > 0 && j < 11))
            {
                celula = mat[i - 1][j - 1];
                imp = imprimeCelula(celula, etapa);
                printf("%c", imp);
            }
            else
                printf("#");
            if (j < 11)
                printf(" ");
        }
        printf("\n");
    }
}
/**
 * Function atirar
 * @param mat board
 * @param linha matrix row
 * @param coluna matrix column
 * @returns shoot function
 *
 */
void atirar(int mat[10][10], int linha, int coluna)
{
    if (mat[linha][coluna] == 0 || mat[linha][coluna] == -1)
        mat[linha][coluna] = -2;

    if (mat[linha][coluna] == 1)
        mat[linha][coluna] = 10;

    if (mat[linha][coluna] == 2)
        mat[linha][coluna] = 20;

    if (mat[linha][coluna] == 3)
        mat[linha][coluna] = 30;
}
/**
 * Function calculaPontuacao
 * @param mat board
 * @param linha matrix row
 * @param coluna matrix column
 * @returns calculate score
 *
 */

int calculaPontuacao(int mat[10][10], int linha, int coluna)
{
    int i, j, cont = 1;
    int c = 0, b = 0, e = 0, d = 0;

    if (mat[linha][coluna] == 10)
    {
        mat[linha][coluna] = 50;
        return 2;
    }

    else if (mat[linha][coluna] == 20)
    {
        if (mat[linha + 1][coluna] == 20)
            b = 1;
        if (mat[linha - 1][coluna] == 20)
            c = 1;
        if (mat[linha][coluna + 1] == 20)
            d = 1;
        if (mat[linha][coluna - 1] == 20)
            e = 1;

        if (b == 1)
        {
            if (mat[linha + 1][coluna] == 20)
            {
                mat[linha][coluna] = 50;
                mat[linha + 1][coluna] = 50;
                return 4;
            }
            else
                return 0;
        }

        if (c == 1)
        {
            if (mat[linha - 1][coluna] == 20)
            {
                mat[linha][coluna] = 50;
                mat[linha - 1][coluna] = 50;
                return 4;
            }
            else
                return 0;
        }

        if (d == 1)
        {
            if (mat[linha][coluna + 1] == 20)
            {
                mat[linha][coluna] = 50;
                mat[linha][coluna + 1] = 50;
                return 4;
            }
            else
                return 0;
        }

        if (e == 1)
        {
            if (mat[linha][coluna - 1] == 20)
            {
                mat[linha][coluna] = 50;
                mat[linha][coluna - 1] = 50;
                return 4;
            }
            else
                return 0;
        }
    }

    else if (mat[linha][coluna] == 30)
    {
        if (mat[linha + 1][coluna] == 30)
            b = 1;
        if (mat[linha - 1][coluna] == 30)
            c = 1;
        if (mat[linha][coluna + 1] == 30)
            d = 1;
        if (mat[linha][coluna - 1] == 30)
            e = 1;

        // meio V
        if (b == 1 && c == 1)
        {
            if (mat[linha + 1][coluna] == 30 && mat[linha - 1][coluna] == 30)
            {
                mat[linha][coluna] = 50;
                mat[linha + 1][coluna] = 50;
                mat[linha - 1][coluna] = 50;
                return 7;
            }
            else
                return 0;
        }
        // meio H
        else if (d == 1 && e == 1)
        {
            if (mat[linha][coluna + 1] == 30 && mat[linha][coluna - 1] == 30)
            {
                mat[linha][coluna] = 50;
                mat[linha][coluna - 1] = 50;
                mat[linha][coluna + 1] = 50;
                return 7;
            }
            else
                return 0;
        }
        // direita H
        else if (d == 1)
        {
            if (mat[linha][coluna + 1] == 30 && mat[linha][coluna + 2] == 30)
            {
                mat[linha][coluna] = 50;
                mat[linha][coluna + 1] = 50;
                mat[linha][coluna + 2] = 50;
                return 7;
            }
            else
                return 0;
        }
        // esquerda H
        else if (e == 1)
        {
            if (mat[linha][coluna - 1] == 30 && mat[linha][coluna - 2] == 30)
            {
                mat[linha][coluna] = 50;
                mat[linha][coluna - 1] = 50;
                mat[linha][coluna - 2] = 50;
                return 7;
            }
            else
                return 0;
        }
        // cima V
        else if (c == 1)
        {
            if (mat[linha - 1][coluna] == 30 && mat[linha - 2][coluna] == 30)
            {
                mat[linha][coluna] = 50;
                mat[linha - 1][coluna] = 50;
                mat[linha - 2][coluna] = 50;
                return 7;
            }
            else
                return 0;
        }
        // baixo V
        else if (b == 1)
        {
            if (mat[linha + 1][coluna] == 30 && mat[linha + 2][coluna] == 30)
            {
                mat[linha][coluna] = 50;
                mat[linha + 1][coluna] = 50;
                mat[linha + 2][coluna] = 50;
                return 7;
            }
            else
                return 0;
        }
    }
    return 0;
}
/**
 * Function printaPosicionamento
 * @param jogador number representing the player
 * @param barco number that represents the boat
 * @param nm which message to print
 * @returns shows boat positioning messages
 *
 */
void printaPosicionamento(int jogador, int barco, int nm)
{
    if (jogador == 1)
    {
        // jogador 1 barco 1
        char msg1[60] = "Jogador 1 - Posicione o barco de tamanho 1 (1/6)";
        char msg2[60] = "Jogador 1 - Posicione o barco de tamanho 1 (2/6)";
        char msg3[60] = "Jogador 1 - Posicione o barco de tamanho 1 (3/6)";
        char msg4[60] = "Jogador 1 - Posicione o barco de tamanho 1 (4/6)";
        char msg5[60] = "Jogador 1 - Posicione o barco de tamanho 1 (5/6)";
        char msg6[60] = "Jogador 1 - Posicione o barco de tamanho 1 (6/6)";

        // jogador 1 barco 2
        char msg7[60] = "Jogador 1 - Posicione o barco de tamanho 2 (1/4)";
        char msg8[60] = "Jogador 1 - Posicione o barco de tamanho 2 (2/4)";
        char msg9[60] = "Jogador 1 - Posicione o barco de tamanho 2 (3/4)";
        char msg10[60] = "Jogador 1 - Posicione o barco de tamanho 2 (4/4)";

        // jogador 1 barco 3
        char msg11[60] = "Jogador 1 - Posicione o barco de tamanho 3 (1/2)";
        char msg12[60] = "Jogador 1 - Posicione o barco de tamanho 3 (2/2)";

        if (barco == 1)
        {
            if (nm == 1)
                imprimeMensagem(msg1);
            if (nm == 2)
                imprimeMensagem(msg2);
            if (nm == 3)
                imprimeMensagem(msg3);
            if (nm == 4)
                imprimeMensagem(msg4);
            if (nm == 5)
                imprimeMensagem(msg5);
            if (nm == 6)
                imprimeMensagem(msg6);
        }
        if (barco == 2)
        {
            if (nm == 1)
                imprimeMensagem(msg7);
            if (nm == 2)
                imprimeMensagem(msg8);
            if (nm == 3)
                imprimeMensagem(msg9);
            if (nm == 4)
                imprimeMensagem(msg10);
        }
        if (barco == 3)
        {
            if (nm == 1)
                imprimeMensagem(msg11);
            if (nm == 2)
                imprimeMensagem(msg12);
        }
    }

    if (jogador == 2)
    {
        // jogador 2 barco 1
        char msg1[60] = "Jogador 2 - Posicione o barco de tamanho 1 (1/6)";
        char msg2[60] = "Jogador 2 - Posicione o barco de tamanho 1 (2/6)";
        char msg3[60] = "Jogador 2 - Posicione o barco de tamanho 1 (3/6)";
        char msg4[60] = "Jogador 2 - Posicione o barco de tamanho 1 (4/6)";
        char msg5[60] = "Jogador 2 - Posicione o barco de tamanho 1 (5/6)";
        char msg6[60] = "Jogador 2 - Posicione o barco de tamanho 1 (6/6)";

        // jogador 2 barco 2
        char msg7[60] = "Jogador 2 - Posicione o barco de tamanho 2 (1/4)";
        char msg8[60] = "Jogador 2 - Posicione o barco de tamanho 2 (2/4)";
        char msg9[60] = "Jogador 2 - Posicione o barco de tamanho 2 (3/4)";
        char msg10[60] = "Jogador 2 - Posicione o barco de tamanho 2 (4/4)";

        // jogador 2 barco 3
        char msg11[60] = "Jogador 2 - Posicione o barco de tamanho 3 (1/2)";
        char msg12[60] = "Jogador 2 - Posicione o barco de tamanho 3 (2/2)";

        if (barco == 1)
        {
            if (nm == 1)
                imprimeMensagem(msg1);
            if (nm == 2)
                imprimeMensagem(msg2);
            if (nm == 3)
                imprimeMensagem(msg3);
            if (nm == 4)
                imprimeMensagem(msg4);
            if (nm == 5)
                imprimeMensagem(msg5);
            if (nm == 6)
                imprimeMensagem(msg6);
        }
        if (barco == 2)
        {
            if (nm == 1)
                imprimeMensagem(msg7);
            if (nm == 2)
                imprimeMensagem(msg8);
            if (nm == 3)
                imprimeMensagem(msg9);
            if (nm == 4)
                imprimeMensagem(msg10);
        }
        if (barco == 3)
        {
            if (nm == 1)
                imprimeMensagem(msg11);
            if (nm == 2)
                imprimeMensagem(msg12);
        }
    }
}
/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    int jogador1[10][10];
    int jogador2[10][10];
    int jogadas = 1;
    int pts1 = 0, pts2 = 0, a1 = 0, a2 = 0;
    int linha, col = 0, lin = 0;
    char coluna;
    // filling logical board
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            jogador1[i][j] = 0;
            jogador2[i][j] = 0;
        }
    }
    // positioning of boats on the board
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i == 1)
            {
                printaPosicionamento(i, 1, j);
                imprimeTabuleiro(jogador1, 0);
                posicionaBarco(jogador1, 1);
            }
            if (i == 2)
            {
                printaPosicionamento(i, 1, j);
                imprimeTabuleiro(jogador2, 0);
                posicionaBarco(jogador2, 1);
            }
        }
        for (int j = 1; j <= 4; j++)
        {
            if (i == 1)
            {
                printaPosicionamento(i, 2, j);
                imprimeTabuleiro(jogador1, 0);
                posicionaBarco(jogador1, 2);
            }
            if (i == 2)
            {
                printaPosicionamento(i, 2, j);
                imprimeTabuleiro(jogador2, 0);
                posicionaBarco(jogador2, 2);
            }
        }
        for (int j = 1; j <= 2; j++)
        {
            if (i == 1)
            {
                printaPosicionamento(i, 3, j);
                imprimeTabuleiro(jogador1, 0);
                posicionaBarco(jogador1, 3);
            }
            if (i == 2)
            {
                printaPosicionamento(i, 3, j);
                imprimeTabuleiro(jogador2, 0);
                posicionaBarco(jogador2, 3);
            }
        }
    }
    // match ! where the game has a maximum of 40 moves.
    while (jogadas <= 40)
    {
        if (jogadas % 2 != 0)
        {
            imprimeMensagemPontos(pts1, pts2);
            imprimeMensagem("VEZ DO JOGADOR 1");
            imprimeTabuleiro(jogador2, 1);
            scanf("%d %c", &linha, &coluna);

            while (validaEntradaLinhaColuna(linha, coluna) != 1 ||
                   podeAtirar(jogador2, linha - 1, coluna - 65) != 1)
            {
                linha = 0;
                coluna = 'a';
                printf("Posicao indisponivel!\n");
                scanf("%d %c", &linha, &coluna);
            }
            lin = linha - 1;
            col = coluna - 65;
            atirar(jogador2, lin, col);
            a1 = pts1;
            pts1 += calculaPontuacao(jogador2, lin, col);

            if (a1 != pts1)
            {
                imprimeMensagem("JOGADOR 1 DERRUBOU UM NAVIO!");
            }
        }
        if (jogadas % 2 == 0)
        {
            imprimeMensagemPontos(pts1, pts2);
            imprimeMensagem("VEZ DO JOGADOR 2");
            imprimeTabuleiro(jogador1, 1);
            scanf("%d %c", &linha, &coluna);

            while (validaEntradaLinhaColuna(linha, coluna) != 1 ||
                   podeAtirar(jogador1, linha - 1, coluna - 65) != 1)
            {
                printf("Posicao indisponivel!\n");
                scanf("%d %c", &linha, &coluna);
            }
            lin = linha - 1;
            col = coluna - 65;
            atirar(jogador1, lin, col);
            a2 = pts2;
            pts2 += calculaPontuacao(jogador1, lin, col);

            if (a2 != pts2)
            {
                imprimeMensagem("JOGADOR 2 DERRUBOU UM NAVIO!");
            }
        }

        jogadas++;
    }
    // end game
    imprimeMensagem("FIM DE JOGO");
    imprimeMensagemPontos(pts1, pts2);

    return 0;
}
