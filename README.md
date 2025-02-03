# Jogo da Forca

Este é um jogo de forca implementado em C, onde o objetivo é adivinhar uma palavra secreta antes de ficar sem tentativas. O jogo escolhe palavras de diferentes temas (frutas, animais ou objetos) a partir de arquivos de texto e permite que o jogador tente adivinhar as letras da palavra.

## Funcionalidades

- **Temas**: O jogador pode escolher entre três temas para a palavra secreta:
  - 1 - Frutas
  - 2 - Animais
  - 3 - Objetos

- **Chances**: O jogador tem 5 chances para errar antes de ser "enforcado".

- **Desenho da Forca**: O jogo desenha a forca e exibe a palavra com os espaços preenchidos pelas letras adivinhadas, ou os espaços em branco para as letras não adivinhadas.

- **Acerto e Erro**: O jogo termina quando o jogador acerta a palavra ou esgota suas chances.

## Como Jogar

1. Clone este repositório para sua máquina local.
2. Compile o código utilizando o compilador de sua preferência (por exemplo, GCC).
   ```bash
   gcc -o forca forca.c
