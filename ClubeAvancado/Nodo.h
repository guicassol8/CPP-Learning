
#ifndef _NODO
#define _NODO
// ****************************
class Nodo{
public:

  long int element;
  Nodo *next;
  Nodo *prev;

  Nodo();
  Nodo(int i);
  Nodo(int i, Nodo *next);
  Nodo(int i, Nodo *next, Nodo *prev);

};

#endif
