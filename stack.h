// stack.h

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100 // Maximum size of the stack

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
int is_empty(const Stack *stack);
int is_full(const Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
void display(const Stack *stack);
int peek(const Stack *stack);
int count(const Stack *stack);
void change(Stack *stack, int index, int value);

#endif // STACK_H
