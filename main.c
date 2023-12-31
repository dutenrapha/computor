#include "include/computor.h"

int main(int argc, char* argv[]) {
    char* result[2];
    int maxTokens = 2;
    int tokenCount;
    Polynomial polynomial1;
    Polynomial polynomial2;
    Polynomial polynomial3;

    if (argc == 2) {
        transformX(argv[1]);
        if (!isCharactersValid(argv[1]))
        {
            return(1);
        }
        if (!isExpoentValid(argv[1]))
        {
            return(1);
        }
        if (!isSignsValid(argv[1]))
        {
            return(1);
        }
        if (!isSignsPresent(argv[1]))
        {
            return(1);
        }
        tokenCount = split(argv[1], "=", result, maxTokens);
        if (tokenCount != 2) {
            return 0;
        }
        polynomial1 = parsePolynomial(result[0]);
        polynomial2 = parsePolynomial(result[1]);
        multiplyByScalar(&polynomial2, -1);
        polynomial3 = addPolynomials(polynomial1, polynomial2);
        removeZeroTerms(&polynomial3);
        int degree = findPolynomialDegree(&polynomial3);
        if (degree == 0)
        {
            if(polynomial3.head->coefficient !=0)
            {
                printf("FALSE\n");
            }
            else
            {
                printf("TRUE\n");
            }
            return (0);
        }
        printPolynomial(&polynomial3);
        handlePolynomial(&polynomial3);
        freePolynomial(&polynomial1);
        freePolynomial(&polynomial2);
        freePolynomial(&polynomial3);
    } else {
        printf("Error: The program needs the polynomial equation enclosed in quotes.\nE.g., ./computor \"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\"\n");
        return 1;
    }
    return 0;
}
