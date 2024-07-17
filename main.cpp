#include "jogoDeTabuleiro.hpp"
#include "lig4.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;

    Lig4 john = Lig4(a,b);
    john.imprimir_tabuleiro();

    return 0;
}