#include <stdio.h>
#include <stdlib.h>


struct node {int val; struct node *next;};

void print_list(struct node *start){
  while(start != NULL){
    printf("%i ",start->val);
    start = (start->next);
  }
  printf("\n");
  return;
}

struct node * insert_front(struct node *top, int val){
  struct node *ret;
  ret = (struct node *)malloc(sizeof(struct node));
  ret->val = val;
  ret->next = top;
  return ret;
}

struct node * free_list(struct node *start){
  while(start != NULL){
    struct node * tempptr = start;
    start = start->next;
    free(tempptr);
  }
  return start;
}


void main(){

  printf("------TESTING-------\n\n");
  
  printf("We start with the simple creation of a single node with a value of 16 and prunt it using the print_list fxn:\n");
  struct node *test;
  test = (struct node *)malloc(sizeof(struct node));
  test->val = 16;
  test->next = NULL;
  print_list(test);

  printf("\nThen we add a node to the front using insert_front fxn and use the print_list fxn again:\n");
  struct node *test2 = insert_front(test, 15);
  print_list(test2);

  printf("\nThen we use a while loop to add some more numbers!!!!:\n");
  int x = 14;
  while(x > 0){
    test2 = insert_front(test2,x);
    x--;
  }
  print_list(test2);

  printf("\nThen we free up the data using the free_list fxn:\n\n");
  free_list(test2);

  printf("But when I try to print the list, which should be a null pointer now, still returns memory values at the freed memory locations (I think). I thought it would just be empty, which is what my code is made to do when it sees an NULL, but for some reason this isn't exactly a null:\n\n");
  print_list(test2);
}
