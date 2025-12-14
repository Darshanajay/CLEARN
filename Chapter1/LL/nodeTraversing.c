#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *link;
};

void countOfNodes(struct node *head){
  int count = 0;
  if(head == NULL){
    printf("Linked List is empty");
  }
  struct node *ptr = NULL;
  ptr = head;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->link;
  }
  printf("%d",count);
  
}

int main(){
  struct node *head=malloc(sizeof(struct node));
  head->data = 21;
  
  struct node *current=malloc(sizeof(struct node));
  current->data = 34;
  head->link = current;
  
  current = malloc(sizeof(struct node));
  current->data = 66;
  head->link->link = current;
  
  
  printf("%d\t",head->data);
  printf("%d\t",current->data);
  countOfNodes(head);
  return 0;
}