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
long long prime[N] = {0}, num_prime = 0;
bool isNotPrime[N] = {true, true};
int psolve() {
    for (long long i = 2; i <= N; i++) {
        if (!isNotPrime[i]) {
            prime[num_prime++] = i;
        }
        for (long long j = 0; j < num_prime && i * prime[j] <= N; j++) {
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
        if (!isNotPrime[i])
            v[i] = 1;
        for (int j = 0; prime[j] <= temp; j++) {
            if (i % prime[j] == 0) {
                v[i]++;
            }
        }
        if (v[i] > 7) cout << i << endl;
    }
}
set<int> st;
int main() {
    ios::sync_with_stdio(false);
    psolve();
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
        for (int i = x; i <= y; i++) {
            if (st.find(v[i]) != st.end())
                m = max(m, v[i]);
            else
                st.insert(v[i]);
        }
        for (auto i : st) {
            for (auto j : st) {
                if (i != j) m = max(m, __gcd(i, j));
            }
        }
        cout << m << endl;
    }
    return 0;
}