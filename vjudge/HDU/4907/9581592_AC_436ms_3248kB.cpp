#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define endl "\n"
int fl[300005] = {0};
int c[300005] = {0};
int flag[300005] = {0};

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
int firstGreatOrEqual(int n, int key) {
    // n + 1 个数
    int low = 0;
    int high = n;
    int mid = 0;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (key <= c[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low <= n ? low : -1;
}
int main() {
    int T, n, m, a, q;
    T = read();
    while (T--) {
        n = read();
        m = read();
        for (int i = 1; i <= n; i++) {
            a = read();
            flag[a] = T + 1;
        }
        int last = 0;
        for (int i = 1; i <= 200006; i++) {
            if (flag[i] != T + 1) {
                ++last;
                c[last] = i;
            }
        }
        for (int i = 1; i <= m; i++) {
            q = read();
            int l = 1, r = last, mid;
            mid = firstGreatOrEqual(last + 1, q);
            printf("%d\n", c[mid]);
        }
    }
    return 0;
}