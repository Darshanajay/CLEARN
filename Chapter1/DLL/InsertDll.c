#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node* prev;
  int data;
  struct node* next;
};


struct node* addEmptyLL(struct node* head , int ele){
  struct node* newp = malloc(sizeof(struct node));
  newp->prev = NULL;
  newp->data = 77;
  newp->next = NULL;
  head = newp;
  return head;
}

int main(){

  struct node* head = NULL;
  head = addEmptyLL(head,33);
  printf("%d",head->data);

  return 0;
}