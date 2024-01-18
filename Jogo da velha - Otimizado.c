#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

void imprimirRegras();
int escolherMatriz();
int sortear();
char *definirPrimeiroJogador(int sorteio, char *nome1, char *nome2);
char *definirSegundoJogador(int sorteio, char *nome1, char *nome2);
int getResultado(char matriz[3][3]);
void imprimirMatriz(char matriz[3][3]);
void imprimirMatrizGuia(char matriz[3][3]);
void imprimirMatrizGuia2(char matriz[3][3]);
void exibirMenuFinal();

int main() {
    setlocale(LC_ALL, "Portuguese");

    int matriz_escolhida = 0;
    char *nome1;
    char *nome2;
    char *primeiro_jogador;
    char *segundo_jogador;
    int sorteio;
    char op;
    int x = 0, o = 0;
    char matriz[3][3];
    char matriz_guia[3][3];
    int i;
    int valor_x = 0, valor_y = 0;
    int pontuacao_nome1 = 0, pontuacao_nome2 = 0;
    int op_menu_final = 0;
    int fim = 0;

    imprimirRegras();

    matriz_escolhida = escolherMatriz();

    nome1 = malloc(17*sizeof(char));
    nome2 = malloc(17*sizeof(char));

    printf("\n\nInsira os IDs dos jogadores abaixo. Podem ser os NOMES, APELIDOS, ou qualquer coisa do tipo.\n*16 CARACTERES NO M�XIMO\n");
    do {
        printf("\nJOGADOR 1: ");
        scanf("%17[^\n]s", nome1);
        fflush(stdin);
        if(strlen(nome1) > 16) {
            printf("\nO n�mero m�ximo de caracteres para o nome � 16. Por favor, digite novamente.");
        }
    }while(strlen(nome1) > 16);
    do {
        printf("\nJOGADOR 2: ");
        scanf("%17[^\n]s", nome2);
        fflush(stdin);
        if(strlen(nome2) > 16) {
            printf("\nO n�mero m�ximo de caracteres para o nome � 16. Por favor, digite novamente.");
        }
    }while(strlen(nome2) > 16);

    while(fim != 1) {
        sorteio = sortear();

        primeiro_jogador = malloc(17*sizeof(char));
        segundo_jogador = malloc(17*sizeof(char));

        strcpy(primeiro_jogador, definirPrimeiroJogador(sorteio, nome1, nome2));
        strcpy(segundo_jogador, definirSegundoJogador(sorteio, nome1, nome2));

        printf("\nQuem come�a �: [%s]", primeiro_jogador);
        do {
            printf("\n[%s], voc� quer ser X ou O? ", primeiro_jogador);
            scanf("%c", &op);
            fflush(stdin);
            if(toupper(op) != 'X' && toupper(op) != 'O') {
                printf("\nInv�lido. Por favor, escolha X ou O.");
            }
        }while(toupper(op) != 'X' && toupper(op) != 'O');

        if(toupper(op) == 'X') {
            // Jogador 1 � X;
            x = 1;
            o = 2;
        }
        else if(toupper(op) == 'O') {
            // Jogador 1 � O;
            o = 1;
            x = 2;
        }

        // ZERAR MATRIZ;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                matriz[i][j] = ' ';
            }
        }

        i = 0;
        while(getResultado(matriz) != 1 && getResultado(matriz) != 2 && i < 9) {
            if(i % 2 == 0) {
                // Vez do jogador 1;
                printf("\n\n[%s] escolha uma posi��o na matriz:\n", primeiro_jogador);
                if(matriz_escolhida == 1) {
                    do {
                        imprimirMatrizGuia(matriz_guia);
                        scanf("%d %d", &valor_x, &valor_y);
                        fflush(stdin);
                        if(valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2) {
                            printf("\nPosi��o inv�lida. Por favor, digite uma posi��o v�lida.");
                        }
                        else if(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y] == 'O')) {
                            printf("\nPosi��o j� ocupada. Por favor, digite outra posi��o.");
                        }
                    }while(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y]) == 'O' || valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2);
                    if(x == 1) {
                        matriz[valor_x][valor_y] = 'X';
                        matriz_guia[valor_x][valor_y] = 'X';
                    }
                    else if(o == 1) {
                        matriz[valor_x][valor_y] = 'O';
                        matriz_guia[valor_x][valor_y] = 'O';
                    }
                }
                else if(matriz_escolhida == 2) {
                    do {
                        imprimirMatrizGuia2(matriz_guia);
                        scanf("%d %d", &valor_x, &valor_y);
                        fflush(stdin);
                        if(valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2) {
                            printf("\nPosi��o inv�lida. Por favor, digite uma posi��o v�lida.");
                        }
                        else if(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y] == 'O')) {
                            printf("\nPosi��o j� ocupada. Por favor, digite outra posi��o.");
                        }
                        }while(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y]) == 'O' || valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2);
                        if(x == 1) {
                        matriz[valor_x][valor_y] = 'X';
                        matriz_guia[valor_x][valor_y] = 'X';
                        }
                        else if(o == 1) {
                        matriz[valor_x][valor_y] = 'O';
                        matriz_guia[valor_x][valor_y] = 'O';
                        }
                }
            }
            else if(i % 2 != 0) {
                // Vez do jogador 2;
                printf("\n\n[%s] escolha uma posi��o na matriz:\n", segundo_jogador);
                if(matriz_escolhida == 1) {
                    do {
                        imprimirMatrizGuia(matriz_guia);
                        scanf("%d %d", &valor_x, &valor_y);
                        fflush(stdin);
                        if(valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2) {
                            printf("\nPosi��o inv�lida. Por favor, digite uma posi��o v�lida.");
                        }
                        else if(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y] == 'O')) {
                            printf("\nPosi��o j� ocupada. Por favor, digite outra posi��o.");
                        }
                    }while(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y]) == 'O' || valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2);
                    if(x == 2) {
                        matriz[valor_x][valor_y] = 'X';
                        matriz_guia[valor_x][valor_y] = 'X';
                    }
                    else if(o == 2) {
                        matriz[valor_x][valor_y] = 'O';
                        matriz_guia[valor_x][valor_y] = 'O';
                    }
                }
                else if(matriz_escolhida == 2) {
                    do {
                        imprimirMatrizGuia(matriz_guia);
                        scanf("%d %d", &valor_x, &valor_y);
                        fflush(stdin);
                        if(valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2) {
                            printf("\nPosi��o inv�lida. Por favor, digite uma posi��o v�lida.");
                        }
                        else if(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y] == 'O')) {
                            printf("\nPosi��o j� ocupada. Por favor, digite outra posi��o.");
                        }
                    }while(toupper(matriz[valor_x][valor_y]) == 'X' || toupper(matriz[valor_x][valor_y]) == 'O' || valor_x < 0 || valor_x > 2 || valor_y < 0 || valor_y > 2);
                    if(x == 2) {
                        matriz[valor_x][valor_y] = 'X';
                        matriz_guia[valor_x][valor_y] = 'X';
                    }
                    else if(o == 2) {
                        matriz[valor_x][valor_y] = 'O';
                        matriz_guia[valor_x][valor_y] = 'O';
                    }
                }
            }
            imprimirMatriz(matriz);
            i++;
        }

        if(getResultado(matriz) == 1) {
            // SIGNIFICA QUE 'X' GANHOU;
            if(x == 1) {
                printf("\n\nVENCEDOR: [%s]\n", primeiro_jogador);
                if(strcmp(primeiro_jogador, nome1) == 0) {
                    pontuacao_nome1++;
                }
                else {
                    pontuacao_nome2++;
                }
            }
            else if(x == 2) {
                printf("\n\nVENCEDOR: [%s]\n", segundo_jogador);
                if(strcmp(segundo_jogador, nome1) == 0) {
                    pontuacao_nome1++;
                }
                else {
                    pontuacao_nome2++;
                }
            }
        }
        else if(getResultado(matriz) == 2) {
            // SIGNIFICA QUE 'O' GANHOU;
            if(o == 1) {
                printf("\n\nVENCEDOR: [%s]\n", primeiro_jogador);
                if(strcmp(primeiro_jogador, nome1) == 0) {
                    pontuacao_nome1++;
                }
                else {
                    pontuacao_nome2++;
                }
            }
            else if(o == 2) {
                printf("\n\nVENCEDOR: [%s]\n", segundo_jogador);
                if(strcmp(segundo_jogador, nome1) == 0) {
                    pontuacao_nome1++;
                }
                else {
                    pontuacao_nome2++;
                }
            }
        }
        else {
            printf("\n\nEMPATE.\n");
        }

        do{
            exibirMenuFinal();
            printf("\n\nO que deseja fazer? ");
            scanf("%d", &op_menu_final);
            fflush(stdin);

            if(op_menu_final == 2) {
                printf("\n[%s] - %d", nome1, pontuacao_nome1);
                printf("\n[%s] - %d\n", nome2, pontuacao_nome2);
            }
            else if(op_menu_final == 1) {
                fim = 0;
            }
            else if(op_menu_final == 3) {
                fim = 1;
            }
        }while(op_menu_final == 2);
    }

    return 0;
}

void imprimirRegras() {
    printf("Seja bem-vindo(a) ao Jogo da Velha!\n");
    printf("\n*** REGRAS **");
    printf("\n[1] - Para jogar, s�o necess�rios 2 jogadores.");
    printf("\n\n[2] - O jogador que come�a escolhe se ser� X ou O.");
    printf("\n\n[3] - O jogo � alternado, ou seja, uma vez o jogador 1 joga e, na outra vez, o jogador 2 joga (o jogo ir� informar de quem � a vez).");
    printf("\n\n[4] - O jogador de quem � a vez deve escolher uma posi��o da matriz 3x3, e inserir atrav�s do teclado os valores dessa posi��o. Por exemplo: 0 0\nA posi��o 0 0 representa a casa da primeira linha e primeira coluna.\nOBS: A maneira correta, e a �nica aceit�vel � digitando o n�mero da linha, espa�o e o n�mero da coluna.");
    printf("\n\n[5] - Ap�s escolher a posi��o, a casa correspondente ser� marcada com X ou O; isso depende se o jogador que escolheu � X ou O.");
    printf("\n\n[6] - O jogador que conseguir uma sequ�ncia em linha horizontal, vertical ou diagonal vence.");

    printf("\n\nExemplo das matriz 3x3 dispon�veis:");
    printf("\nMATRIZ 1: \t[0-0]  [0-1]  [0-2]");
    printf("\n\n\t\t[1-0]  [1-1]  [1-2]");
    printf("\n\n\t\t[2-0]  [2-1]  [2-2]\n");

    printf("\nMATRIZ 2: \t0-0 | 0-1 | 0-2");
    printf("\n\t\t---------------");
    printf("\n\t\t1-0 | 1-1 | 1-2");
    printf("\n\t\t---------------");
    printf("\n\t\t2-0 | 2-1 | 2-2\n");
}

int escolherMatriz() {
    int matriz_escolhida;

    printf("\n\nEscolha uma das matrizes dispon�veis (1 ou 2): ");
    while(matriz_escolhida != 1 && matriz_escolhida != 2) {
        scanf("%d", &matriz_escolhida);
        fflush(stdin);
        if(matriz_escolhida != 1 && matriz_escolhida != 2) {
            printf("\nInv�lido. Por favor, escolha uma matriz, 1 ou 2.\n");
        }
    }

    return matriz_escolhida;
}

int sortear() {
    int sorteio;

    srand(time(NULL)); // Fun��o para fazer com que os valores da vari�vel "sorteio" sejam realmente aleat�rios.
    sorteio = rand() % 2;

    return sorteio;
}

char *definirPrimeiroJogador(int sorteio, char *nome1, char *nome2) {
    char *primeiro_jogador;

    primeiro_jogador = malloc(17*sizeof(char));

    if(sorteio == 0) {
        // O primeiro a jogar � o nome1.
        strcpy(primeiro_jogador, nome1);
    }
    else if(sorteio == 1) {
        strcpy(primeiro_jogador, nome2);
    }
    return primeiro_jogador;
}

char *definirSegundoJogador(int sorteio, char *nome1, char *nome2) {
    char *segundo_jogador;

    segundo_jogador = malloc(17*sizeof(char));

    if(sorteio == 0) {
        strcpy(segundo_jogador, nome2);
    }
    else if(sorteio == 1) {
        strcpy(segundo_jogador, nome1);
    }

    return segundo_jogador;
}

int getResultado(char matriz[3][3]) {
    // RESULTADOS -> X = 1; O = 2; EMPATE = 0;
    // Resultados poss�veis - X
    if(matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X') {return 1;}
    else if(matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X') {return 1;}
    else if(matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X') {return 1;}
    else if(matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X') {return 1;}
    else if(matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X') {return 1;}
    else if(matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X') {return 1;}
    else if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X') {return 1;}
    else if(matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X') {return 1;}
    // Resultados poss�veis - O
    if(matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O') {return 2;}
    else if(matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O') {return 2;}
    else if(matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O') {return 2;}
    else if(matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O') {return 2;}
    else if(matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O') {return 2;}
    else if(matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O') {return 2;}
    else if(matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O') {return 2;}
    else if(matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O') {return 2;}
    else {return 0;}
}

void imprimirMatriz(char matriz[3][3]) {
    for(int i = 0; i < 3; i++) {
        printf("\n");
        for(int j = 0; j < 3; j++) {
            printf("\t[ %c ]", matriz[i][j]);
        }
    }
}

void imprimirMatrizGuia(char matriz_guia[3][3]) {
    for(int i = 0; i < 3; i++) {
        printf("\n");
        for(int j = 0; j < 3; j++) {
            printf("\t[%d-%d]", i, j);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatrizGuia2(char matriz_guia[3][3]) {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j < 2) {
                printf("\t%d-%d  |", i, j);
            }
            else {
                printf("\t%d-%d", i, j);
            }

        }
        printf("\n\t---------------------\n");
    }
}

void exibirMenuFinal() {
    printf("\n[1] - JOGAR NOVAMENTE.");
    printf("\n[2] - EXIBIR PONTUA��ES.");
    printf("\n[3] - SAIR.");
}
