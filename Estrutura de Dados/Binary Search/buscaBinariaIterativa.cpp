#include <iostream>
#include <vector>
int buscaBinariaIterativa(std::vector<int>& vetor, int numeroRequerido) {
    int inicio = 0;
    int fim = vetor.size() - 1;
    while (inicio < fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == numeroRequerido)
            return meio;
        // se for maior, então o número está na metade direita
        if (vetor[meio] < numeroRequerido) 
        // limita o inicio à metade direita
            inicio = meio + 1;
        // senão, está na metade esquerda 
        else
            // limita o fim ao meio
            fim = meio;
    }
    return -1;
}
int main() {    
    std::vector<int> vetor = {1, 3, 6, 8, 9, 890};
    int numeroRequerido = 0;
    std::cin >> numeroRequerido;
    int indiceElementoRequerido = buscaBinariaIterativa(vetor, numeroRequerido);
    std::cout << indiceElementoRequerido;
}