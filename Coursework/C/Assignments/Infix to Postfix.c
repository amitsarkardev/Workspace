#include <stdio.h>
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

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            // If operand, add to postfix output
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // If left parenthesis, push to stack
            push(infix[i]);
        } else if (infix[i] == ')') {
            // If right parenthesis, pop until left parenthesis is found
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else {
            // If operator, pop higher or equal precedence operators to output
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]); // Push current operator
        }
        i++;
    }
    
    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter Infix Expression (e.g., A+B*C): ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}