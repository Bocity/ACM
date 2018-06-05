#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define endl "\n"
int a[300005] = {0};
int mx[300005], mn[300005];
int ans = 0;
inline int read() {
    int f = 1, n = 0;
    char c;
    c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n * f;
}
int main() {
    int n, m, rr, y0;
    while (scanf("%d%d", &n, &m) != EOF) {
        ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            if (a[i] == m) rr = i;
        }
        mx[0] = 0;
        mn[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > m) {
                mx[i] = mx[i - 1] + 1;
                mn[i] = mn[i - 1];
            } else {
                mx[i] = mx[i - 1];
                if (a[i] != m) mn[i] = mn[i - 1] + 1;
            }
        }
    }
    return 0;
}