#include <iostream>
#include <vector>
void swap(int& elemento, int& elemento2) {
    int temp = elemento;
    elemento = elemento2;
    elemento2 = temp;
}

int partition(std::vector<int>& vetor, int menor, int maior) {
    // selecionando o elemento pivô
    int pivot = vetor[maior];
    // índice do menor elemento
    int i = menor - 1;
    for (int j = menor; j <= maior - 1; j++) {
    // compara se o elemento é menor ou igual ao pivô 
        if (vetor[j] <= pivot) {
            // se o elemento for menor ou igual, o i incrementa 
            i++;
            // troca o índice de comparação pela posição atual 
            swap(vetor[i], vetor[j]);
        }
    }
    // troca a posiçao pelo último índice
    swap(vetor[i + 1], vetor[maior]);
    // retorna a posicao do array ordenado
    return i + 1;
}
void quickSort(std::vector<int>& vetor, int menor, int maior) {
    if (menor < maior) {
        int pi = partition(vetor, menor, maior);
        // faz o quicksort da parte esquerda do array
        quickSort(vetor, menor, pi - 1);
        // faz o quicksort da parte direita do array
        quickSort(vetor, pi + 1, maior);
    }
}

void printar(std::vector<int> vetor) {
    for (int it: vetor)
        std::cout << it << " ";
}
int main() {
    std::vector<int> vetor = {1, 9, 2, 6, -5, 2, 2};
    size_t tamanho = vetor.size();
    quickSort(vetor, 0, tamanho);
    printar(vetor);
}