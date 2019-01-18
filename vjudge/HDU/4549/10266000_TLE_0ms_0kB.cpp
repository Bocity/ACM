#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
int t;
const int N = 3;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
ll ans = 0;
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                ans += (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) / MOD;
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}
Mat operator^(Mat a, ll k) {
    if (k < 0) k = 0;
    Mat c;
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) c.mat[i][j] = (i == j);

    for (; k; k >>= 1) {
        if (k & 1) c = c * a;
        a = a * a;
    }
    return c;
}
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
ll a, b, c;
Mat x, y, z1, z2;
ll ans1, ans2;
int main() {
    ios::sync_with_stdio(false);
    x.mat[0][0] = 1, x.mat[0][1] = 1;
    x.mat[1][0] = 1, x.mat[1][1] = 0;
    while (cin >> a >> b >> c) {
        if (c == 1) {
            cout << b % MOD << endl;
            continue;
        }
        if (c == 0) {
            cout << a % MOD << endl;
            continue;
        }
        y.mat[0][0] = 1;
        y.mat[1][0] = 1;
        z1 = (x ^ (c - 2)) * y;
        ans2 = ans;
        ans = 0;
        z2 = (x ^ (c - 3)) * y;
        ans1 = ans;
        ans = 0;
        ll A = a, B = b;
        ll a2, b2;
        while (A < MOD) {
            A *= a;
        }
        a2 = A % MOD;
        while (B < MOD) {
            B *= b;
        }
        b2 = B % MOD;
        cout << (qpow(a2, ans1, MOD) * qpow(b2, ans2, MOD) % MOD) * (qpow(a, z2.mat[0][0], MOD)) * (qpow(b, z1.mat[0][0], MOD)) % MOD << endl;
    }

    return 0;
}