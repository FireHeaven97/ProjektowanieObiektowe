#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int pop(stack *my_stack, int *my_elem){
  if(my_stack->first == NULL) return 0;

  elem *new_first = (*(my_stack->first)).next;
  *my_elem = (*(my_stack->first)).value;
  
  free(my_stack->first);
  
  my_stack->first = new_first;
  --(my_stack->size);
  
  return 1;
}

int push(stack *my_stack, int *my_elem){
  elem *init = (elem*)malloc(sizeof(elem));
  if(init == NULL) return 0;
  init->value = *my_elem;
  init->next = my_stack->first;
  
  my_stack->first = init;
  
  ++my_stack->size;
  return 1;
}

int init(stack *my_stack){
  my_stack->first = NULL;
  my_stack->size = 0;
  return 1;
}

int front(stack *my_stack){
  return my_stack->first->value;
}

int print(stack *my_stack){
  elem *current = my_stack->first;
  while(current != NULL){
    printf("%d ",current->value);
    current = current->next;
  }
  printf("\n");
  return 1;
}
