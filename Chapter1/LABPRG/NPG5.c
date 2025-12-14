#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Structure to represent Queue
typedef struct {
    int calls[MAX];
    int front;
    int rear;
} Queue;

// Initialize queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Add new call to queue (Enqueue)
void enqueue(Queue *q, int callID) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow! Cannot add more calls.\n");
        return;
    }
    q->rear++;
    q->calls[q->rear] = callID;
    printf("Incoming Call Added: %d\n", callID);
}

// Remove call from queue (Dequeue)
void dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue Underflow! No calls waiting.\n");
        return;
    }
    int servicedCall = q->calls[q->front];
    printf("Call Being Serviced: %d\n", servicedCall);
    q->front++;
}

// Display queue
void display(Queue *q) {
    if (q->front > q->rear) {
        printf("No calls in the queue.\n");
        return;
    }

    printf("\n--- CALL QUEUE (Front → Rear) ---\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->calls[i]);
    }
    printf("\n----------------------------------\n");
}

int main() {
    Queue q;
    init(&q);

    int choice, callID;

    while (1) {
        printf("\n--- CALL CENTER SYSTEM ---\n");
        printf("1. Add Incoming Call\n");
        printf("2. Service a Call (Dequeue)\n");
        printf("3. Show Waiting Calls\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Call ID: ");
                scanf("%d", &callID);
                enqueue(&q, callID);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}
