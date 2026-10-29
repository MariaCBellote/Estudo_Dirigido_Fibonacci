
#include <iostream>
#include "CalculadoraFibonacci.h"

int main() {
    CalculadoraFibonacci calculadora;
    int opcao;
    int n;

    do {
        std::cout << "\n=== Calculadora de Fibonacci ===\n";
        std::cout << "1 - Metodo recursivo\n";
        std::cout << "2 - Metodo iterativo\n";
        std::cout << "3 - Formula de Binet\n";
        std::cout << "4 - Comparar metodos\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "Entrada invalida.\n";
            return 1;
        }

        if (opcao == 0) {
            std::cout << "Programa encerrado.\n";
            break;
        }

        if (opcao < 1 || opcao > 4) {
            std::cout << "Opcao invalida.\n";
            continue;
        }

        std::cout << "Informe o valor de n (0 a 92): ";

        if (!(std::cin >> n)) {
            std::cout << "Entrada invalida.\n";
            return 1;
        }

        switch (opcao) {
            case 1: {
                long long resultado = calculadora.recursivo(n);

                if (resultado == -1) {
                    std::cout << "Valor invalido ou acima do "
                              << "limite recursivo (40).\n";
                } else {
                    std::cout << "Fibonacci(" << n << ") = "
                              << resultado << "\n";
                }
                break;
            }

            case 2: {
                long long resultado = calculadora.iterativo(n);

                if (resultado == -1) {
                    std::cout << "Valor invalido. Use n entre 0 e 92.\n";
                } else {
                    std::cout << "Fibonacci(" << n << ") = "
                              << resultado << "\n";
                }
                break;
            }

            case 3: {
                long long resultado = calculadora.binet(n);

                if (resultado == -1) {
                    std::cout << "Resultado impreciso ou valor invalido.\n";
                } else {
                    std::cout << "Fibonacci(" << n << ") = "
                              << resultado << "\n";
                }
                break;
            }

            case 4:
                calculadora.compararMetodos(n);
                break;
        }

    } while (true);

    return 0;
}
