#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to reverse a string manually (since strrev is not standard in GCC)
void reverse(char* exp) {
    int i = 0, j = strlen(exp) - 1;
    char temp;
    while (i < j) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
        i++;
        j--;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    int i, j = 0;
    
    // 1. Reverse the infix expression
    reverse(infix);

    // 2. Swap '(' and ')'
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // 3. Convert modified Infix to Postfix
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i]; // Operand directly to output
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && peek() != '(') {
                prefix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else {
            // Operator: pop while precedence is STRICTLY greater (because string is reversed)
            while (top != -1 && precedence(peek()) > precedence(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';

    // 4. Reverse the postfix result to get the prefix expression
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter Infix Expression (e.g., A+B*C): ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}