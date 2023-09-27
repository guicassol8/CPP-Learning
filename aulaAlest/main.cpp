#include <iostream>
#include <cstdlib>
using namespace std;

#include "Nodo.h"
#include "DoubleLinkedListOfInteger.h"


int main() {

    DoubleLinkedListOfInteger L1, L2,L3;

    L3.add(1);
    L3.add(2);
    L3.add(3);
    L3.add(4);
    L3.add(6);

    L1.add(1);
    L1.add(2);
    L1.add(30);
    L1.add(3);
    L1.add(1);
    L1.add(30);
    
    cout << "Ultima Ocorrencia: " << L1.lastIndexOf(1) << endl;
    L1.printBackToFront();
    
    L2.add(-2);
    L2.add(3);
    L2.add(30);
    L2.add(20);
    L2.recursivePrintBackToFront();

    cout << "As listas sao iguais? " << L1.equals(&L2) << endl;    

    cout << "A lista L1 e unique? " << L1.unique() << endl;

    cout << "A lista L2 e unique? " << L2.unique() << endl; 

    cout << "O ultimo index do elemento 1 na lista L1 e: " << L1.lastIndexOf(1) << endl;

    cout << "O primeiro index do elemento 1 na lista L1 e: " << L1.indexOf(1) << endl;

    cout << "O primeiro index do elemento 30 na lista L1 e: " << L1.indexOf(30) << endl;

    cout << "O ultimo index do elemento 30 na lista L1 e: " << L1.lastIndexOf(30) << endl;

    cout << "Numero de ocorrencias de 30 na lista L1 e: " << L1.countOccurrences(30) << endl;

    cout<< "Revertendo L1..." << endl;

    L1.reverse();

    L1.ImprimeLista();

    cout<< "Revertendo L1 de index 1 ate 5..." << endl;

    L1.reverseSubList(1,5);

    L1.ImprimeLista();

    L3.reverse();

    L3.ImprimeLista();

    if (L1.removeEvenNumbers()){
      cout << "Removendo pares da lista L1..." << endl;
      }
    else {
      cout << "Nao ha pares na lista L1" << endl;
    }

    //L1.ImprimeLista();
    L1.ImprimeLista();
    cout << "Rotacionado para esquerda 3 vezes a lista L2..." << endl;
    L2.rotacionaEsquerda(3);
    L2.ImprimeLista();
    //cout << "inserindo -1 a direita de 30..." << endl;
    //L2.InsereNaDireita(L2.getNodeIndex(2), -1);
    L1.ImprimeLista();
    L1 = getunique(L1);
    L1.ImprimeLista();
    L3 = getunique(L3);
    L3.ImprimeLista();
    L2 = getunique(L2);
    L2.ImprimeLista();

  return 0;
}
