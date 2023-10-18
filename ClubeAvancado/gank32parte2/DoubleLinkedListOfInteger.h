

#include "Nodo.h"

#ifndef _LISTASE
#define _LISTASE

// ****************************
// Lista Duplamente Encadeada
class DoubleLinkedListOfInteger{
    // Referencia para o sentinela de inicio da lista encadeada.
    Nodo *header;
    // Referencia para o sentinela de fim da lista encadeada.
    Nodo *trailer;
    // Contador para a quantidade de elementos que a lista contem.
    int count;

    void recursivePrintBackToFront(Nodo* n);
public:
    DoubleLinkedListOfInteger();
    void ImprimeLista();
    bool isEmpty();
    int size();
    void clear();
    Nodo* getNodeIndex(int index);

    void add(int element);
    long int get(int index);
    long int set(int index, long int element);
    void add(int index, int element);
    bool remove(int element);
    int removeByIndex(int index);
    int indexOf(int element);
    bool contains(int element);
    int *subList(int fromIndex, int toIndex);
    void printBackToFront();
    void recursivePrintBackToFront();
    bool equals(DoubleLinkedListOfInteger *l);
    void addIncreasingOrder(int element);
    bool unique();
    void InsereNaDireita(Nodo *aux, int valor);
    int lastIndexOf(int element);
    int countOccurrences(int element);
    bool removeEvenNumbers();
    void rotacionaEsquerda(int N);
    void reverse();
    void reverseSubList(int fromIndex, int toIndex);
};
    DoubleLinkedListOfInteger getunique (DoubleLinkedListOfInteger lista1);

#endif
