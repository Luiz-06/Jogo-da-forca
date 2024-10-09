#ifndef FORCA_H
#define FORCA_H

void bemVindo();
void escolherTema(int* tema);
void escolhePalavra(char palavraSecreta[], int tema);
int jaChutou(char letra, char chutes[], int tentativas);
int acertou(int tentativas, char chutes[], char palavraSecreta[]);
void desenhaForca(char palavraSecreta[], char chutes[], int tentativas, int chancesFaltando);
void realizeSeuPalpite(char chutes[], int* tentativas, int* chancesFaltando, char palavraSecreta[]);
int enforcou(int tentativas, char chutes[], char palavraSecreta[]);
void mensagemFinal(int acertou, int enforcou, char palavraSecreta[]);

#endif // FORCA_H
