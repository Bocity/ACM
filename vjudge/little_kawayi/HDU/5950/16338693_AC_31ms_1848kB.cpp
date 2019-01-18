#include <bits/stdc++.h>
#define REP(i,x,n) for(ll i = (x); i < (n); ++i)
#define PER(i,x,n) for(ll i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
const ll mod = 2147493647;
const ll maxn = 100000 + 10;
const ll N = 105;
const ll M = 2147493647;
class Matrix {
public:
    ll n, m;
    ll mat[N][N];
    ll quickPow(ll A, ll n, ll m) {
        if(n == 0 || A == 1) return 1;
        ll ret = 1;
        while(n != 0) {
            if(n & 1) ret = ret * A % m;
            A = A * A % m;
            n >>= 1;
        }
        return ret;
    }
    ll inv(ll a) {
        return quickPow(a, M - 2, M);
    }
    Matrix(ll row = N, ll col = N) : n(row), m(col) {
        memset(mat, 0, sizeof(mat));
    }
    void unit() {
        m = n;
        for(ll i = 0; i < n; i++) mat[i][i] = 1;
    }
    Matrix &operator = (const Matrix &x) {
        n = x.n, m = x.m;
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) mat[i][j] = x.mat[i][j];
        }
        return *this;
    }
    Matrix operator + (const Matrix &x) {
        Matrix t(n, m);
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                t.mat[i][j] = (mat[i][j] + x.mat[i][j] + M) % M;
            }
        }
        return t;
    }
    Matrix operator - (const Matrix &x) {
        Matrix t(n, m);
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                t.mat[i][j] = (mat[i][j] - x.mat[i][j] + M) % M;
            }
        }
        return t;
    }
    Matrix operator * (const Matrix &x) {
        Matrix t(n, x.m);
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                if(mat[i][j] == 0) continue;
                for(ll k = 0; k < x.m; k++) {
                    if(x.mat[j][k] == 0) continue;
                    t.mat[i][k] = (t.mat[i][k] + mat[i][j] * x.mat[j][k] % M) % M;
                }
            }
        }
        return t;
    }
    Matrix operator * (const ll &x) {
        Matrix t(n, m);
        for(ll i = 0; i < n; i++ ) {
            for(ll j = 0; j < m; j++) t.mat[i][j] = mat[i][j] * x % M;
        }
        return t;
    }
    Matrix operator / (const ll &x) {
        Matrix t(n, m);
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) t.mat[i][j] = (mat[i][j] * inv(x)) % M;
        }
        return t;
    }
    Matrix operator ! () {
        Matrix t(n, m);
        for(ll i = 0; i < m; i++) {
            for(ll j = 0; j < n; j++) t.mat[i][j] = mat[j][i];
        }
        return t;
    }
    friend Matrix quickPow(Matrix tmp, ll x) {
        Matrix ret(tmp.n, tmp.m);
        ret.unit();
        if(x == 0) return ret;
        while(x) {
            if(x & 1) ret = tmp * ret;
            tmp = tmp * tmp;
            x >>= 1;
        }
        return ret;
    }
    void read() {
        mat[0][0] = 1, mat[0][1] = 2, mat[0][2] = 1, mat[0][3] = 0, mat[0][4] = 0, mat[0][5] = 0, mat[0][6] = 0;
        mat[1][0] = 1, mat[1][1] = 0, mat[1][2] = 0, mat[1][3] = 0, mat[1][4] = 0, mat[1][5] = 0, mat[1][6] = 0;
        mat[2][0] = 0, mat[2][1] = 0, mat[2][2] = 1, mat[2][3] = 4, mat[2][4] = 6, mat[2][5] = 4, mat[2][6] = 1;
        mat[3][0] = 0, mat[3][1] = 0, mat[3][2] = 0, mat[3][3] = 1, mat[3][4] = 3, mat[3][5] = 3, mat[3][6] = 1;
        mat[4][0] = 0, mat[4][1] = 0, mat[4][2] = 0, mat[4][3] = 0, mat[4][4] = 1, mat[4][5] = 2, mat[4][6] = 1;
        mat[5][0] = 0, mat[5][1] = 0, mat[5][2] = 0, mat[5][3] = 0, mat[5][4] = 0, mat[5][5] = 1, mat[5][6] = 1;
        mat[6][0] = 0, mat[6][1] = 0, mat[6][2] = 0, mat[6][3] = 0, mat[6][4] = 0, mat[6][5] = 0, mat[6][6] = 1;
    }
    void write() {
        for(
            ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                printf("%lld%c", mat[i][j], " \n"[j == m - 1]);
            }
        }
    }
};
// ll main() {
//     Matrix t(7, 7);
//     t.read();
//     for(ll i = 2; i < 5; i++) {
//         Matrix tmp = quickPow(t, i);
//         tmp.write();
//         prllf("\n");
//     }
//     return 0;
//
int  main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    Matrix t(7, 7);
    t.read();
    while(T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if(n == 1) {
            cout << a << endl;
            continue;
        }
        if(n == 2) {
            cout << b << endl;
            continue;
        }
        Matrix tmp;
        tmp.mat[0][0] = b, tmp.mat[1][0] = a, tmp.mat[2][0] = 81;
        tmp.mat[3][0] = 27, tmp.mat[4][0] = 9, tmp.mat[5][0] = 3, tmp.mat[6][0] = 1;
        Matrix ans = quickPow(t, n - 2) * tmp;
        cout << ans.mat[0][0]%M << endl;
    }
    return 0;
}
