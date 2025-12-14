//Write a program to evaluate a valid postfix expression using stack. Assume that the postfix expression is read as a single line consisting of non-negative single digit operands and binary operators. The operators are + - * and /.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

typedef struct {
    char* s;
    int top;
    int size;
} STACK;

STACK* create(int size) {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->size = size;
    stack->top = -1;
    stack->s = (char*)malloc(stack->size*sizeof(STACK));
    return stack;
}

bool empty(STACK* stack) {
    return (stack->top == -1);
}

bool full(STACK* stack) {
    return (stack->top == (stack->size - 1));
}

void push(STACK* stack, char item) {
    if(full(stack)){
        printf("overflow\n");
        return;
    }
    stack->s[++stack->top] = item;    
}

char pop(STACK* stack) {
    if(empty(stack)) {
        printf("underflow\n");
        return -1;
    }
    return stack->s[stack->top--];
}

char peek(STACK* stack){
    if(empty(stack)) {
        printf("underflow\n");
        return -1;
    }
    return stack->s[stack->top];
}

void liberate(STACK* stack) {
    free(stack->s);
    free(stack);
}

bool opnd(char op) {
    return (isalnum(op));
}

bool optr(char op) {
    return (op == '*' || op == '-' || op == '/' || op == '%' || op == '+');
}

char itoc(int i) {
    return (char)(i+48);
}

char ctoi(char c) {
    return (int)(c-'0');
}

int evaluate(char* postfix) {
    int ind = 0;
    STACK* stack = create(60);
    for(int i = 0; postfix[i]!='\0'; i++) {
        char cur = postfix[i];
        if(opnd(cur)) {
            push(stack, cur);
        }
        else if(optr(cur)) {
            int op2 = ctoi(pop(stack));
            int op1 = ctoi(pop(stack));
            switch(cur) {
                case '+':
                    push(stack, itoc(op1+op2));
                    break;
                case '-':
                    push(stack, itoc(op1-op2));
                    break;
                case '*':
                    push(stack, itoc(op1*op2));
                    break;
                case '/':
                    push(stack, itoc(op1/op2));
                    break;
                case '%':
                    push(stack, itoc(op1%op2));
                    break;
            }
        }
    }
    int result = ctoi(pop(stack));
    liberate(stack);
    return result;
}

int main(void) {
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%[ ^ \n]", postfix);
    printf("The result of the expression is: %d\n", evaluate(postfix));
}