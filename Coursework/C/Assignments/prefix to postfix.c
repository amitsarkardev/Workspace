#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    if (top < MAX - 1) strcpy(stack[++top], str);
}

void pop(char* str) {
    if (top != -1) strcpy(str, stack[top--]);
}

void prefixToPostfix(char* prefix) {
    int len = strlen(prefix);
    char op1[MAX], op2[MAX], temp[MAX];
    char operand[2];

    // Scan from Right to Left
    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(operand);
        } else {
            pop(op1);
            pop(op2);
            // Format as op1 + op2 + operator
            sprintf(temp, "%s%s%c", op1, op2, prefix[i]);
            push(temp);
        }
    }
    printf("Postfix Expression: %s\n", stack[top]);
}

int main() {
    char prefix[MAX];
    printf("Enter Prefix Expression (e.g., *+ABC): ");
    scanf("%s", prefix);
    prefixToPostfix(prefix);
    return 0;
}