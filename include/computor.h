#ifndef COMPUTOR_H
# define COMPUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Term {
    float coefficient;
    int exponent;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* head;
} Polynomial;

Polynomial parsePolynomial(char* argv[]);
void printPolynomial(const Polynomial* polynomial);
void freePolynomial(Polynomial* polynomial);
#endif