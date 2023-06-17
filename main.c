#include "include/computor.h"

int main(int argc, char *argv[]) 
{
    char *result[2]; // Array para armazenar os tokens divididos
    int maxTokens = 2;
    int tokenCount;
    int degree;
    Solution *solution;

    if(argc > 0)
    {

        tokenCount = split(argv[1], "=", result, maxTokens);
        if(tokenCount != 2)
        {
            return 0;
        }
        Polynomial polynomial1 = parsePolynomial(result[0]);
        Polynomial polynomial2 = parsePolynomial(result[1]);
        multiplyByScalar(&polynomial2, -1);
        Polynomial polynomial3 = addPolynomials(polynomial1, polynomial2);
        printPolynomial(&polynomial3);
        degree =  findPolynomialDegree(&polynomial3);
        printf("Polynomial degree %d\n", degree);
        if(degree == 1)
        {
            if (polynomial3.head->next == NULL)
            {
                solution = NULL;
            }
            else
            {
            solution = solveFirstDegreePolynomial(&polynomial3);
            }
            if(solution != NULL)
            {
                printf("The solution is: %f\n", solution->x1);
            }
            else
            {
                printf("Polynomial has infinite solutions.\n");
            }
        }
        if(degree == 2)
        {
            solution = solveQuadraticEquation(&polynomial3);
            if(solution == NULL)
            {
                printf("This polynomial equation does not have a solution in the set of real numbers.\n");
            }
            else if (solution->x1 == solution->x2)
            {
                printf("Discriminant is 0, the solution is:\n%f", solution->x1);
            }
            else
            {
                printf("Discriminant is strictly positive, the two solutions are:\n%f\n%f\n", solution->x1, solution->x2);
            }
        }
        if (degree > 2)
        {
            printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
        }
        freePolynomial(&polynomial1);
        freePolynomial(&polynomial2);
        freePolynomial(&polynomial3);
    }
    return 0;
}
