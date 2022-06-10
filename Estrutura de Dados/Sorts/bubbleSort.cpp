#include <iostream>
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// Bubble sort roda o loop 'N' vezes e compara se o
// vetor na posição 'j' é maior que o próximo, se for, ambos trocam de valores
void bubbleSort(int* array, size_t tamanho) {
    // loop para percorrer o vetor 'tamanho' vezes
    for (size_t i = 0; i < tamanho; i++)
    //  loop para fazer a comparação em si
        for(size_t j = 0; j < tamanho - 1; j++)
            // se for maior, troca
            if(array[j] > array[j + 1]) 
                swap(&array[j], &array[j + 1]);
}
void printar(int* vetor, size_t tamanho) {
    for(size_t i = 0; i < tamanho; i++)
        std::cout << vetor[i] << " ";
}
int main() {
    size_t tamanho;
    std::cin >> tamanho;
    int vetor[tamanho];
    for (size_t i = 0; i < tamanho; i++)
        std::cin >> vetor[i];
    bubbleSort(vetor, tamanho);
    printar(vetor, tamanho);
}