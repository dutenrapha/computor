#include "../include/computor.h"

char* convertPolynomialFormat(const char* polynomial) {
    int len = strlen(polynomial);
    char* result = (char*)malloc((len * 2) * sizeof(char)); // Alocando mais espaço por precaução
    int resultIndex = 0;
    int isFirst = 1;

    for(int i = 0; i < len; i++) {
        if(polynomial[i] == ' ') continue; // Ignora espaços
        else if(polynomial[i] == '+' || polynomial[i] == '-') {
            if(!isFirst) result[resultIndex++] = ' '; // Adiciona espaço, se não for o primeiro caractere
            result[resultIndex++] = polynomial[i]; // Adiciona sinal
            // Não adiciona espaço após o sinal
            isFirst = 0;
        }
        else if(isdigit(polynomial[i]) || polynomial[i] == '.') {
            while(i < len && (isdigit(polynomial[i]) || polynomial[i] == '.')) {
                result[resultIndex++] = polynomial[i++]; // Adiciona coeficiente
            }
            result[resultIndex++] = ' '; // Adiciona espaço
            i--; // Devolve um passo
        }
        else if(polynomial[i] == '*') {
            result[resultIndex++] = ' '; // Adiciona espaço antes do '*'
            result[resultIndex++] = polynomial[i]; // Adiciona '*'
            result[resultIndex++] = ' '; // Adiciona espaço após o '*'
        }
        else if(polynomial[i] == 'X') {
            result[resultIndex++] = polynomial[i]; // Adiciona 'X'
        }
        else if(polynomial[i] == '^') {
            result[resultIndex++] = polynomial[i]; // Adiciona '^'
            while(i < len - 1 && isdigit(polynomial[i + 1])) {
                result[resultIndex++] = polynomial[++i]; // Adiciona expoente
            }
            if(i < len - 1) result[resultIndex++] = ' '; // Adiciona espaço se não for o final do polinômio
        }
    }

    result[resultIndex] = '\0'; // Finaliza a string
    return result;
}
