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

bool isCharactersValid(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!(c >= '0' && c <= '9') && c != '+' && c != '-' && c != '=' && c != 'X' && c != '^' && c != ' '&& c != '.'&& c != '*') {
            printf("Error: The string '%s' is invalid due to the presence of invalid characters.\n", str);
            printf("The valid characters are floating-point numbers, the plus sign (+), the minus sign (-),\n");
            printf("the multiplication sign (*), the equality sign (=), the variable symbol (X), and the exponentiation symbol (^).\n");
            return false;
        }
    }
    return true;
}

bool isSignsValid(const char* str) {
    int length = strlen(str);
    bool isValid = true;
    bool prevSign = false;
    
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            continue;  // Ignora espaços e tabulações
        }
        
        if (str[i] == '+' || str[i] == '-') {
            if (prevSign) {
                isValid = false;  // Sinal consecutivo encontrado
                break;
            }
            prevSign = true;
        } else {
            prevSign = false;
        }
    }
    if (!isValid)
    {
        printf("Error:Invalid equation, two consecutive signs\n");
    }
    return isValid;
}

bool isSignsPresent(const char* str) {
    bool found_caret = false;
    bool found_number = false;
    bool found_equals = false;
    bool found_sign = false;
    int i = 0;
    char c;

    while((c = str[i]) != '\0') {
        if (c == '^') {
            found_caret = true;
        } else if (found_caret && isdigit(c)) {
            found_number = true;
        } else if (found_caret && found_number && (c == ' ' || c == '\t')) {
            // ignore spaces or tabs after number
        } else if (found_caret && found_number && (c == '+' || c == '-')) {
            found_sign = true;
        } else if (found_caret && found_number && c == '=') {
            if (found_equals) {
                printf("Error:Invalid equation, more than one '=' found\n");
                return false;
            } else {
                found_equals = true;
                found_sign = true;
            }
        } else if (found_caret && found_number && !isspace(c)) {
            if (!found_sign) {
                printf("Error:Invalid equation, no signs between two terms\n");
                return false;
            }
            found_caret = false;
            found_number = false;
            found_sign = false;
        }
        i++;
    }

    return true;
}


void transformX(char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == 'x') {
            str[i] = 'X';
        }
    }
}