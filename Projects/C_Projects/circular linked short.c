#include <stdio.h>
#include <stdlib.h>

typedef struct N { int d; struct N *n; } N;
N *h = NULL;

void ins(int v, int p) {
    N *x = malloc(sizeof(N)), *t = h; x->d = v;
    if (!h) { h = x->n = x; return; }
    if (p == 1) { while (t->n != h) t = t->n; x->n = h; h = t->n = x; return; }
    for (int i = 1; i < p - 1 && t->n != h; i++) t = t->n;
    x->n = t->n; t->n = x;
}

void del(int p) {
    if (!h) return;
    N *t = h, *q = NULL;
    if (p == 1) {
        while (t->n != h) t = t->n;
        if (t == h) { free(h); h = NULL; return; }
        t->n = h->n; free(h); h = t->n; return;
    }
    for (int i = 1; i < p && t->n != h; i++) { q = t; t = t->n; }
    if (q) { q->n = t->n; free(t); }
}

int main() {
    int c, v, p, i;
    while (printf("\n1.Create \n2.Display \n3.Search \n4.Insert \n5.Delete \n6.Exit: \n"), scanf("%d", &c) && c != 6) {
        if (c == 1) for (printf("Count: "), scanf("%d", &p), i = 0; i < p; i++) scanf("%d", &v), ins(v, 999);
        if (c == 2 && h) { N *t = h; do printf("%d -> ", t->d), t = t->n; while (t != h); printf("(HEAD)\n"); }
        if (c == 3 && h) {
            printf("Val: "); scanf("%d", &v); N *t = h; i = 1;
            do { if (t->d == v) { printf("Found at pos %d\n", i); break; } t = t->n; i++; } while (t != h);
        }
        if (c == 4) printf("Val & Pos: "), scanf("%d%d", &v, &p), ins(v, p);
        if (c == 5) printf("Pos: "), scanf("%d", &p), del(p);
    }
}