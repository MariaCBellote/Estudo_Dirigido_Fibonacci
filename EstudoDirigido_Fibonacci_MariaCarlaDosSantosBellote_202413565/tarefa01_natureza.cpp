#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Prototipo da funcao
void verificarRazaoAurea(int limite);

int main() {
    verificarRazaoAurea(1000);
    return 0;
}

// Definicao da funcao
void verificarRazaoAurea(int limite) {
    long long f0 = 0, f1 = 1, f2;
    double razao;

    cout << fixed << setprecision(10);
    cout << "Sequencia de Fibonacci e razoes:\n";

    for (int i = 2; i <= limite; i++) {
        f2 = f0 + f1;

        razao = (double)f2 / f1;

        cout << "Fibonacci: " << f2
             << " | Razao: " << razao
             << " | Erro: "
             << abs(razao - (1.0 + sqrt(5.0)) / 2.0)
             << endl;

        f0 = f1;
        f1 = f2;

        if (f2 > limite - f1)
            break;
    }

    double phi = (1.0 + sqrt(5.0)) / 2.0;

    cout << "\nRazao aurea teorica: " << phi << endl;
}