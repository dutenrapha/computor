#ifndef COMPUTOR_H
# define COMPUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct Term {
    float coefficient;
    int exponent;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* head;
} Polynomial;

typedef struct {
    float x1;
    float x2;
} Solution;

void transformX(char* str);
bool isSignsPresent(const char* str);
bool isSignsValid(const char* str);
bool isCharactersValid(const char* str);
void handleDegreeOne(Polynomial* polynomial);
void handleDegreeTwo(Polynomial* polynomial);
void handlePolynomial(Polynomial* polynomial);
Solution* solveQuadraticEquation(Polynomial* polynomial);
int findPolynomialDegree(Polynomial* polynomial);
Solution* solveFirstDegreePolynomial(Polynomial* polynomial);
void multiplyByScalar(Polynomial* polynomial, float scalar);
void sortPolynomial(Polynomial* polynomial);
Polynomial addPolynomials(Polynomial p1, Polynomial p2);
int split(char *string, char *delimiter, char **result, int maxTokens);
Polynomial parsePolynomial(char* str);
void printPolynomial(const Polynomial* polynomial);
void freePolynomial(Polynomial* polynomial);
char* convertPolynomialFormat(const char* polynomial);
#endif