
#include "CalculadoraFibonacci.h"

#include <iostream>
#include <cmath>
#include <iomanip>

// Metodo recursivo classico.
long long CalculadoraFibonacci::recursivo(int n) const {
    if (n < 0 || n > LIMITE_RECURSIVO) {
        return -1;
    }

    if (n <= 1) {
        return n;
    }

    return recursivo(n - 1) + recursivo(n - 2);
}

// Metodo iterativo.
long long CalculadoraFibonacci::iterativo(int n) const {
    if (n < 0 || n > LIMITE_FIBONACCI) {
        return -1;
    }

    if (n <= 1) {
        return n;
    }

    long long anterior = 0;
    long long atual = 1;

    for (int i = 2; i <= n; i++) {
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return atual;
}

// Formula de Binet com verificacao de precisao.
long long CalculadoraFibonacci::binet(int n) const {
    if (n < 0 || n > LIMITE_FIBONACCI) {
        return -1;
    }

    const double raiz5 = std::sqrt(5.0);
    const double phi = (1.0 + raiz5) / 2.0;
    const double psi = (1.0 - raiz5) / 2.0;

    const double resultado =
        (std::pow(phi, n) - std::pow(psi, n)) / raiz5;

    if (!std::isfinite(resultado)) {
        return -1;
    }

    const long long arredondado = std::llround(resultado);
    const long long referencia = iterativo(n);

    // Retorna -1 se Binet nao produzir o termo exato.
    if (arredondado != referencia) {
        return -1;
    }

    return arredondado;
}

// Compara os tres metodos.
void CalculadoraFibonacci::compararMetodos(int n) const {
    if (n < 0 || n > LIMITE_FIBONACCI) {
        std::cout << "Valor invalido. Use n entre 0 e "
                  << LIMITE_FIBONACCI << ".\n";
        return;
    }

    std::cout << "\nComparacao para n = " << n << "\n\n";

    std::cout << std::left
              << std::setw(20) << "Metodo"
              << std::setw(25) << "Resultado"
              << "Situacao\n";

    std::cout << std::string(60, '-') << "\n";

    // Recursivo.
    std::cout << std::left << std::setw(20) << "Recursivo";

    if (n <= LIMITE_RECURSIVO) {
        std::cout << std::setw(25) << recursivo(n)
                  << "Calculado\n";
    } else {
        std::cout << std::setw(25) << "Nao calculado"
                  << "Limite recursivo excedido\n";
    }

    // Iterativo.
    std::cout << std::left
              << std::setw(20) << "Iterativo"
              << std::setw(25) << iterativo(n)
              << "Calculado\n";

    // Binet.
    const long long resultadoBinet = binet(n);

    std::cout << std::left << std::setw(20) << "Binet";

    if (resultadoBinet == -1) {
        std::cout << std::setw(25) << "Indisponivel"
                  << "Resultado impreciso ou invalido\n";
    } else {
        std::cout << std::setw(25) << resultadoBinet
                  << "Resultado exato\n";
    }

    std::cout << "\n";
}
