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
  printf("Total no-of nodes are: %d\n",count);
}

void print_data(struct node *head){
  if(head == NULL){
    printf("Linked List is empty");
  }
  struct node *ptr = NULL;
  ptr = head;
  while(ptr != NULL){
    printf("%d\t",ptr->data);
    ptr = ptr->link;
  }
}

void insertAtEnd(struct node *head,int ele){
  struct node *ptr , *temp;
  ptr = head;

  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = ele;
  temp->link = NULL;

  while (ptr->link != NULL)
  {
    ptr = ptr->link;
  }
  ptr->link = temp;
}

// struct node* insertAtFront(struct node *head,int ele){
//   struct node *ptr;
//   ptr = (struct node*)malloc(sizeof(struct node));
//   ptr->data = ele;
//   ptr->link = NULL;

//   ptr->link = head;
//   head = ptr;
//   return head;
// }

void insertAtFront(struct node **head,int ele){
  struct node *ptr;
  ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = ele;
  ptr->link = NULL;

  ptr->link = *head;
  *head = ptr;
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

  
  
  insertAtEnd(head , 44);
  // head = insertAtFront(head , 100);
  // struct node *ptr = malloc(sizeof(struct node));
  // ptr = head;
  // while(ptr != NULL){
  //   printf("%d\t",ptr->data);
  //   ptr = ptr->link;
  // }
  insertAtFront(&head , 100);
  struct node *ptr = malloc(sizeof(struct node));
  ptr = head;
  while(ptr != NULL){
    printf("%d\t",ptr->data);
    ptr = ptr->link;
  }
  return 0;
}