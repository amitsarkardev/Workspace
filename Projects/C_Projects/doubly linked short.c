#include <stdio.h>
#include <stdlib.h>

typedef struct N { int d; struct N *p, *n; } N;
N *h = NULL;

void ins(int v, int pos) {
    N *x = calloc(1, sizeof(N)), *t = h; x->d = v;
    if (!h || pos == 1) { x->n = h; if (h) h->p = x; h = x; return; }
    for (int i = 1; i < pos - 1 && t->n; i++) t = t->n;
    x->n = t->n; x->p = t;
    if (t->n) t->n->p = x;
    t->n = x;
}

void del(int pos) {
    N *t = h;
    for (int i = 1; i < pos && t; i++) t = t->n;
    if (!t) return;
    if (t->p) t->p->n = t->n; else h = t->n;
    if (t->n) t->n->p = t->p;
    free(t);
}

int main() {
    int c, v, p, i;
    while (printf("\n1.Create \n2.Display \n3.Search \n4.Insert \n5.Delete \n6.Exit: "), scanf("%d", &c) && c != 6) {
        if (c == 1) for (printf("Count: "), scanf("%d", &p), i = 0; i < p; i++) scanf("%d", &v), ins(v, 999);
        if (c == 2) { for (N *t = h; t; t = t->n) printf("%d <-> ", t->d); printf("NULL\n"); }
        if (c == 3) {
            printf("Val: "); scanf("%d", &v); i = 1;
            for (N *t = h; t; t = t->n, i++) if (t->d == v) printf("Found at pos %d\n", i);
        }
        if (c == 4) printf("Val & Pos: "), scanf("%d%d", &v, &p), ins(v, p);
        if (c == 5) printf("Pos: "), scanf("%d", &p), del(p);
    }
}