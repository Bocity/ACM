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
        cout << 0 << endl;
        return;
    }
    PER(i, 1, n * n + 1) {
        if ((i) % m == 0) {
            cout << i << endl;
            break;
        }
    }
    return;
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
