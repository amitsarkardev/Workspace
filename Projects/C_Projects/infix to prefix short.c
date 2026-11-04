#include <stdio.h>
#include <string.h>

char s[99], res[99], a[99]; int t = -1, j = 0;
int p(char c) { return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0; }
void rev(char* str) { for (int i = 0, k = strlen(str) - 1; i < k; i++, k--) { char temp = str[i]; str[i] = str[k]; str[k] = temp; } }

int main() {
    printf("Infix: "); scanf("%s", a); rev(a);
    for (int i = 0; a[i]; i++) {
        if (a[i] == ')') a[i] = '('; else if (a[i] == '(') a[i] = ')';
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9')) res[j++] = a[i];
        else if (a[i] == '(') s[++t] = a[i];
        else if (a[i] == ')') { while (t >= 0 && s[t] != '(') res[j++] = s[t--]; t--; }
        else { while (t >= 0 && p(s[t]) > p(a[i])) res[j++] = s[t--]; s[++t] = a[i]; }
    }
    while (t >= 0) res[j++] = s[t--];
    res[j] = '\0'; rev(res);
    printf("Prefix: %s\n", res);
    return 0;
}