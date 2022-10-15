#ifndef stack_h_
#define stack_h_

typedef struct elem{
  int value;
  struct elem *next;
}elem;

typedef struct stack{
  elem* first;
  unsigned int size;
}stack;


int pop(stack*, int*); /* zapisuje do int pierwszy element stack, usuwa pierwszy element ze stack */
int push(stack*, int*); /* int jest wrzucany na poczatek stack */
int init(stack*); /* inicjuje stos */
int front(stack*); /* zwraca element na szczycie stosu */
int print(stack*); /* wypisuje wszystkie elementy stosu od najnowszego */


#endif
