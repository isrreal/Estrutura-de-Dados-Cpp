#include <iostream>
// insertion sort compara se a chave da posição 'j' é
// menor que os anteriores e troca de posição com todos os 
// valores do vetor até encontrar a posição correta

void insertionSort(int* array, size_t tamanho) {
    // percorre todo o vetor
    for (size_t i = 0; i < tamanho - 1; i++)
    // percorre na posicao seguinte em relação a "i" (por isso o "j = i + 1")
    // e decrementa para comparar com os elementos anteriores
        for (size_t j = i + 1; j > 0; --j)
        // comparando se o elemento na posição "j", que tambem é "i", é menor que o 
        // elemento anterior, se sim, entao ambos trocam de valores entre si  
            if (array[j] < array[j - 1]) {
                int aux = array[j];
                array[j] = array [j - 1];
                array[j - 1] = aux;
            }
}
void printar(int* array, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++) 
        std::cout << array[i] << " ";
}
int main() {
    int array[] = {1, 23, 534, 2, 5, 9, 2, -90};
    size_t tamanho = sizeof(array)/ sizeof(array[0]);
    insertionSort(array, tamanho);
    printar(array, tamanho);
}