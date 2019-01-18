#include <algorithm>
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
    long long n, m, ans;
    while (cin >> n) {
        if (n <= 7) {
            cout << n - 1 << endl;
            continue;
        }
        if (n > 7 && n % 4 == 0) {
            cout << 1 << endl;
            continue;
        }
        cout << n - 1 << endl;
    }
    return 0;
}