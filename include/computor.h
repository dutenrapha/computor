#ifndef COMPUTOR_H
# define COMPUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Term {
    float coefficient;
    int exponent;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* head;
} Polynomial;

void sortPolynomial(Polynomial* polynomial);
Polynomial addPolynomials(Polynomial p1, Polynomial p2);
int split(char *string, char *delimiter, char **result, int maxTokens);
Polynomial parsePolynomial(char* str);
void printPolynomial(const Polynomial* polynomial);
void freePolynomial(Polynomial* polynomial);
char* convertPolynomialFormat(const char* polynomial);
#endif