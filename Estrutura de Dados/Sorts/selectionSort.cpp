#include <iostream>
#include <vector>
void swap(int& maior, int& menor) {
    int aux = maior;
    maior = menor;
    menor = aux; 
}
// Selection sort seleciona uma posição específica do vetor e compara se os elementos 
// seguintes sao menores, caso forem, ambos trocam de posição.
void selectionSort(std::vector<int>& array, size_t tamanhoDoVetor) {
    int posicaoDoMenorElemento;
    // percorrendo o vetor
    for (size_t i = 0; i < tamanhoDoVetor - 1; i++) {
        // fazendo com que a posição do menor elemento seja o da posição i
        posicaoDoMenorElemento = i;
        // analisando se o próximo valor em relação a i seja menor
        for (size_t j = i + 1; j < tamanhoDoVetor; j++)
        // se for, o próximo elemento for menor, troca
            if (array[j] < array[posicaoDoMenorElemento])
                posicaoDoMenorElemento = j;
        // colocando na posicao correta  
        swap(array[i], array[posicaoDoMenorElemento]);
    }
}

void printar(std::vector<int>& array, int size)  {
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> vetor = {9999, 2, 20, 9, 33, 6, 2};
    size_t tamanhoDoVetor = vetor.size();
    selectionSort(vetor, tamanhoDoVetor);
    printar(vetor, tamanhoDoVetor); 
}