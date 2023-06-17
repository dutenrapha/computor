#include "include/computor.h"

int main(int argc, char *argv[]) 
{
    char *result[2]; // Array para armazenar os tokens divididos
    int maxTokens = 2;
    int tokenCount;

    if(argc > 0)
    {

        tokenCount = split(argv[1], "=", result, maxTokens);
        if(tokenCount != 2)
        {
            return 0;
        }
        Polynomial polynomial1 = parsePolynomial(result[0]);
        printPolynomial(&polynomial1);
        Polynomial polynomial2 = parsePolynomial(result[1]);
        printPolynomial(&polynomial2);
        Polynomial polynomial3 = addPolynomials(polynomial1, polynomial2);
        printPolynomial(&polynomial3);
        freePolynomial(&polynomial1);
        freePolynomial(&polynomial2);
        freePolynomial(&polynomial3);
    }
    return 0;
}
