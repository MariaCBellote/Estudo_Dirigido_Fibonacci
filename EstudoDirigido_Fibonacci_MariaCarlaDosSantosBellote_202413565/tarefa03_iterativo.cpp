#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;

long long fibonacciRecursivo(int n);
long long fibonacciIterativo(int n);

int main() {
    int valores[] = {10, 20, 30, 40};

    for (int n : valores) {
        cout << "\n===== n = " << n << " =====\n";

        // Mede o tempo da versao recursiva
        auto inicioRecursivo = high_resolution_clock::now();

        long long resultadoRecursivo = fibonacciRecursivo(n);

        auto fimRecursivo = high_resolution_clock::now();

        auto tempoRecursivo = duration_cast<microseconds>(
            fimRecursivo - inicioRecursivo
        ).count();

        // Mede o tempo da versao iterativa
        auto inicioIterativo = high_resolution_clock::now();

        long long resultadoIterativo = fibonacciIterativo(n);

        auto fimIterativo = high_resolution_clock::now();

        auto tempoIterativo = duration_cast<microseconds>(
            fimIterativo - inicioIterativo
        ).count();

        cout << "Resultado recursivo: " << resultadoRecursivo << endl;
        cout << "Tempo recursivo: " << tempoRecursivo
             << " microssegundos" << endl;

        cout << "Resultado iterativo: " << resultadoIterativo << endl;
        cout << "Tempo iterativo: " << tempoIterativo
             << " microssegundos" << endl;
    }

    return 0;
}

long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacciRecursivo(n - 1)
         + fibonacciRecursivo(n - 2);
}


long long fibonacciIterativo(int n){
    long long anterior = 0;
    long long atual = 1;
for(int i=2;i<=n;i++){
 if(n<=1){
    return n;
 }

long long proximo=anterior+atual;
anterior=atual;
atual=proximo;


}
return atual;
}
    // Calcula os termos do menor para o maior.
    // Tempo: O(n), pois o laco executa n-1 vezes.
    // Espaco auxiliar: O(1), pois utiliza apenas um numero
    // constante de variaveis, independentemente de n.
    //
    // Diferentemente da recursao, nao cria uma nova chamada
    // de funcao a cada termo. Portanto, nao acumula chamadas
    // na pilha de execucao nem precisa guardar os contextos
    // das chamadas anteriores.