#include "../include/computor.h"


int split(char *string, char *delimiter, char **result, int maxTokens) {
    int tokenCount = 0;
    char *token = strtok(string, delimiter); 
    while (token != NULL && tokenCount < maxTokens) {
        result[tokenCount] = token;
        token = strtok(NULL, delimiter);
        tokenCount++;
    }

    return tokenCount;
}

void handleDegreeOne(Polynomial* polynomial) {
    Solution* solution;
    if (polynomial->head->next == NULL) {
        solution = NULL;
    } else {
        solution = solveFirstDegreePolynomial(polynomial);
    }
    if (solution != NULL) {
        printf("The solution is: %f\n", solution->x1);
    } else {
        if (polynomial->head->coefficient !=0)
        {
            printf("The solution is: 0.00000\n");
        }
        else
        {
        printf("Polynomial has infinite solutions.\n");
        }
    }
}

void handleDegreeTwo(Polynomial* polynomial) {
    Solution* solution = solveQuadraticEquation(polynomial);
    if (solution == NULL) {
        printf("This polynomial equation does not have a solution in the set of real numbers.\n");
    } else if (solution->x1 == solution->x2) {
        printf("Discriminant is 0, the solution is:\n%f\n", solution->x1);
    } else {
        printf("Discriminant is strictly positive, the two solutions are:\n%f\n%f\n", solution->x1, solution->x2);
    }
}

void handlePolynomial(Polynomial* polynomial) {
    int degree = findPolynomialDegree(polynomial);
    printf("Polynomial degree %d\n", degree);
    if (degree == 1) {
        handleDegreeOne(polynomial);
    } else if (degree == 2) {
        handleDegreeTwo(polynomial);
    } else if (degree > 2) {
        printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
    }
}

void removeZeroTerms(Polynomial* polynomial) {
    Term* current = polynomial->head;
    Term* previous = NULL;

    while (current != NULL) {
        if (current->coefficient == 0 && current->exponent > 1) {
            // Remover o termo atual
            if (previous == NULL) {
                // O termo atual é o primeiro da lista
                polynomial->head = current->next;
            } else {
                previous->next = current->next;
            }

            // Liberar a memória ocupada pelo termo removido
            Term* temp = current;
            current = current->next;
            free(temp);
        } else {
            previous = current;
            current = current->next;
        }
    }
}
