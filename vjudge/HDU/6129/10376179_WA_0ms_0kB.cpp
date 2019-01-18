#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#define REP(i, x, n) for (long long i = (x); i < (n); ++i)
#define PER(i, x, n) for (long long i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE(x) cout << "--------\n" << (x) << "----------\n"
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define testin freopen("test.in", "r", stdin)
#define testout freopen("test.out", "w", stdout)
#define MOD 2
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 1000150;
template <class T> void read(T &num) {
    char CH;
    bool F = false;
    num = 0;
    for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
        ;
    for (num = 0; CH >= '0' && CH <= '9'; num = num * 10 + CH - '0', CH = getchar())
        ;
    F && (num = -num);
}
char stk[600];
int tp = 0;
template <class T> inline void print(T p) {
    if (!p) {
        puts("0");
        return;
    }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
    putchar('\n');
}
const int N = 2;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}
Mat operator^(Mat a, ll k) {
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
int F[31][200005][3];
int ans = 200004;
int a[200005];
int b[200005];
Mat x, y, z, zz;
ll n, m;
void stay() {
    cin >> n >> m;
    memset(x.mat, 0, sizeof x.mat);
    memset(F, 0, sizeof F);
    memset(b, 0, sizeof b);
    memset(a, 0, sizeof a);
    REP(i, 0, n) {
        cin >> a[i];
    }
    REP(i, 0, n) {
        int x = a[i];
        int pos = 0;
        while (x != 0) {
            F[pos][i][0] = (x & 1);
            x >>= 1;
            pos++;
        }
    }
    ll an = log2(n);
    an = pow(2, an);
    ll endd = m % an;
    // cout << endd << endl;
    REP(pos, 0, 31) {
        REP(i, 0, n) {
            b[i] = F[pos][i][0];
        }
        F[pos][0][0] = b[0];
        REP(i, 1, n) {
            F[pos][i][0] = b[i] ^ b[max(int(i - endd), 0)];
        }
    }
    memset(b, 0, sizeof b);
    REP(i, 0, n) {
        PER(j, 0, 31) {
            b[i] = (b[i] << 1) | F[j][i][0];
        }
    }
    REP(i, 0, n - 1) {
        cout << b[i] << " ";
    }
    cout << b[n - 1] << endl;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        stay();
    }
    return 0;
}