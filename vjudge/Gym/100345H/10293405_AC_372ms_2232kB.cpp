#include <bits/stdc++.h>
#define rep(i, k, n) for (int i = k; i <= n; i++)
using namespace std;

template <class T> void read(T &num) {
    char CH;
    bool F = false;
    for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
        ;
    for (num = 0; CH >= '0' && CH <= '9'; num = num * 10 + CH - '0', CH = getchar())
        ;
    F && (num = -num);
}
int stk[70], tp;
template <class T> inline void print(T p) {
    if (!p) {
        puts("0");
        return;
    }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
    putchar('\n');
}

const int N = 210;

int n, m, k, sum;
bitset<N> b[N], bit[N];

void update() {
    rep(i, 1, n) bit[i].reset();
    sum = 0;
    for (int i = n; i >= 1; i--) {
        bit[i].set(i);
        for (int j = 1; j < i; j++) {
            if (b[j][i]) bit[j] |= bit[i];
        }
        sum += bit[i].count();
    }
}

int main() {
    freopen("settling.in", "r", stdin);
    freopen("settling.out", "w", stdout);
    read(n), read(m);
    rep(i, 1, m) {
        int u, v;
        read(u), read(v);
        b[u].set(v);
    }
    update();
    print(sum - n);

    read(k);
    while (k--) {
        char op[2];
        int u, v;
        scanf("%s%d%d", op, &u, &v);
        if (op[0] == '+') {
            b[u].set(v);
            update();
            print(sum - n);
        } else if (op[0] == '-') {
            b[u].reset(v);
            update();
            print(sum - n);
        } else {
            if (bit[u].test(v))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}