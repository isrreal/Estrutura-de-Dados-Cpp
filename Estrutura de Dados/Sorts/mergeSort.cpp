#include <iostream>
#include <vector>
void merge(std::vector<int>& vetor, int start, int mid, int end){
    // vetor auxiliar
    std::vector<int> vetorAuxiliar;
    vetorAuxiliar.resize(end - start + 1);
    int start1 = start;
    int start2 = mid + 1;
    // inicio do vetor auxiliar
    int start3 = 0;
    // compara as duas metades do vetor já existente
    while (start1 <= mid && start2 <= end){
        if(vetor[start1] <= vetor[start2])
            // vetor auxiliar recebe a posição
            vetorAuxiliar[start3++] = vetor[start1++];
        else
            vetorAuxiliar[start3++] = vetor[start2++];
    }
    // adiciona o vetor ja ordenado até a parte esquerda
    while (start1 <= mid)
        vetorAuxiliar[start3++] = vetor[start1++];
    // adiciona o valor ordenado da metade até o fim
    while(start2 <= end)
        vetorAuxiliar[start3++] = vetor[start2++];
    // igualando o vetor original com o auxiliar
    for (int i = start, j = 0; i <= end; i++, j++)
        vetor[i] = vetorAuxiliar[j];
}

void mergesort(std::vector <int> & A, int start, int end ){
    if(end > start){
        int mid = (start + end)/2;
        mergesort(A, start, mid);
               mergesort(A, mid+1, end);
               merge(A, start, mid, end );
    }
}

void printar(std::vector<int>& vetor) {
    for (auto i: vetor)
        std::cout << i << " ";
}

int main() {
    std::vector<int> A ({5,6,4,3,1,3,8,5,9});
    mergesort(A, 0, A.size() - 1);
    printar(A);
}

