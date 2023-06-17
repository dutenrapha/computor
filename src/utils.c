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
        printf("Polynomial has infinite solutions.\n");
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



