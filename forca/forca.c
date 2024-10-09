#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

void  bemVindo() {
    printf("/*************/\n");
    printf(" * Bem Vindo *\n");
    printf("/*************/\n\n");
}

void escolherTema(int* tema) {
    printf("Selecione o tema: \n");

    printf("1 - Fruta\n");
    printf("2 - Animal\n");
    printf("3 - Objeto\n\n");

    printf("Digite o numero do tema: ");

    scanf("%d", tema);
    printf("\n\n");
}

void escolhePalavra(char palavraSecreta[], int tema) {
    FILE* arquivoTxt;
    
    switch (tema) {
        case 1:
            arquivoTxt = fopen("palavras/frutas.txt", "r");
            break;
        case 2:
            arquivoTxt = fopen("palavras/animais.txt", "r");
            break;
        case 3:
            arquivoTxt = fopen("palavras/objetos.txt", "r");
            break;
        default:
            printf("Tema inválido. Usando tema padrão.\n");
            arquivoTxt = fopen("palavras/frutas.txt", "r");
            break;
    }

    if (arquivoTxt == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        exit(1);
    }

    int qtdDePalavras;
    fscanf(arquivoTxt, "%d", &qtdDePalavras);

    srand(time(0));
    int aleatorio = rand() % qtdDePalavras;

    for (int i = 0; i <= aleatorio; i++) {
        fscanf(arquivoTxt, "%s", palavraSecreta);
    }

    fclose(arquivoTxt);
}

void desenhaForca(char palavraSecreta[], char chutes[], int tentativas, int chancesFaltando) {

    system("cls||clear");

    printf("Voce ainda tem %d chances.\n", chancesFaltando);

    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (jaChutou(palavraSecreta[i], chutes, tentativas)) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
}

void realizeSeuPalpite(char chutes[], int* tentativas, int* chancesFaltando, char palavraSecreta[]) {
    char chute;
    printf("Chute uma letra: ");
    scanf(" %c", &chute);
    printf("\n");

    int naoEncontrou = 0;

    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (chute == palavraSecreta[i]) {
            naoEncontrou = 1;
            break;
        }
    }

    if (!naoEncontrou) {
        (*chancesFaltando)--;
    }

    chutes[*tentativas] = chute;
    (*tentativas)++;

}

int jaChutou(char letra, char chutes[], int tentativas) {
    for (int i = 0; i < tentativas; i++) {
        if (chutes[i] == letra) {
            return 1;
        }
    }

    return 0;
}

int acertou(int tentativas, char chutes[], char palavraSecreta[]) {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (!jaChutou(palavraSecreta[i], chutes, tentativas)) {
            return 0;
        }
    }
    return 1;
}

int enforcou(int tentativas, char chutes[], char palavraSecreta[]) {
    int erros = 0;
    for (int i = 0; i < tentativas; i++) {
        if (!jaChutou(chutes[i], palavraSecreta, strlen(palavraSecreta))) {
            erros++;
        }
    }
    return erros == 5;
}

void mensagemFinal(int acertou, int enforcou, char palavraSecreta[]) {
    if (acertou) {

        system("cls||clear");

        printf("Parabens, voce acertou!\n\n\n");
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else if (enforcou) {

        system("cls||clear");

        printf("Que pena, voce perdeu!\n\n\n");
        printf("A palavra secreta era: %s\n\n\n", palavraSecreta);
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n\n");
    }

    printf("Obrigado por jogar!\n");
}

int main() {
    int tentativas = 0;
    char chutes[10];
    char palavraSecreta[20];

    int tema = 0;
    int chancesFaltando = 5; 

    bemVindo();
    escolherTema(&tema);
    escolhePalavra(palavraSecreta, tema);

    do {
        desenhaForca(palavraSecreta, chutes, tentativas, chancesFaltando);
        printf("\n\n");
        realizeSeuPalpite(chutes, &tentativas, &chancesFaltando, palavraSecreta);

    } while (!acertou(tentativas, chutes, palavraSecreta) && !enforcou(tentativas, chutes, palavraSecreta));

    mensagemFinal(acertou(tentativas, chutes, palavraSecreta), enforcou(tentativas, chutes, palavraSecreta), palavraSecreta);

    return 0;
}
