#include <stdio.h>
#include <stdlib.h>

typedef struct N { int d; struct N *n; } N;
N *f = NULL, *r = NULL;

void in(int v) { N *x = malloc(sizeof(N)); x->d = v; x->n = NULL; if (!r) f = r = x; else r = r->n = x; }
void de() { if (f) { N *t = f; printf("Deleted: %d\n", t->d); f = f->n; if (!f) r = NULL; free(t); } }

int main() {
    int c, v;
    while (printf("\n1.Insert 2.Delete 3.Display 4.Exit: "), scanf("%d", &c) && c != 4) {
        if (c == 1) printf("Val: "), scanf("%d", &v), in(v);
        if (c == 2) de();
        if (c == 3) for (N *t = f; t; t = t->n) printf("%d -> ", t->d);
    }
    return 0;
}