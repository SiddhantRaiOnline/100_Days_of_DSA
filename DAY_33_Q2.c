#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* t = tokens[i];

        // Check if operator
        if (strcmp(t, "+") == 0 ||
            strcmp(t, "-") == 0 ||
            strcmp(t, "*") == 0 ||
            strcmp(t, "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];

            if (strcmp(t, "+") == 0)
                stack[++top] = a + b;
            else if (strcmp(t, "-") == 0)
                stack[++top] = a - b;
            else if (strcmp(t, "*") == 0)
                stack[++top] = a * b;
            else
                stack[++top] = a / b;  // truncates toward 0
        }
        else {
            // Convert string to int
            stack[++top] = atoi(t);
        }
    }

    return stack[top];
}