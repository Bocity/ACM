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
    ios::sync_with_stdio(false);
    long long n;
    while (cin >> n && n != -1) {
        cout << n - 1 << endl;
    }
    return 0;
}