#include <stdio.h>
int s[99], t = -1;

int main() {
    char a[99];
    printf("Postfix (e.g. 53+): "); scanf("%s", a);
    for (int i = 0; a[i]; i++) {
        if (a[i] >= '0' && a[i] <= '9') s[++t] = a[i] - '0';
        else {
            int y = s[t--], x = s[t--];
            s[++t] = (a[i] == '+') ? x + y : (a[i] == '-') ? x - y : (a[i] == '*') ? x * y : x / y;
        }
    }
    printf("Result: %d\n", s[0]);
    return 0;
}