
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

Polynomial parsePolynomial(char* str) {
    Polynomial polynomial;
    polynomial.head = NULL;

    str = convertPolynomialFormat(str);
    while (strlen(str) != 0) {
        Term* term = (Term*)malloc(sizeof(Term));
        term = parseTerm(&str);
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
    sortPolynomial(&polynomial);
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


static Term* createTerm(float coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.head = NULL;

    Term* current1 = p1.head;
    Term* current2 = p2.head;
    Term* currentResult = NULL;

    while (current1 != NULL || current2 != NULL) {
        Term* newTerm = NULL;

        if (current1 == NULL) {
            newTerm = createTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else if (current2 == NULL) {
            newTerm = createTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else {
            if (current1->exponent > current2->exponent) {
                newTerm = createTerm(current2->coefficient, current2->exponent);
                current2 = current2->next;
            } else if (current2->exponent > current1->exponent) {
                newTerm = createTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            } else {
                newTerm = createTerm(current1->coefficient + current2->coefficient, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            }
        }

        if (result.head == NULL || newTerm->exponent > result.head->exponent) {
            newTerm->next = result.head;
            result.head = newTerm;
        } else {
            currentResult = result.head;
            while (currentResult->next != NULL && currentResult->next->exponent > newTerm->exponent) {
                currentResult = currentResult->next;
            }
            newTerm->next = currentResult->next;
            currentResult->next = newTerm;
        }
    }
    sortPolynomial(&result);
    return result;
}


void insertTerm(Polynomial* polynomial, float coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    if (polynomial->head == NULL) {
        polynomial->head = newTerm;
    } else {
        Term* current = polynomial->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void sortPolynomial(Polynomial* polynomial) {
    if (polynomial->head == NULL) {
        insertTerm(polynomial, 0.0, 0);
        return;
    }

    int swapped;
    Term* ptr1;
    Term* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = polynomial->head;

        while (ptr1->next != lptr) {
            if (ptr1->exponent > ptr1->next->exponent) {
                float tempCoefficient = ptr1->coefficient;
                int tempExponent = ptr1->exponent;
                ptr1->coefficient = ptr1->next->coefficient;
                ptr1->exponent = ptr1->next->exponent;
                ptr1->next->coefficient = tempCoefficient;
                ptr1->next->exponent = tempExponent;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void multiplyByScalar(Polynomial* polynomial, float scalar) {
    Term* currentTerm = polynomial->head;
    
    while (currentTerm != NULL) {
        currentTerm->coefficient *= scalar;
        currentTerm = currentTerm->next;
    }
}
