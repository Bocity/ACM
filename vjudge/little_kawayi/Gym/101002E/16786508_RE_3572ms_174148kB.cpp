#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ll long long
const int N = 4e6 + 10;
const int p = 998244353, G = 3, Gi = 332748118;
struct NTT {
    ll a[N], b[N], c[N];
    int r[N];
    inline ll fastpow(ll x, ll n) {
        ll ans = 1;
        while (n) {
            if (n & 1) ans = ans * x % p;
            x = x * x % p;
            n >>= 1;
        }
        return ans;
    }
    void ntt(ll *a, int n, int op) {
        REP(i, 0, n) if (i < r[i]) swap(a[i], a[r[i]]);
        for (int i = 1; i < n; i <<= 1) {
            ll wn = fastpow(op == 1 ? G : Gi, (p - 1) / (i << 1));
            for (int j = 0; j < n; j += (i << 1)) {
                ll w = 1;
                for (int k = 0; k < i; k++, w = w * wn % p) {
                    int x = a[j + k], y = w * a[j + k + i] % p;
                    a[j + k] = (x + y) % p;
                    a[j + k + i] = (x - y + p) % p;
                }
            }
        }
    }
    void calc(int *A, int *B, int *C, int n, int m) {
        REP(i, 0, n) a[i] = (A[i] + p) % p;
        REP(i, 0, m) b[i] = (B[i] + p) % p;
        int L = 0, limit = 1;
        while (limit <= n + m) limit <<= 1, L++;
        n = limit;
        REP(i, 0, n) r[i] = (r[i >> 1] >> 1) | ((i & 1) << L - 1);
        ntt(a, n, 1), ntt(b, n, 1);
        REP(i, 0, n) c[i] = a[i] * b[i] % p;
        ntt(c, n, -1);
        ll inv = fastpow(n, p - 2);
        REP(i, 0, n) C[i] = c[i] * inv % p;
    }

} ntt;

int A[N], B[N], C[N << 1];
int n, m;
int main() {
    string c;
    cin>>c;
    int n = 2*c.size(),m=c.size();
    memset(A,0,sizeof A);
    memset(B,0,sizeof B);
    memset(C,0,sizeof C);
    for(int i=0;i<c.size();i++)
    {
        if(c[i]=='A')
            A[i+c.size()] = 1;
            else
                B[-i+c.size()]=1;
    }

        ntt.calc(A, B, C, n + 1, m + 1);
        int p=n+m+1;
        for(int i=1;i<c.size();i++)
            cout<<C[c.size()*2+i]<<endl;

}
