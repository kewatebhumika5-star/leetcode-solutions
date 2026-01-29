#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;

    char *stack = (char*)malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        
        else {
            if (top == -1) {
                free(stack);
                return false;
            }

            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);
    free(stack);
    return result;
}
