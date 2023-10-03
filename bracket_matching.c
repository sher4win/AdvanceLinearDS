// bracket_matching.c

#include "bracket_matching.h"
#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

bool areBracketsMatched(const char *expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char bracket = expression[i];

        if (bracket == '(' || bracket == '[' || bracket == '{') {
            push(&stack, bracket);
        } else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (is_empty(&stack)) {
                return false; // Unmatched closing bracket
            }

            char topBracket = pop(&stack);

            if ((bracket == ')' && topBracket != '(') ||
                (bracket == ']' && topBracket != '[') ||
                (bracket == '}' && topBracket != '{')) {
                return false; // Mismatched brackets
            }
        }
    }

    return is_empty(&stack); // All brackets must be matched
}
