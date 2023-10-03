// stack.c

#include "stack.h"
#include <stdio.h>

void initialize(Stack *stack) {
    stack->top = -1;
}

int is_empty(const Stack *stack) {
    return stack->top == -1;
}

int is_full(const Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }
    return stack->data[stack->top--];
}

void display(const Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int peek(const Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int count(const Stack *stack) {
    return stack->top + 1;
}

void change(Stack *stack, int index, int value) {
    if (index < 0 || index > stack->top) {
        printf("Invalid index. Cannot change element.\n");
        return;
    }
    stack->data[index] = value;
}