#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int n, k;
ll dp[20005]{0};
int f[30]{0};
ll sum[40005]{0};
string s, s1;
void check(){
        REP(i,1,n + 1) cout << dp[i] << " " ;
    cout << endl;
}
main() {
    ios::sync_with_stdio(0);
    cin >> k >> n;
    REP(i, 0, 26) {
        cin >> f[i];
    }
    cin >> s;
    cin >> s1;
    REP(i, 0, n) {
        if (s1[i] == s[0]) {
            dp[i + 1] = 1;
        }
    }

    sum[1] = dp[1];
    REP(i,2,n + 1){
        sum[i] = sum[i-1] + dp[i];
    }
    ll ans = 1;
    REP(i,1,k){
        REP(j,1,n + 1){
            if (s1[j - 1] != s[i]){
                dp[j] = 0;
                continue;
            }
            int p = max(1, j - f[s[i - 1] - 'A']);
            //cout << j <<" " << p <<" " << sum[p]<<endl;
            dp[j] = sum[p - 1];
        }
        sum[1] = dp[1];
        REP(j,2,n + 1){
            sum[j] = (dp[j] + sum[j-1]) % MOD ;
        }
       // check();
    }
    //REP(i,1,n + 1) cout << sum[i] << " ";
    cout << sum[n] << endl;
}
