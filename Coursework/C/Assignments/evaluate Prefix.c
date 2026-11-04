#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void evaluatePrefix(char* prefix) {
    int val1, val2, result;
    int len = strlen(prefix);

    // Scan from Right to Left
    for (int i = len - 1; i >= 0; i--) {
        // If character is a digit, push it to stack
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0'); 
        } 
        // If character is an operator, pop two elements
        else {
            val1 = pop(); // Top element is val1
            val2 = pop(); // Next element is val2

            switch (prefix[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero!\n");
                        return;
                    }
                    result = val1 / val2; 
                    break;
                case '^': 
                    result = (int)pow(val1, val2); 
                    break;
                default: 
                    printf("Unknown operator encountered.\n");
                    return;
            }
            push(result);
        }
    }
    
    printf("Result of Prefix evaluation: %d\n", pop());
}

int main() {
    char prefix[MAX];
    
    printf("Enter Prefix Expression (single-digit numbers, e.g., +*234): ");
    scanf("%s", prefix);
    
    evaluatePrefix(prefix);
    
    return 0;
}