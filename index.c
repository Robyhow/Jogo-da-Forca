#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 20

char* palavras[] = {"ABACAXI", "BANANA", "LARANJA", "MELANCIA", "MORANGO"};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int escolherPalavra(char* palavra) {
    int indice = rand() % (sizeof(palavras) / sizeof(palavras[0]));
    strcpy(palavra, palavras[indice]);
    return strlen(palavra);
}

void mostrarForca(int erros) {
    printf("\n\n");
    printf("  +---+\n");
    printf("  |   |\n");
    
    if (erros >= 1)
        printf("  O   |\n");
    else
        printf("      |\n");
    
    if (erros == 2)
        printf("  |   |\n");
    else if (erros == 3)
        printf(" /|   |\n");
    else if (erros >= 4)
        printf(" /|\\  |\n");
    else
        printf("      |\n");
    
    if (erros == 5)
        printf(" /    |\n");
    else if (erros >= 6)
        printf(" / \\  |\n");
    else
        printf("      |\n");
    
    printf("      |\n");
    printf("=========\n\n");
}

void mostrarPalavraEscondida(char* palavra, char* letrasUsadas) {
    int i, j, encontrado;
    for (i = 0; palavra[i] != '\0'; i++) {
        encontrado = 0;
        for (j = 0; letrasUsadas[j] != '\0'; j++) {
            if (toupper(palavra[i]) == letrasUsadas[j]) {
                encontrado = 1;
                break;
            }
        }
        if (encontrado)
            printf("%c ", palavra[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char palavra[MAX_PALAVRA + 1];
    char letrasUsadas[MAX_TENTATIVAS * 2]; // Armazena letras usadas e caracteres especiais
    
    int tentativas = 0, erros = 0, acertos = 0;
    int i;
    
    printf("Bem-vindo ao Jogo da Forca!\n");
    printf("Tente adivinhar a palavra secreta.\n");
    
    int tamanhoPalavra = escolherPalavra(palavra);
    
    for (i = 0; i < MAX_TENTATIVAS * 2; i++)
        letrasUsadas[i] = '\0';
    
    while (erros < MAX_TENTATIVAS && acertos < tamanhoPalavra) {
        printf("\n\n");
        printf("Letras usadas: %s\n", letrasUsadas);
        mostrarForca(erros);
        mostrarPalavraEscondida(palavra, letrasUsadas);
        
        char palpite;
        printf("Digite uma letra ou tente adivinhar a palavra: ");
        scanf(" %c", &palpite);
        limparBuffer();
        
        int jaUsada = 0;
        for (i = 0; letrasUsadas[i] != '\0'; i++) {
            if (toupper(palpite) == letrasUsadas[i]) {
                jaUsada = 1;
                break;
            }
        }
        if (jaUsada) {
            printf("Você já usou essa letra ou tentou essa palavra. Tente novamente.\n");
            continue;
        }
        
        letrasUsadas[strlen(letrasUsadas)] = toupper(palpite);
        letrasUsadas[strlen(letrasUsadas)] = ' ';
        
        if (strlen(&palpite) > 1) {
            if (strcmp(palavra, &palpite) == 0) {
                acertos = tamanhoPalavra;
                break;
            } else {
                erros++;
            }
        } else {
            int acertou = 0;
            for (i = 0; palavra[i] != '\0'; i++) {
                if (toupper(palpite) == palavra[i]) {
                    acertos++;
                    acertou = 1;
                }
            }
            if (!acertou)
                erros++;
        }
    }
    
    printf("\n\n");
    mostrarForca(erros);
    mostrarPalavraEscondida(palavra, letrasUsadas);
    
    if (acertos == tamanhoPalavra)
        printf("Parabéns! Você acertou a palavra secreta: %s\n", palavra);
    else
        printf("Você perdeu! A palavra secreta era: %s\n", palavra);
    
    return 0;
}
