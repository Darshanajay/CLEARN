#include <stdio.h>
#include <stdlib.h>


struct node {
  struct node* prev;
  int data;
  struct node* next;
};


struct node* insert(struct node* head,int data){
  struct node* newn = malloc(sizeof(struct node));
  newn->prev = NULL;
  newn->data = data;
  newn->next = NULL;
  
  if(head == NULL){
    return newn;
  }
  struct node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newn;
  newn->prev = temp;
  return head;
}
struct node* readData(struct node* head){
  int data, n,i;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  for(i=0;i<n;i++){
    printf("Enter a node%d: ",i+1);
    scanf("%d",&data);
    head = insert(head,data);
  }
  return head;
}

void print(struct node* head){
  if(head == NULL){
    printf("list is empty");
  }
  struct node* temp = head;
  printf("DD Linked list: ");
  while(temp != NULL){
    printf("%d\t",temp->data);
    temp = temp->next;
  }
}


int main(){

  struct node* head = NULL;
  head = readData(head);

  print(head);

  return 0;
}