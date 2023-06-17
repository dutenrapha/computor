#include "../include/computor.h"

Solution* solveFirstDegreePolynomial(Polynomial* polynomial) {
    Solution* solution = (Solution*)malloc(sizeof(Solution));
    Term* term = polynomial->head;
    float coefficient;

    coefficient = term->next->coefficient;
    if (coefficient == 0) {
        free(solution);
        return NULL;
    }
    solution->x1 = -term->coefficient / coefficient;
    return solution;
}



Solution* solveQuadraticEquation(Polynomial* polynomial)
{    
    float a;
    float b;
    float c;

    Solution* solution = (Solution*)malloc(sizeof(Solution));
    a = 0.0;
    b = 0.0;
    c = 0.0;
    Term* currentTerm = polynomial->head;
    while (currentTerm != NULL) {
        int exponent = currentTerm->exponent;
        float coefficient = currentTerm->coefficient;
        if (exponent == 2) {
            a += coefficient;
        } else if (exponent == 1) {
            b += coefficient;
        } else if (exponent == 0) {
            c += coefficient;
        }
        
        currentTerm = currentTerm->next;
    }
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        free(solution);
        return NULL;
    }
    solution->x1 = (-b + sqrt(discriminant)) / (2 * a);
    solution->x2 = (-b - sqrt(discriminant)) / (2 * a);
    return solution;
}