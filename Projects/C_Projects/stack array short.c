#include <stdio.h>
int s[99], t = -1;

void push(int v) { if (t < 98) s[++t] = v; }
void pop() { if (t >= 0) printf("Popped: %d\n", s[t--]); else printf("Empty\n"); }

int main() {
    int c, v;
    while (printf("\n1.Push \n2.Pop \n3.Display \n4.Exit: "), scanf("%d", &c) && c != 4) {
        if (c == 1) printf("Val: "), scanf("%d", &v), push(v);
        if (c == 2) pop();
        if (c == 3) for (int i = t; i >= 0; i--) printf("%d ", s[i]);
    }
}