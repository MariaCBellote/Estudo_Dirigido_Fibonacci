
#pragma once

class CalculadoraFibonacci {
private:
    // Limites para evitar estouro e tempos excessivos.
    static constexpr int LIMITE_RECURSIVO = 40;
    static constexpr int LIMITE_FIBONACCI = 92;

public:
    // Construtor padrao.
    CalculadoraFibonacci() = default;

    long long recursivo(int n) const;
    long long iterativo(int n) const;
    long long binet(int n) const;

    void compararMetodos(int n) const;
};