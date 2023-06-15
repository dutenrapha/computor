#include "include/computor.h"

int main(int argc, char *argv[]) 
{
    if(argc > 0)
    {
        Polynomial polynomial = parsePolynomial(argv);
        printPolynomial(&polynomial);
        freePolynomial(&polynomial);
    }
    return 0;
}
