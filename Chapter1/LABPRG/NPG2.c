#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Structure for Stack
typedef struct {
    int pages[MAX];
    int top;
} Stack;

// Function to initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Push: visit a new web page
void push(Stack *s, int page) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot visit more pages.\n");
        return;
    }
    s->pages[++(s->top)] = page;
    printf("Visited Page: %d\n", page);
}

// Pop: go backward
void pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! No pages to go back.\n");
        return;
    }
    int removedPage = s->pages[(s->top)--];
    printf("Going Back... Removed Page: %d\n", removedPage);
}

// Display the stack
void display(Stack *s) {
    if (s->top == -1) {
        printf("No pages in history.\n");
        return;
    }

    printf("\n--- PAGE HISTORY (Top to Bottom) ---\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->pages[i]);
    }
    printf("------------------------------------\n");
}

int main() {
    Stack s;
    init(&s);

    int choice, page;

    while (1) {
        printf("\n--- WEB BROWSER ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back (Pop)\n");
        printf("3. Show Page History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Page Number to Visit: ");
                scanf("%d", &page);
                push(&s, page);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                display(&s);
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
