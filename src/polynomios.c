
#include "../include/computor.h"

static Term* parseTerm(char** polynomial) {
    if (!polynomial || !(*polynomial) || strlen(*polynomial) == 0) {
        return NULL;
    }

    float coefficient;
    int exponent;
    char var;

    // Tenta extrair o coeficiente, a variável e o expoente do início da string.
    int scanned = sscanf(*polynomial, "%f * %c^%d", &coefficient, &var, &exponent);
    if(scanned != 3) {
        return NULL;
    }

    // Cria um novo termo.
    Term* newTerm = (Term*) malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    // Encontra o final do termo atual na string.
    char* endTerm = strstr(*polynomial, " * X^");
    if (endTerm) {
        endTerm += strlen(" * X^");  // Pula para o final do termo.
        while (*endTerm && *endTerm != '+' && *endTerm != '-') {  
            endTerm++;  // Procura pelo início do próximo termo ou pelo final da string.
        }
    }

    // Atualiza a string do polinômio para apontar para o início do próximo termo.
    *polynomial = endTerm;

    return newTerm;
}

Polynomial parsePolynomial(char* argv[]) {
    Polynomial polynomial;
    polynomial.head = NULL;

    while (strlen(argv[1]) != 0) {
        Term* term = (Term*)malloc(sizeof(Term));
        term = parseTerm(&argv[1]);
        if (term == NULL)
        {
            break;
        }
        term->next = NULL;
        if (polynomial.head == NULL) {
            polynomial.head = term;
        } else {
            Term* current = polynomial.head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = term;
        }
    }

    return polynomial;
}

void printPolynomial(const Polynomial* polynomial) {
    const Term* current = polynomial->head;

    while (current != NULL) {
        printf("%.1f * X^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(Polynomial* polynomial) {
    Term* current = polynomial->head;
    while (current != NULL) {
        Term* next = current->next;
        free(current);
        current = next;
    }
    polynomial->head = NULL;
}