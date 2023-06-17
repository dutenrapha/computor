#include "../include/computor.h"


int split(char *string, char *delimiter, char **result, int maxTokens) {
    int tokenCount = 0;
    char *token = strtok(string, delimiter); // Divide a string em tokens

    while (token != NULL && tokenCount < maxTokens) {
        result[tokenCount] = token; // Armazena o token no array resultante
        token = strtok(NULL, delimiter); // Obtém o próximo token
        tokenCount++;
    }

    return tokenCount; // Retorna o número de tokens encontrados
}