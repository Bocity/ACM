#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1000000;
int v[N + 1];
vector<int> vv[8];
long long prime[N] = {0}, num_prime = 0;
bool isNotPrime[N] = {true, true};
int psolve() {
    int n = sqrt(N * 1.0) + 2;
    for (long long i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            prime[num_prime++] = i;
        }
        for (long long j = 0; j < num_prime && i * prime[j] <= n; j++) {
            isNotPrime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return 0;
}
void solve() {
    int temp, temp2;
    for (int i = 2; i <= N; i++) {
        temp = sqrt(i * 1.0);
        for (int j = 0; j < num_prime && prime[j] <= temp; j++) {
            if (i % prime[j] == 0) {
                v[i]++;
            }
        }
        if (!v[i]) v[i] = 1;
        vv[v[i]].push_back(i);
    }
}
set<int> st;
int dp[10][10];
int main() {
    ios::sync_with_stdio(false);
    psolve();
    // cout << '!' << endl;
    solve();
    // cout << '!';
    // for (int i = 1; i <= N; i++) {
    //     cout << v[i] << " ";
    // }
    int t, x, y, m, g;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        m = 0;
        st.clear();
        for (int i = 1; i <= 7; i++) {
            g = lower_bound(vv[i].begin(), vv[i].end(), x) - vv[i].begin(); 
            if (vv[i][g] <= y) st.insert(i);
            if (vv[i][g + 1] <= y) m = i;
        }
        for (auto i : st) {
            for (auto j : st) {
                m = max(m, __gcd(i, j));
            }
        }
        cout << m << endl;
    }
    return 0;
}