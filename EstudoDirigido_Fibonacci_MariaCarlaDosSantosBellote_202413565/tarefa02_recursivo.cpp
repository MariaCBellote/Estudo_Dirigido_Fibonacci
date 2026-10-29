#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long long fibonacciRecursivo(int n);
int contador =0;

int main() {
    int valores[] = {10, 20, 30, 40};

    for (int n : valores) {
        contador = 0;

        long long resultado = fibonacciRecursivo(n);

        cout << "Fibonacci(" << n << ") = " << resultado << endl;
        cout << "Casos base atingidos: "
             << contador << endl;
        cout << "--------------------------" << endl;
    }
}

long long fibonacciRecursivo(int n){
    if(n==0 ||n==1){
        contador++;
        return n;
    }
    // A função chama a si mesma duas vezes.
    // Complexidade: O(2^n), pois o número de chamadas
    // cresce exponencialmente com n devido às chamadas
    // repetidas dos mesmos subproblemas.
    return fibonacciRecursivo(n-2)+fibonacciRecursivo(n-1);
}