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
#define N 1300000
long long prime[N] = {0}, num_prime = 0;
bool isNotPrime[N] = {true, true};
ll cnt[N];
ll num[N];
int solve() {
    cnt[1] = cnt[0] = 0;
    for (long long i = 2; i < N; i++) {
        if (!isNotPrime[i]) {
            prime[num_prime++] = i;
            cnt[i] = num_prime;
        } else
            cnt[i] = cnt[i - 1];
        for (long long j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return 0;
}
char v[100];
bool fuck(int n) {
    int temp = 0;
    while (n) {
        v[temp++] = n % 10;
        n /= 10;
    }
    for (int i = 0, j = temp - 1; i < j; i++, j--) {
        if (v[i] != v[j]) return false;
    }
    return true;
}
double ans[N];
void work() {
    ans[0] = 0;
    int temp;
    for (int i = 1; i < 10; i++) {
        num[i] = i;
        ans[i] = cnt[i] * 1.0 / num[i];
        temp = i;
        while(ans[--temp] > ans[i]) ans[temp] = ans[i]; 
    }
    for (int i = 10; i < N; i++) {
        num[i] = (fuck(i) ? 1 : 0) + num[i - 1];
        ans[i] = cnt[i] * 1.0 / num[i];
        temp = i;
        while(ans[--temp] > ans[i]) ans[temp] = ans[i]; 
    }
}
bool cmp(double a, double b) {
    return a > b;
}
int main() {
    double p, q;
    solve();
    work();
    while (cin >> p >> q) {
        int temp = upper_bound(ans, ans + N - 1, p / q) - ans - 1;

        // cout << p / q - ans[temp] << " " << p / q - ans[temp + 1] << endl;
        cout << temp << endl;
    }
    return 0;
}