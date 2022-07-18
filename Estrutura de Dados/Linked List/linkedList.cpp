#include <iostream>
class Node {
private:
    int valor;
    Node* next;
public:
    Node(int valor): valor(valor), next(nullptr) {}
    Node(int valor, Node* ponteiroProx) {
        this->valor = valor;
        this->next = ponteiroProx;
    }
    int getValor() { return this->valor; }
    Node* getNext() { return this->next; }
    Node* setNext(Node* novoNo) { return (this->next = novoNo); }
};
class ListaEncadeada {
private:
    Node* head;
    Node* tail;
public:
    ListaEncadeada() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    ListaEncadeada(int valor) {
        this->head = new Node(valor);
        this->tail = head;
    }
    bool empty() { return this->head == nullptr; }
    void push_front(int valor) {
        // criar um node Auxiliar para inserir na frente
        Node* aux = new Node(valor);
        if (empty()) {
            this->head = aux;
            this->tail = aux;
        }
        else {
            // faz o novo Node receber o ponteiro de head,
            // assim, tornando-se o primeiro elemento
            aux->setNext(head);
            head = aux;
        }
    }
    void push_back(int valor) {
        Node* aux = new Node(valor);
        // se não tiver elementos, head e tail são iguais
        if (empty()) {
            head = aux;
            tail = aux;
        }
        else {
            // o novo Node agora será o tail, pois agora ele é o último elemento
            tail->setNext(aux);
            tail = aux;
        }
    }
    void pop_back() {
        if (!empty()) {
            if (head->getNext() == nullptr)
                head = nullptr;
            else {
                // anterior_anterior é igual a head 
                Node* anterior_anterior = head;
                // anterior recebe o próximo elemento em relação a "anterior_anterior" 
                Node* anterior = head->getNext();
                // serve como um interceptador do último elemento
                // já que precisa de pelo menos dois nós para realizarem as operações
                Node* iterator = head->getNext()->getNext();
                // itera até iterator ser nullptr
                while (iterator) {
                    Node* aux = anterior;
                    anterior = iterator;
                    anterior_anterior = aux;
                    // iterando para não ficar um loop infinito
                    iterator = iterator->getNext();
                }
                // desalocando o próximo elemento
                delete anterior_anterior->getNext();
                // setando para nullptr
                anterior_anterior->setNext(nullptr);
                // faz a cauda ser o nó "anterior_anterior"
                tail = anterior_anterior;
            }
        }
    }
    void remove(int value) {
        Node* iterator = head;
        // enquanto iterator não for nullptr
        while(iterator) {
            if (iterator->getValor() == value) {
                Node* removido = iterator;
                head = iterator->getNext();
                delete removido;
                iterator = iterator->getNext();
            }  
            else if (iterator->getNext() != nullptr &&
                     iterator->getNext()->getValor() == value) {
                Node* removido = iterator->getNext();
                iterator->setNext(removido->getNext());
                iterator = iterator->getNext();
                delete removido;
            }
            else
                iterator = iterator->getNext();
        }
    }
    void printar() {
        // cria um Nó auxiliar para iterar de Head até Tail
        Node* iterator = head;
        if (empty())
            std::cout << "Lista vazia!" << std::endl;
        else {
            while (iterator) {
                std::cout << iterator->getValor() << " ";
                iterator = iterator->getNext();
            }
            std::cout << std::endl;
        }
    }
    
    int getTamanho() {
        if (empty())
            return 0;
        Node* iterator = head;
        int tamanho = 0;
        // vai verificando até que seja nullptr
        while(iterator) {
            // vai navegando entre os ponteiros para o próxim elemento
            iterator = iterator->getNext();
            ++tamanho;
        }
        return tamanho;
    }
};

int main() {
    ListaEncadeada* lista = new ListaEncadeada(1);
    lista->push_back(2);
    lista->push_back(3);
    lista->push_front(-900);
    lista->printar();
    lista->remove(2);
    lista->printar();
    lista->remove(1);
    lista->printar();
    lista->remove(-900);
    lista->printar();
}