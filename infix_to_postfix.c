// infix_to_postfix.c

#include "infix_to_postfix.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPostfix(const char *infixExpression, char *postfixExpression) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;

    for (i = 0; infixExpression[i] != '\0'; i++) {
        char token = infixExpression[i];

        if (isalnum(token)) {
            postfixExpression[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfixExpression[j++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        } else {
            while (!is_empty(&stack) && precedence(token) <= precedence(peek(&stack))) {
                postfixExpression[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!is_empty(&stack)) {
        postfixExpression[j++] = pop(&stack);
    }

    postfixExpression[j] = '\0';
}

