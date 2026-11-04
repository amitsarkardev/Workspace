#include <stdio.h>
int q[99], f = -1, r = -1;

void in(int v) { if (r < 98) { q[++r] = v; if (f == -1) f = 0; } }
void de() { if (f != -1) { printf("Deleted: %d\n", q[f++]); if (f > r) f = r = -1; } }

int main() {
    int c, v;
    while (printf("\n1.Insert 2.Delete 3.Display 4.Exit: "), scanf("%d", &c) && c != 4) {
        if (c == 1) printf("Val: "), scanf("%d", &v), in(v);
        if (c == 2) de();
        if (c == 3 && f != -1) for (int i = f; i <= r; i++) printf("%d ", q[i]);
    }
    return 0;
}