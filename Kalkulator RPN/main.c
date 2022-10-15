#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define ENDLESS 1
#define CALC_ERROR -1
#define SUCCESS 1
#define FAIL 0;

int my_add(stack*);
int my_sub(stack*);
int my_mul(stack*);
int my_div(stack*);

void print_guide();

int main(){
  stack calc;
  init(&calc);

  char sign;
  
  char input[10];
  int int_input;
  input[0]='q';

  print_guide();
  
  while(ENDLESS){
    scanf("%s", input);
    if(input[0] == 'p') break;
    
    switch(input[0]){
    case '+': if( !my_add(&calc) ) return CALC_ERROR; break;
    case '-': if( !my_sub(&calc) ) return CALC_ERROR; break;
    case '*': if( !my_mul(&calc) ) return CALC_ERROR; break;
    case '/': if( !my_div(&calc) ) return CALC_ERROR; break;
    default: sscanf(input, "%d", &int_input); push(&calc, &int_input); break;
    }
  }

  pop(&calc, &int_input);
  printf("Ostatni wynik: %d\n", int_input);
  
  return 0;
}

int my_add(stack *my_stack){
  int s1, s2;
  if( !pop(my_stack, &s1) ) return FAIL;
  if( !pop(my_stack, &s2) ) return FAIL;
  int ex = s2 + s1;
  printf("dodaje: %d do %d\n", s2, s1);
  if( !push(my_stack, &ex) ) return FAIL;
  return SUCCESS;
}

int my_sub(stack *my_stack){
  int s1, s2;
  if( !pop(my_stack, &s1) ) return FAIL;
  if( !pop(my_stack, &s2) ) return FAIL;
  int ex = s2 - s1;
  printf("odejmuje: od %d %d\n", s2, s1);
  if( !push(my_stack, &ex) ) return FAIL;
  return SUCCESS;
}

int my_mul(stack *my_stack){
  int s1, s2;
  if( !pop(my_stack, &s1) ) return FAIL;
  if( !pop(my_stack, &s2) ) return FAIL;
  int ex = s2 * s1;
  printf("mnoze: %d razy %d\n", s2, s1);
  if( !push(my_stack, &ex) ) return FAIL;
  return SUCCESS;
}

int my_div(stack *my_stack){
  int s1, s2;
  if( !pop(my_stack, &s1) ) return FAIL;
  if( !pop(my_stack, &s2) ) return FAIL;
  int ex = s2 / s1;
  printf("dziele: %d przez %d\n", s2, s1);
  if( !push(my_stack, &ex) ) return FAIL;
  return SUCCESS;
}

void print_guide(){

  printf("Dane nalezy wprowadzac w osobnych linijkach\nBrak obslugi wprowadzania liczb ujemnych\nAby zakonczyc dzialanie programu nalezy pwrowadzic znak 'p'\n");

  return;
}
