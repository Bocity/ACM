#include <iostream>
using namespace std;
int read() {
    int n = 0, f = 1;
    char ch;
    ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return f * n;
}
int main() {
    int n, k, x, tot;
    n = read();
    k = read();
    for (int i = 1; i <= n; i++) {
        x = read();
        if (x + k <= 5) tot++;
    }
    printf("%d", tot / 3);
    return 0;
}