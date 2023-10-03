// postfix_evaluation.c

#include "postfix_evaluation.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluatePostfix(const char *postfixExpression) {
    Stack stack;
    initialize(&stack);

    int operand1, operand2, result;
    char token;

    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        token = postfixExpression[i];

        if (isdigit(token)) {
            push(&stack, token - '0'); // Convert character to integer
        } else if (token == ' ') {
            continue; // Ignore spaces
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Error: Invalid operator '%c' in postfix expression.\n", token);
                    exit(EXIT_FAILURE);
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}
