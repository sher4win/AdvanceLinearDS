// main.c
/*
#include "stack.h"
#include <stdio.h>

int main() {
    Stack stack;
    initialize(&stack);

    int choice;
    int value, index;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Peek at the top element\n");
        printf("4. Count elements in the stack\n");
        printf("5. Change an element at a specific position\n");
        printf("6. Display stack contents\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                printf("Number of elements in the stack: %d\n", count(&stack));
                break;
            case 5:
                printf("Enter the index of the element to change (0 to %d): ", stack.top);
                scanf("%d", &index);
                if (index >= 0 && index <= stack.top) {
                    printf("Enter the new value: ");
                    scanf("%d", &value);
                    change(&stack, index, value);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 6:
                display(&stack);
                break;
            case 7:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    }

    return 0;
}


// main.c

#include "stack.h"
#include "infix_to_postfix.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    Stack stack;
    initialize(&stack);
    char infixExpression[100], postfixExpression[100];
    int choice, value, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Peek at the top element of the stack\n");
        printf("4. Count elements in the stack\n");
        printf("5. Change an element at a specific position in the stack\n");
        printf("6. Display stack contents\n");
        printf("7. Convert an infix expression to postfix\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                printf("Number of elements in the stack: %d\n", count(&stack));
                break;
            case 5:
                printf("Enter the index of the element to change (0 to %d): ", stack.top);
                scanf("%d", &index);
                if (index >= 0 && index <= stack.top) {
                    printf("Enter the new value: ");
                    scanf("%d", &value);
                    change(&stack, index, value);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 6:
                display(&stack);
                break;
            case 7:
                printf("Enter an infix expression: ");
                scanf("%s", infixExpression);
                infixToPostfix(infixExpression, postfixExpression);
                printf("Postfix expression: %s\n", postfixExpression);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
*/

// main.c

#include "stack.h"
#include "infix_to_postfix.h"
#include "postfix_evaluation.h"
#include "bracket_matching.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void stackMenu() {
    Stack stack;
    initialize(&stack);
    int choice, value, index;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Peek at the top element of the stack\n");
        printf("4. Count elements in the stack\n");
        printf("5. Change an element at a specific position in the stack\n");
        printf("6. Display stack contents\n");
        printf("7. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                printf("Number of elements in the stack: %d\n", count(&stack));
                break;
            case 5:
                printf("Enter the index of the element to change (0 to %d): ", stack.top);
                scanf("%d", &index);
                if (index >= 0 && index <= stack.top) {
                    printf("Enter the new value: ");
                    scanf("%d", &value);
                    change(&stack, index, value);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 6:
                display(&stack);
                break;
            case 7:
                return; // Return to the main menu
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

/*

int main() {
    char infixExpression[100], postfixExpression[100];
    int choice;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Create Stack and Perform Stack Operations\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stackMenu(); // Display the stack menu
                break;
            case 2:
                printf("Enter an infix expression: ");
                scanf("%s", infixExpression);
                infixToPostfix(infixExpression, postfixExpression);
                printf("Postfix expression: %s\n", postfixExpression);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

int main() {
    char infixExpression[100], postfixExpression[100];
    int choice;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Create Stack and Perform Stack Operations\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Postfix Expression Evaluation\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stackMenu();
                break;
            case 2:
                printf("Enter an infix expression: ");
                scanf("%s", infixExpression);
                infixToPostfix(infixExpression, postfixExpression);
                printf("Postfix expression: %s\n", postfixExpression);
                break;
            case 3:
                printf("Enter a postfix expression: ");
                scanf("%s", postfixExpression);
                int result = evaluatePostfix(postfixExpression);
                printf("Evaluation result: %d\n", result);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}


int main() {
    char infixExpression[100], postfixExpression[100];
    int choice;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Create Stack and Perform Stack Operations\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Postfix Expression Evaluation\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stackMenu();
                break;
            case 2:
                printf("Enter an infix expression: ");
                scanf("%s", infixExpression);
                infixToPostfix(infixExpression, postfixExpression);
                printf("Postfix expression: %s\n", postfixExpression);
                break;
            case 3:
                printf("Enter a postfix expression: ");
                scanf("%s", postfixExpression);
                int result = evaluatePostfix(postfixExpression);
                printf("Evaluation result: %d\n", result);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
*/

int main() {
    char infixExpression[100], postfixExpression[100], expression[100];
    int choice;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Create Stack and Perform Stack Operations\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Postfix Expression Evaluation\n");
        printf("4. Bracket Matching\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stackMenu();
                break;
            case 2:
                printf("Enter an infix expression: ");
                scanf("%s", infixExpression);
                infixToPostfix(infixExpression, postfixExpression);
                printf("Postfix expression: %s\n", postfixExpression);
                break;
            case 3:
                printf("Enter a postfix expression: ");
                scanf("%s", postfixExpression);
                int result = evaluatePostfix(postfixExpression);
                printf("Evaluation result: %d\n", result);
                break;
            case 4:
                printf("Enter an expression to check for bracket matching: ");
                scanf("%s", expression);
                if (areBracketsMatched(expression)) {
                    printf("Brackets are matched.\n");
                } else {
                    printf("Brackets are not matched.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}