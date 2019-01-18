#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define REP(i, x, n) for (int i = (x); (i) < (n); i++)
#define PER(i, x, n) for (int i = (n) -1; (i) >= (x); i--)
#define DE puts("---------")
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef bitset<4005> Bitset;
// void stay(int n) {}
ll n, m;
void stay() {
    cin >> n >> m;
    if (m > n) {
        cout << n * n << endl;
        return;
    }
    if (n % m == 0) {
        cout << n * n << endl;
        return;
    }
    REP(i, 1, n) {
        if ((n * n - i * i) % m == 0) {
            cout << n * n - i * i << endl;
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        stay();
    }
    return 0;
}
