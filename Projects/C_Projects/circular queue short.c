#include <stdio.h>
int q[5], f = -1, r = -1, size = 5;

void in(int v) { if ((r + 1) % size != f) { r = (r + 1) % size; q[r] = v; if (f == -1) f = 0; } else printf("Full\n"); }
void de() { if (f != -1) { printf("Deleted: %d\n", q[f]); if (f == r) f = r = -1; else f = (f + 1) % size; } else printf("Empty\n"); }

int main() {
    int c, v;
    while (printf("\n1.Insert 2.Delete 3.Display 4.Exit: "), scanf("%d", &c) && c != 4) {
        if (c == 1) printf("Val: "), scanf("%d", &v), in(v);
        if (c == 2) de();
        if (c == 3 && f != -1) { int i = f; do { printf("%d ", q[i]); i = (i + 1) % size; } while (i != (r + 1) % size); }
    }
    return 0;
}