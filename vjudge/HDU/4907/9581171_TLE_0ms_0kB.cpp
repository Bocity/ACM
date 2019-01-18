#include <cstring>
#include <iostream>
using namespace std;
#define endl "\n"
int fl[200005] = {0};
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
    // ios::sync_with_stdio(false);
    int T, n, m, a, q;
    T = read();
    while (T--) {
        n = read();
        m = read();
        for (int i = 1; i <= n; i++) {
            a = read();
            fl[a] = T + 1;
        }
        for (int i = 1; i <= m; i++) {
            q = read();
            for (int j = q; j <= 200001; j++) {
                if (fl[j] != T + 1) {
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
    return 0;
}