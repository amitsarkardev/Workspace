#include <stdio.h>
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

void evaluatePostfix(char* postfix) {
    int i = 0;
    int val1, val2, result;

    while (postfix[i] != '\0') {
        // If character is a digit, convert to integer and push
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0'); // Convert char to actual integer value
        } 
        // If character is an operator, pop two elements and evaluate
        else {
            val1 = pop();
            val2 = pop();

            switch (postfix[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': 
                    if (val1 == 0) {
                        printf("Error: Division by zero!\n");
                        return;
                    }
                    result = val2 / val1; 
                    break;
                case '^': 
                    result = (int)pow(val2, val1); 
                    break;
                default: 
                    printf("Unknown operator encountered.\n");
                    return;
            }
            // Push the result back onto the stack
            push(result);
        }
        i++;
    }
    
    printf("Result of evaluation: %d\n", pop());
}

int main() {
    char postfix[MAX];
    
    printf("Enter Postfix Expression (single-digit numbers, e.g., 53+82-*): ");
    scanf("%s", postfix);
    
    evaluatePostfix(postfix);
    
    return 0;
}