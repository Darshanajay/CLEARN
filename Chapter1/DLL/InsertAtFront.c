#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node* prev;
  int data;
  struct node* next;
};

void print(struct node* head){
  if(head == NULL){
    printf("List is Empty");
  }
  else{
    struct node* temp = malloc(sizeof(struct node));
    temp = head;
    while(temp != NULL){
      printf("%d\t",temp->data);
      temp = temp->next;
    }
  }
}

struct node* insertFront(struct node* head,int ele){
  struct node* newp = malloc(sizeof(struct node));
  newp->prev = NULL;
  newp->data = ele;
  newp->next = NULL;  

  struct node* temp = head;
  newp->next = head;
  head=newp;
  temp->prev = newp;
  return head;
}

int main(){

  struct node* head = malloc(sizeof(struct node));
  head->prev = NULL;
  head->data = 99;
  head->next = NULL;
  
  struct node* newp = malloc(sizeof(struct node));
  newp->prev = NULL;
  newp->data = 22;
  newp->next = NULL;

  head->next = newp;
  newp->prev = head;

  head = insertFront(head,44);

  
  
  print(head);
  

  return 0;
}