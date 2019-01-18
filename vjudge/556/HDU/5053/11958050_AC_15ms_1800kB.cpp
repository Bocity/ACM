#include <bits/stdc++.h>
using namespace std;
long long dp[20000];
int main() {
    long long a, b;
    int t;
    cin >> t;
    int cas = 1;
    dp[0] = 0;
    for (long long i = 1; i <= 10000; i++) {
        dp[i] = i * i * i + dp[i - 1];
    }
    while (t--) {
        long long ans = 0;
        cin >> a >> b;
        cout << "Case #" << cas++ << ": ";
        cout << dp[b] - dp[a - 1] << endl;
    }
}