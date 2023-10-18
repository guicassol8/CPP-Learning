#include <iostream>
#include <sstream>
using namespace std;

#include "DoubleLinkedListOfInteger.h"

#define IndexOutOfBoundsException 0

/**
 * Construtor da lista.
 */
DoubleLinkedListOfInteger::DoubleLinkedListOfInteger(){
    header = new Nodo(0);
    trailer = new Nodo(0);
    header->next = trailer;
    trailer->prev = header;
    count = 0;
}

/**
 * Impressão da lista.
 */
void DoubleLinkedListOfInteger::ImprimeLista() {
    Nodo *ptr;
    if (count == 0) {
    // Lista Vazia  
        printf("List: []\n");
        return;
    }
    // Caso a lista nao esteja vazia
    ptr = header->next;
    printf("List: [");
    while (true){
        cout << ptr->element << "";
        ptr = ptr->next;
        if (ptr==trailer){
            cout << "]"<<endl;
            break;
        } else{
            cout<<"; ";
        }
    }
}

/**
 * Retorna true se a lista nao contem elementos.
 * @return true se a lista nao contem elementos
 */
bool DoubleLinkedListOfInteger::isEmpty() {
    return (count == 0);
}

/**
 * Retorna o numero de elementos da lista.
 * @return o numero de elementos da lista
 */
int DoubleLinkedListOfInteger::size() {
    return count;
}

/**
 * Esvazia a lista
 */
void DoubleLinkedListOfInteger::clear() {
    Nodo *ptr;
    if (count == 0) {
      // Lista já estava Vazia
      return;
    }
    // Caso a lista nao esteja vazia
    // Apaga cada elemento
    ptr = header->next;
    Nodo *aux;
    while (true) {
        cout << "Apagando " << ptr->element << endl;
        aux = ptr;
        ptr = ptr->next;
        delete aux;
        if (ptr==trailer)
            break;
    }
    header->next = trailer;
    trailer->prev = header;
    count = 0;
}

/**
 * Adiciona um elemento ao final da lista.
 * @param element elemento a ser adicionado ao final da lista
 */
void DoubleLinkedListOfInteger::add(int element) {
    Nodo *novo = new Nodo(element); // cria um novo objeto Nodo, mantendo a referencia à ele em "novo"

    novo->next = trailer; // faz o novo nodo apontar para o nodo sentinela
    novo->prev = trailer->prev; // faz o novo nodo apontar para o ultimo elemento da lista

    novo->prev->next = novo; // faz o ultimo nodo apontar para o novo nodo
    novo->next->prev = novo; // faz o nodo sentinela apontar para o novo nodo
    
    count++;
    return;
}

 /* Retorna a referência ao nodo que está em uma determinada posicao da lista. */
Nodo* DoubleLinkedListOfInteger::getNodeIndex(int index){
    if ((index < 0) || (index >= count)) {
        throw IndexOutOfBoundsException;
    }
    Nodo *ptr;
    if(index > (count/2)){
        ptr = trailer->prev; // aponta para o último elemento da lista
        // retorcede até chegar na posição desejada
        for(int i = count-1; i > index; i--){
            ptr = ptr->prev;
        }
    } else{
        ptr = header->next; // aponta para o primeiro elemento da lista
        // avança até chegar na posição desejada
        for(int i = 0; i < index; i++){
            ptr = ptr->next;
        }
    }
    return ptr;
}

/**
 * Retorna o elemento de uma determinada posicao da lista.
 * @param index a posição da lista
 * @return o elemento da posicao especificada
 * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
 */
long int DoubleLinkedListOfInteger::get(int index) {
    if ((index < 0) || (index >= count)) {
        throw IndexOutOfBoundsException;
    }
    
    Nodo *ptr = getNodeIndex(index);
    return ptr->element;
}

/**
 * Insere um elemento em uma determinada posicao da lista.
 * @param index a posicao da lista onde o elemento sera inserido
 * @param element elemento a ser inserido
 * @throws IndexOutOfBoundsException se (index < 0 || index > size())
 */
void DoubleLinkedListOfInteger::add(int index, int element) {
    if ((index < 0) || (index >= count)) {
        throw IndexOutOfBoundsException;
    }
    Nodo *ptr = getNodeIndex(index);
    Nodo *novo = new Nodo(element);

    // faz o novo nodo apontar para os nodos antigos da lista
    novo->next = ptr;
    novo->prev = ptr->prev;

    // faz os nodos antigos apontarem para o novo nodo
    novo->prev->next = novo;
    novo->next->prev = novo;
    
    count++;
    return;
}

/**
 * Substitui o elemento armazenado em uma determinada posicao da lista pelo elemento indicado.
 * @param index a posicao na lista
 * @param element o elemento a ser armazenado na lista
 * @return o elemento armazenado anteriormente na posicao da lista
 * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
 */
long int DoubleLinkedListOfInteger::set(int index, long int element) {
    if ((index < 0) || (index >= count)) {
        throw IndexOutOfBoundsException;
    }
    Nodo *ptr = getNodeIndex(index); // pega a referencia ao nodo na posicao index
    int retorno = ptr->element; // salva o valor atual para retornar
    ptr->element = element; // faz o set no nodo
    return retorno;
}

/**
  * Remove o elemento de uma determinada posicao da lista.
  * @param index a posicao da lista
  * @return o elemento que foi removido da lista
  * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
  */
int DoubleLinkedListOfInteger::removeByIndex(int index) {
    if ((index < 0) || (index >= count)) {
        throw IndexOutOfBoundsException;
    }
    Nodo *ptr = getNodeIndex(index);
    int retorno = ptr->element;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
    count--;
    return retorno;
}

/**
 * Remove a primeira ocorrencia do elemento na lista, se estiver presente.
 * @param element o elemento a ser removido
 * @return true se a lista contem o elemento especificado
 */
bool DoubleLinkedListOfInteger::remove(int element) {
    // retorna false se a lista estiver vazia
    if (count == 0)
        return false;

    Nodo *ptr = header->next; // aponta para o primeiro elemento da lista
    for(int i = 0; i < count; i++){
        if(ptr->element == element){
            removeByIndex(i);
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

/**
 * Retorna o indice da primeira ocorrencia do elemento na lista, ou -1 se a
 * lista nao contem o elemento.
 * @param element o elemento a ser buscado
 * @return o indice da primeira ocorrencia do elemento na lista, ou -1 se a
 * lista nao contem o elemento
 */
int DoubleLinkedListOfInteger::indexOf(int element) {
    Nodo *ptr = header->next;
    // avança na lista comparando o element com os elementos armazenados em cada nodo
    // se encontrar, retorna o index (i) atual 
    for(int i = 0; i < count; i++){
        if(element == ptr->element)
            return i;
        ptr = ptr->next;
    }
    return -1;
}

/**
 * Retorna true se a lista contem o elemento especificado.
 * @param element o elemento a ser testado
 * @return true se a lista contem o elemento especificado
 */
bool DoubleLinkedListOfInteger::contains(int element) {
    if (isEmpty())
        return false;  // Lista Vazia

    // utiliza o método anterior para verificar se o element está na lista
    if(indexOf(element) == -1)
        return false;
    else
        return true;
}

/**
 * Retorna um arranjo com os elementos da lista original entre
 * fromIndex (inclusivo) e toIndex (exclusivo).
 * @param fromIndex posicao a partir da qual os elementos serao inseridos no
 * arranjo a ser retornado
 * @param toIndex indica a posicao final dos elementos que devem ser
 * inseridos
 * @return Um arranjo com um subconjunto dos elementos da lista.
 * @throws IndexOutOfBoundsException se (fromIndex < 0 || toIndex > size())
 * @throws IllegalArgumentException se (fromIndex > toIndex)
  */
int* DoubleLinkedListOfInteger::subList(int fromIndex, int toIndex) {
    // Primeiro verifica se os indices sao validos
    if (fromIndex < 0 || toIndex > size() || fromIndex >= toIndex) {
        cout << "Indices invalidos!" << endl;
        throw IndexOutOfBoundsException;
    }

    int *vector = new int[toIndex-fromIndex];
    Nodo *ptr = getNodeIndex(fromIndex);
    for(int i = 0; i < (toIndex-fromIndex); i++){
        vector[i] = ptr->element;
        ptr = ptr->next;
    }

    return vector;
}


void DoubleLinkedListOfInteger::printBackToFront(){
    Nodo *ptr = trailer->prev;
    printf("Reversed: [");
    for(int i = 0; i < count; i++){
        cout << ptr->element;
        if(i != count-1)
            printf("; ");
        ptr = ptr->prev;
    }
    printf("]\n");
    return;
}

void DoubleLinkedListOfInteger::recursivePrintBackToFront(){
    recursivePrintBackToFront(trailer->prev);
}  

void DoubleLinkedListOfInteger::recursivePrintBackToFront(Nodo* n){
    if(n->next == trailer){
        printf("Reversed: [");
    }
    if(n != header){
        cout << n->element;
        if(n->prev != header)
            printf("; ");
    }
    if(n == header){
        printf("]\n");
        return;
    }
    recursivePrintBackToFront(n->prev);
    return;
}

bool DoubleLinkedListOfInteger::equals(DoubleLinkedListOfInteger *l){
    if (this->size() != l->size())
        return false;
    
    Nodo *ptr1, *ptr2;
    ptr1 = header->next;
    ptr2 = l->getNodeIndex(0);
    for(int i = 0; i < this->size(); i++){
        if(ptr1->element != ptr2->element){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}

void DoubleLinkedListOfInteger::addIncreasingOrder(int element){
    Nodo *ptr = header->next;
    Nodo *novo = new Nodo(element);
    // enquanto o elemento for menor que o que está na lista e não chegarmos no final da lista...
    while(element < ptr->element && ptr->next != trailer){
        ptr = ptr->next;
    }

    // faz o novo nodo apontar para os elementos antigos da lista
    novo->next = ptr;
    novo->prev = ptr->prev;

    // faz os elementos antigos da lista apontarem para o novo
    novo->next->prev = novo;
    novo->prev->next = novo;

    return;
}


bool DoubleLinkedListOfInteger::unique(){
    if(isEmpty())
        return true;

    Nodo *ptri = header->next; // começa no primeiro elemento da lista
    for(int i = 0; i < count; i++){
        Nodo *ptrj = ptri->next; // começa no proximo do nodo a ser verificado
        for(int j = i+1; j < count; j++){
            if(ptri->element == ptrj->element){ // compara se os elementos armazenados são iguais
                return false;
            }
            ptrj = ptrj->next;
        }
        ptri = ptri->next;
    }
    return true;
}

void DoubleLinkedListOfInteger::InsereNaDireita(Nodo *aux, int valor){
    Nodo *novo = new Nodo(valor);
    
    // faz o novo nodo apontar para os nodos já existentes na lista
    novo->prev = aux;
    novo->next = aux->next;

    // faz os nodos antigos apontarem para o novo elemento
    novo->prev->next = novo;
    novo->next->prev = novo;

    count++;

    return;
}

int DoubleLinkedListOfInteger::lastIndexOf(int element){
    if(isEmpty()){
        return -1;
    }
    Nodo *ptr = trailer->prev;
    for(int i = count-1; i >= 0; i--){
        if(ptr->element == element){
            return i;
        }
        ptr = ptr->prev;
    }
    return -1;
}

// O(n)
int DoubleLinkedListOfInteger::countOccurrences(int element){
    
    Nodo *aux = header->next;

    int countOcu = 0;
    for (int i = 0; i < count; i++){
        if (aux->element == element){
            countOcu++;
        }
        if (aux->next == trailer){
            break;
        }
        aux = aux->next;
    }
    return countOcu;
}
// O(n)
bool DoubleLinkedListOfInteger::removeEvenNumbers() {
    
    bool checar = false;
    int countaux = count;

    Nodo *aux = header->next;

    for (int i = 0; i < count; i++){
        if (aux->element % 2 == 0){
            Nodo *removido = aux;
            checar = true;

            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;

            countaux--;
        }
        aux = aux->next;
    }
    delete aux;
    count = countaux;
    return checar;
}

/*
O(n + (n * (n + 0)) / 2)
O(n + n^2/2)
O(n^2/2)
O(n^2)
*/
DoubleLinkedListOfInteger getunique(DoubleLinkedListOfInteger lista1) {

    if (lista1.unique()){
        return lista1;
    }

    Nodo *aux = lista1.getNodeIndex(0);
    DoubleLinkedListOfInteger listaAux;

    for (int i = 0; i < lista1.size(); i++){

        bool checar = false;

        for (int j = 0; j < listaAux.size() ; j++){
            if (aux->element == listaAux.get(j)){
                checar = true;
                break;
            }
        }

        if (!checar){
            listaAux.add(aux->element);
        }
        aux = aux->next;
    }

    return listaAux;
}
//O(n)
void DoubleLinkedListOfInteger::rotacionaEsquerda(int N){
    
    if (N < 1){
        throw IndexOutOfBoundsException;
    }

    if (N == count){
        return;
    }

    if (N > count){
        N = N % count;
    }
    
    for (int i = 0; i < N; i++){

        Nodo *aux = trailer->prev;
        trailer->prev = aux->prev;
        aux->prev->next = trailer;
        Nodo *aux2 = header->next;
        header->next = aux;
        aux->next = aux2;
        
    }
}
// O(n)
void DoubleLinkedListOfInteger::reverse (){

    Nodo *left = header->next;
    Nodo *right = trailer->prev;
    Nodo *auxHeader = header;
    Nodo *auxTrailer = trailer;

    for(int i = 0; i < count/2; i++){
        Nodo *auxl = left->next;
        Nodo *auxr = right->prev;
        if (i == (count/2)-1 && count%2 == 0){
            auxl = left;
            auxr = right;
        }
        left->next = auxTrailer;
        auxTrailer->prev = left;
        left->prev = auxr;
        auxr->next = left;
        right->prev = auxHeader;
        auxHeader->next = right;
        auxl->prev = right;
        right->next = auxl;
        auxTrailer = left;
        auxHeader = right;
        Nodo *aux2 = right->next;
        right = left->prev;
        left = aux2;
    }
}
/*
Arrumar possives passagens de Index impossiveis, como negativos e maiores que o tamanho da lista, etc
O(n)
*/

void DoubleLinkedListOfInteger::reverseSubList(int fromIndex, int toIndex){

    if (fromIndex > toIndex || fromIndex < 0 || toIndex > count || fromIndex > count|| toIndex < 0){
        throw IndexOutOfBoundsException;
    }

    int countRelativo = toIndex - fromIndex + 1;
    Nodo *left = header->next;
    Nodo *right = trailer->prev;
    Nodo *auxHeader = left->prev;
    Nodo *auxTrailer = right->next;
    for (int i = 0; i < fromIndex; i++){
        left = left->next;
        auxHeader = auxHeader->next;
    }

    for (int i = count-1; i > toIndex; i--){
        right = right->prev;
        auxTrailer = auxTrailer->prev;
    }

    for(int i = 0; i < countRelativo/2; i++){
        Nodo *auxl = left->next;
        Nodo *auxr = right->prev;
        if (i == (countRelativo/2)-1 && countRelativo%2 == 0){
            auxl = left;
            auxr = right;
        }
        left->next = auxTrailer;
        auxTrailer->prev = left;
        left->prev = auxr;
        auxr->next = left;
        right->prev = auxHeader;
        auxHeader->next = right;
        auxl->prev = right;
        right->next = auxl;
        auxTrailer = left;
        auxHeader = right;
        Nodo *aux2 = right->next;
        right = left->prev;
        left = aux2;
    }

}
