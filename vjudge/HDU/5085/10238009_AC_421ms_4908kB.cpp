#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define endl "\n"
#define maxn 100000
#define N 1500015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
ll a, b, k, S, ans;
ll qpow(ll a, ll b) { // return a^b %p
    ll t = 1;
    for (a; b; b >>= 1LL, a = a * a)
        if (b & 1LL) t = t * a;
    return t;
}
struct qQ {
    ll a, b, k, S, i;
};
struct AA {
    ll ans, i;
};
struct kkk {
    ll f, i;
} f1[100005];
vector<AA> ANS;
vector<qQ> qq[20];
bool cmp(AA x, AA y) {
    return x.i < y.i;
}
bool cmp2(kkk x, kkk y) {
    return x.f < y.f;
}
long long f[100005];
long long ff[100005];
int main() {
    int len = 0;
    ios::sync_with_stdio(0);
    while (cin >> a >> b >> k >> S) {
        if (a == 0) break;
        len++;
        qQ x;
        x.a = a;
        x.b = b;
        x.k = k;
        x.S = S;
        x.i = len;
        qq[k].push_back(x);
    }
    REP(ii, 1, 16) {
        if (qq[ii].size() != 0) {
            k = ii;
            memset(f, 0, sizeof f);
            memset(ff, 0, sizeof ff);
            ans = 0;
            REP(i, 0, 100000) {
                ll p = i;
                while (p != 0) {
                    f[i] += qpow(p % 10, k);
                    ff[i] = f[i];
                    f1[i].f = f[i];
                    f1[i].i = i;
                    p /= 10;
                }
            }
            sort(f, f + 100000);
            sort(f1, f1 + 100000, cmp2);
            REP(jj, 0, qq[ii].size()) {
                ans = 0;
                a = qq[ii][jj].a;
                b = qq[ii][jj].b;
                S = qq[ii][jj].S;
                if (b < 100000) {
                    REP(i, a, b + 1) {
                        if (ff[i] == S) ans++;
                    }
                } else {
                    REP(i, a, 100000) {
                        if (ff[i] == S) {
                            // cout << i << endl;
                            ans++;
                        }
                        a = 100000;
                    }
                    REP(i, 0, 10000) {
                        if (i > b / 100000) break;
                        if (i != 0 && i < b / 100000 && i > a / 100000) {
                            // cout << i << endl;
                            ll anss = S - ff[i];
                            if (anss < 0) continue;
                            ll pos = lower_bound(f, f + 100000, anss) - f;
                            ll pos2 = upper_bound(f, f + 100000, anss) - f;
                            ans += pos2 - pos;
                            // cout << "---1--" << i << endl;
                            continue;
                        }
                        if (i == a / 100000 || i == b / 100000) {
                            // cout << i << endl;
                            ll anss = S - ff[i];
                            if (anss < 0) continue;
                            ll pos = lower_bound(f, f + 100000, anss) - f;
                            ll pos2 = upper_bound(f, f + 100000, anss) - f;
                            REP(kk, pos, pos2) {
                                if (i * 100000 + f1[kk].i >= a && i * 100000 + f1[kk].i <= b) {
                                    ans++;
                                }
                            }
                            // cout << "----2--" << i << endl;
                        }
                    }
                }
                AA ppp;
                // cout << ans << " " << ppp.i << endl;
                ppp.ans = ans;
                ppp.i = qq[ii][jj].i;
                ANS.push_back(ppp);
            }
        }
    }
    sort(ANS.begin(), ANS.end(), cmp);
    REP(i, 0, ANS.size()) {
        cout << ANS[i].ans << endl;
    }
    return 0;
}