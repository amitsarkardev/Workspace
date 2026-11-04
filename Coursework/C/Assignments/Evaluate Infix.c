#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int valStack[MAX];
int valTop = -1;

char opStack[MAX];
int opTop = -1;

// Value Stack Operations
void pushVal(int val) { valStack[++valTop] = val; }
int popVal() { return valStack[valTop--]; }

// Operator Stack Operations
void pushOp(char op) { opStack[++opTop] = op; }
char popOp() { return opStack[opTop--]; }
char peekOp() { return opStack[opTop]; }

// Check operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Apply arithmetic operation
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
    }
    return 0;
}

void evaluateInfix(char* expr) {
    int i = 0;
    
    while (expr[i] != '\0') {
        // If current character is a digit, push to value stack
        if (isdigit(expr[i])) {
            pushVal(expr[i] - '0');
        }
        // If current character is an opening brace, push to operator stack
        else if (expr[i] == '(') {
            pushOp(expr[i]);
        }
        // If current character is a closing brace
        else if (expr[i] == ')') {
            while (opTop != -1 && peekOp() != '(') {
                int val2 = popVal();
                int val1 = popVal();
                char op = popOp();
                pushVal(applyOp(val1, val2, op));
            }
            popOp(); // Pop the '('
        }
        // If current character is an operator
        else {
            while (opTop != -1 && precedence(peekOp()) >= precedence(expr[i])) {
                int val2 = popVal();
                int val1 = popVal();
                char op = popOp();
                pushVal(applyOp(val1, val2, op));
            }
            pushOp(expr[i]);
        }
        i++;
    }
    
    // Process remaining elements in the stacks
    while (opTop != -1) {
        int val2 = popVal();
        int val1 = popVal();
        char op = popOp();
        pushVal(applyOp(val1, val2, op));
    }
    
    printf("Result of Infix evaluation: %d\n", popVal());
}

int main() {
    char infix[MAX];
    
    printf("Enter Infix Expression (single-digit numbers, e.g., 2+3*4): ");
    scanf("%s", infix);
    
    evaluateInfix(infix);
    
    return 0;
}