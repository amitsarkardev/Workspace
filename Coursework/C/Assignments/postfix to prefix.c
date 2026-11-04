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

void postfixToPrefix(char* postfix) {
    int len = strlen(postfix);
    char op1[MAX], op2[MAX], temp[MAX];
    char operand[2];

    // Scan from Left to Right
    for (int i = 0; i < len; i++) {
        if (isalnum(postfix[i])) {
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(operand);
        } else {
            pop(op2); // op2 is popped first
            pop(op1);
            // Format as operator + op1 + op2
            sprintf(temp, "%c%s%s", postfix[i], op1, op2);
            push(temp);
        }
    }
    printf("Prefix Expression: %s\n", stack[top]);
}

int main() {
    char postfix[MAX];
    printf("Enter Postfix Expression (e.g., AB+C*): ");
    scanf("%s", postfix);
    postfixToPrefix(postfix);
    return 0;
}