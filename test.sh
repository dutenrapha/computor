#!/bin/bash

# Função para imprimir em verde
print_green() {
    printf "\e[32m$1\e[0m\n"
}

# Função para imprimir em vermelho
print_red() {
    printf "\e[31m$1\e[0m\n"
}

# Array com as equações
equations=("42*X^1 = 42*X^1" "4*X^1 - 5*X^0 = 15*X^0" "1*X^2 - 3*X^1 + 2*X^0 = 0*X^0" "1 * X^2 = - 1 * X^0" "1*X^3 - 6*X^2 + 11*X^1 - 6*X^0 = 0*X^0" "1*X^3 - 6*X^2 + 11*X^1 - 6*X^0 = 0*X ^  / 0")
# Array com as soluções correspondentes
solutions=("Polynomial has infinite solutions." "X = 5" "X = 2, X = 1" "This polynomial equation does not have a solution in the set of real numbers." "The polynomial degree is strictly greater than 2, I can't solve." "Error: ...")

# Loop para executar o programa com cada equação
for i in ${!equations[@]}
do
    # Imprimir o comando que será executado
    echo "./computor \"${equations[$i]}\""
    
    # Executar o programa com a equação atual e guardar o resultado
    IFS=$'\n' read -d '' -r -a lines < <(./computor "${equations[$i]}" && printf '\0')

    # Check if this is the third case, if so, print the second last line in red as well
    if [ $i -eq 2 ]; then
        for (( j=0; j < ${#lines[@]} - 2; j++ ))
        do
            print_green "${lines[$j]}"
        done
        # Print the second last line in red
        print_red "${lines[-2]}"
    else
        for (( j=0; j < ${#lines[@]} - 1; j++ ))
        do
            print_green "${lines[$j]}"
        done
    fi

    # Imprimir a última linha do resultado obtido pelo programa em vermelho
    print_red "${lines[-1]}"

    # Imprimir a solução que foi gerada em vermelho
    print_red "Expected: ${solutions[$i]}"

    # Pular uma linha
    echo
done
