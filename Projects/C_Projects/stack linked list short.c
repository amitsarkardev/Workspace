#include <stdio.h>
#include <stdlib.h>

typedef struct N { int d; struct N *n; } N;
N *t = NULL;

void push(int v) { N *x = malloc(sizeof(N)); x->d = v; x->n = t; t = x; }
void pop() { if (t) { N *x = t; printf("Popped: %d\n", t->d); t = t->n; free(x); } else printf("Empty\n"); }

int main() {
    int c, v;
    while (printf("\n1.Push \n2.Pop \n3.Display \n4.Exit: "), scanf("%d", &c) && c != 4) {
        if (c == 1) printf("Val: "), scanf("%d", &v), push(v);
        if (c == 2) pop();
        if (c == 3) for (N *x = t; x; x = x->n) printf("%d -> ", x->d);
    }
}