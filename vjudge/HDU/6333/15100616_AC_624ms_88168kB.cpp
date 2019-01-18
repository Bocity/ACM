#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define N 100005
#define endl "\n"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll sum[1005][N]{0};
ll C[1005][1005]{0};
ll inv[N]{0};
void getInv(int n, int mod = MOD) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}

void getCom(int n) {
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

void getSum() {
    for (int i = 0; i <= 100000; ++i) {
        sum[0][i] = 1;
    }
    ll pre, cur;
    for (register int i = 1; i <= 100; ++i) {
        pre = 1;
        sum[i][0] = 1;
        cur = i * 1000;
        for (register int j = 1; j <= 100000; ++j) {
            if (j > cur)
                sum[i][j] = sum[i][j - 1];
            else {
                pre = pre * (cur - j + 1) % MOD * inv[j] % MOD;
                sum[i][j] = (sum[i][j - 1] + pre) % MOD;
            }
        }
    }
}
int t;
int main() {
    getInv(N - 1);
    getCom(1000);
    getSum();
    scanf("%d", &t);
    int n, m, wdh, wdhnb;
    while (t--) {
        scanf("%d%d", &n, &m);
        wdh = n % 1000;
        ll ans = 0;
        wdhnb = (n - wdh) / 1000;
        // cout << wdh << " " << (n - wdh) / 317 << endl;
        int fuck = max(m - wdh, 0);
        for (int i = m; i >= fuck; --i) {
            ans = (ans + sum[wdhnb][i] * C[wdh][m - i]) % MOD;
        }
        printf("%lld\n", ans);
    }
}
