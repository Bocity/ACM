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
int vv[8][N + 1];
int prime[N] = {0}, num_prime = 0;
bool isNotPrime[N + 1] = {true, true};
int psolve() {
    int n = N;
    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            prime[num_prime++] = i;
        }
        for (int j = 0; j < num_prime && i * prime[j] <= n; j++) {
            isNotPrime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return 0;
}
void solve() {
    int temp, temp2;
    for (int i = 1; i <= 7; i++) vv[i][1] = (i == 1 ? 1 : 0);
    for (int i = 2; i <= N; i++) {
        temp = sqrt(i * 1.0);
        temp2 = i;
        if (!isNotPrime[i])
            v[i] = 1;
        else
            for (int j = 0; j < num_prime && prime[j] <= temp && prime[j] <= temp2; j++) {
                if (temp2 % prime[j] == 0) {
                    temp2 /= prime[j];
                    v[i]++;
                }
            }
        for (int j = 1; j <= 7; j++) {
            vv[j][i] = (v[i] == j ? vv[j][i - 1] + 1 : vv[j][i - 1]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    psolve();
    solve();
    int t, x, y, m, g;
    int st[10];
    cin >> t;
    while (t--) {
        cin >> x >> y;
        m = 1;
        mems(st, 0);
        int temp = 0;
        for (int i = 1; i <= 7; i++) {
            if (vv[i][y] - vv[i][x - 1] >= 1) st[temp++] = i;
            if (vv[i][y] - vv[i][x - 1] >= 2) {
                m = i;
            }
        }
        for (int i = 0; i < temp; i++) {
            for (int j = i + 1; j < temp; j++) {
                m = max(m, __gcd(st[i], st[j]));
            }
        }
        cout << m << endl;
    }
    return 0;
}