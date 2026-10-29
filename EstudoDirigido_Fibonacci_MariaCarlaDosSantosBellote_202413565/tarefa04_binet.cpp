
#include <iostream>
#include <cmath>
#include <iomanip>

// Prototipos
long long fibonacciIterativo(int n);
long long fibonacciBinet(int n);
long long diferencaAbsoluta(long long a, long long b);

int main() {
    const int limite = 92;
    int primeiroErro = -1;

    std::cout << "Analise da precisao da formula de Binet\n\n";

    // Procura a primeira divergencia.
    for (int n = 0; n <= limite; n++) {
        long long referencia = fibonacciIterativo(n);
        long long binet = fibonacciBinet(n);

        if (referencia != binet) {
            primeiroErro = n;
            break;
        }
    }

    if (primeiroErro == -1) {
        std::cout << "Nenhuma divergencia encontrada ate n = "
                  << limite << ".\n";
        std::cout << "Exibindo os ultimos termos testados.\n\n";
    } else {
        std::cout << "Primeira divergencia encontrada em n = "
                  << primeiroErro << "\n\n";
    }

    // Define o intervalo que sera exibido.
    int inicio;
    int fim;

    if (primeiroErro != -1) {
        inicio = (primeiroErro > 3) ? primeiroErro - 3 : 0;
        fim = (primeiroErro + 5 <= limite)
                  ? primeiroErro + 5 : limite;
    } else {
        inicio = limite - 8;
        fim = limite;
    }

    // Exibe a tabela.
    std::cout << std::left
              << std::setw(5) << "n"
              << std::setw(24) << "Iterativo"
              << std::setw(24) << "Binet"
              << "Diferenca absoluta\n";

    for (int n = inicio; n <= fim; n++) {
        long long referencia = fibonacciIterativo(n);
        long long binet = fibonacciBinet(n);
        long long diferenca =
            diferencaAbsoluta(referencia, binet);

        std::cout << std::left
                  << std::setw(5) << n
                  << std::setw(24) << referencia
                  << std::setw(24) << binet
                  << diferenca;

        if (referencia != binet) {
            std::cout << "  <-- divergencia";
        }

        std::cout << '\n';
    }

    std::cout << "\nAnalise concluida.\n";

    return 0;
}

// Calcula Fibonacci iterativamente.
// Complexidade: O(n) em tempo e O(1) em espaco auxiliar.
long long fibonacciIterativo(int n) {
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

// Calcula Fibonacci pela formula de Binet usando double.
long long fibonacciBinet(int n) {
    const double raiz5 = std::sqrt(5.0);
    const double phi = (1.0 + raiz5) / 2.0;
    const double psi = (1.0 - raiz5) / 2.0;

    double resultado =
        (std::pow(phi, n) - std::pow(psi, n)) / raiz5;

    return std::llround(resultado);
}

// Calcula a diferenca absoluta entre dois valores.
long long diferencaAbsoluta(long long a, long long b) {
    return (a >= b) ? a - b : b - a;
}


/*
A precisao de double possui 53 bits significativos.
Como phi e psi envolvem sqrt(5), um numero irracional
que nao pode ser representado exatamente em binario,
as operacoes de ponto flutuante introduzem arredondamentos.

Conforme n aumenta, phi^n cresce e a distancia entre
numeros double representaveis tambem aumenta. Assim,
o erro numerico pode superar a margem de arredondamento
necessaria para recuperar o inteiro correto.

A funcao iterativa usa somas inteiras exatas neste intervalo,
servindo como referencia para a comparacao.


4.3 Análise do Ponto A (Ilusão da Complexidade O(1))

A fórmula de Binet calcula o número de Fibonacci por meio de potências, raízes quadradas e operações aritméticas. No C++, a função std::pow() é utilizada para calcular φⁿ e ψⁿ.

Embora a fórmula seja frequentemente considerada O(1), seu custo real depende da implementação das operações matemáticas, da arquitetura do computador e da precisão numérica utilizada. Com o tipo double, os valores são aproximados, podendo gerar erros de arredondamento para n maiores.

Para comparar Binet e a versão iterativa, são medidos os tempos de execução para n = 10, 20, 40, 60 e 70. Os resultados devem ser obtidos experimentalmente, pois variam conforme o computador e o compilador.

A versão de Binet executa uma quantidade fixa de operações matemáticas, enquanto a versão iterativa realiza O(n) operações. Entretanto, a versão iterativa pode ser mais rápida em determinados casos, pois utiliza operações simples e evita cálculos com ponto flutuante. Além disso, Binet pode apresentar resultados incorretos devido à perda de precisão.


4.4 Análise do Ponto C (Origem Algébrica)

A sequência de Fibonacci é definida pela recorrência:

Fₙ = Fₙ₋₁ + Fₙ₋₂

com F₀ = 0 e F₁ = 1.

Essa recorrência é linear porque os termos anteriores aparecem elevados à primeira potência, e homogênea porque não possui um termo independente adicional.

Para encontrar sua solução, considera-se Fₙ = rⁿ. Substituindo na recorrência:

rⁿ = rⁿ⁻¹ + rⁿ⁻²

Dividindo por rⁿ⁻², obtém-se:

r² = r + 1

Portanto, a equação característica é:

r² - r - 1 = 0

Resolvendo a equação, encontram-se as raízes:

φ = (1 + √5) / 2
ψ = (1 - √5) / 2

A solução geral é Fₙ = Aφⁿ + Bψⁿ. Aplicando as condições iniciais F₀ = 0 e F₁ = 1, determinam-se as constantes, resultando na fórmula de Binet:

Fₙ = (φⁿ - ψⁿ) / √5

A mesma fórmula pode ser obtida pela diagonalização da matriz de Fibonacci:

A = [[1, 1], [1, 0]]

A diagonalização representa a matriz como A = PDP⁻¹, em que D contém seus autovalores, φ e ψ. Assim, calcular Aⁿ torna-se mais simples, pois basta elevar os elementos da matriz diagonal à potência n. O desenvolvimento resulta na mesma fórmula de Binet, demonstrando a relação entre recorrências, matrizes e álgebra linear.

*/