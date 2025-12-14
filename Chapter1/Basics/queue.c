// #include <stdio.h>
// #define Max 4

// typedef struct {
//   int qu[Max];
//   int rear,front;
// }queue;

// void init(queue *q){
//   q->front = -1;
//   q->rear = -1;
// }

// int isFull(queue *q){
//   return q->rear == Max -1;
// }

// int isEmpty(queue *q){
//   return q->rear+1 == q->front; 
// }

// void enque(queue *q,int ele){
//   if(isFull(q)){
//     printf("queue is Full...");
//   }
//   if (isEmpty(q))
//         q->front = 0;
//   else
//   {
    
//     q->rear++;
//     q->qu[q->rear] = ele;
//     printf("inserted element is: %d\n",ele);
//   }
// }

// void deque(queue *q){
//   if(isEmpty(q)){
//     printf("queue is Empty...");
//   }
//   else{
//     int ele = q->qu[q->front];
//     q->front++;
//     printf("deleted element is %d\n",ele);
//   }
  
// }

// void display(queue *q){
//   if(isEmpty(q)){
//     printf("queue is Empty...");
//   }
//   else
//   {
//     for(int i=q->front;i<=q->rear;i++){
//       printf("%d,",q->qu[i]);
//     }
//   }
  
  
// }

// int main(){
//   queue q;
//   init(&q);
//   enque(&q,10);
//   enque(&q,20);
//   enque(&q,30);
//   //enque(&q,40);

//   display(&q);
//   deque(&q);
//   return 0;
// }

#include <stdio.h>
#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued\n", value);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;  // Reset queue
    printf("%d dequeued\n", data);
    return data;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}
