#include "../include/computor.h"

char* convertPolynomialFormat(const char* polynomial) {
    int len = strlen(polynomial);
    char* result = (char*)malloc((len * 2) * sizeof(char));
    int resultIndex = 0;
    int isFirst = 1;

    for(int i = 0; i < len; i++) {
        if(polynomial[i] == ' ') continue;
        else if(polynomial[i] == '+' || polynomial[i] == '-') {
            if(!isFirst) result[resultIndex++] = ' ';
            result[resultIndex++] = polynomial[i];
            isFirst = 0;
        }
        else if(isdigit(polynomial[i]) || polynomial[i] == '.') {
            while(i < len && (isdigit(polynomial[i]) || polynomial[i] == '.')) {
                result[resultIndex++] = polynomial[i++];
            }
            result[resultIndex++] = ' ';
            i--;
        }
        else if(polynomial[i] == '*') {
            result[resultIndex++] = ' ';
            result[resultIndex++] = polynomial[i];
            result[resultIndex++] = ' ';
        }
        else if(polynomial[i] == 'X') {
            result[resultIndex++] = polynomial[i];
        }
        else if(polynomial[i] == '^') {
            result[resultIndex++] = polynomial[i];
            while(i < len - 1 && isdigit(polynomial[i + 1])) {
                result[resultIndex++] = polynomial[++i];
            }
            if(i < len - 1) result[resultIndex++] = ' ';
        }
    }

    result[resultIndex] = '\0';
    return result;
}
