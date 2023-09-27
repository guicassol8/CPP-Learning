#include <iostream>
using namespace std;

#include "Nodo.h"

Nodo::Nodo()
{
    this->next = NULL;
}

Nodo::Nodo(int i)
{
    this->element = i;
    this->next = NULL;
    this->prev = NULL;
}

Nodo::Nodo(int i, Nodo *next)
{
    this->element = i;
    this->next = next;
    this->prev = NULL;
}

Nodo::Nodo(int i, Nodo *next, Nodo *prev)
{
    this->element = i;
    this->next = next;
    this->prev = prev;
}
