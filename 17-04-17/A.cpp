#include <algorithm>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
string a1, a2;
ll ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin >> a1;
    if (a1.length() == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < a1.length() - 1; i++) {
        if (a1[i] == 'V' && a1[i + 1] == 'K') {
            a1[i] = ' ';
            a1[i + 1] = ' ';
            ans++;
        }
    }
    for (int i = 0; i < a1.length() - 1; i++) {
        if (a1[i] == 'V' && a1[i + 1] == 'V') {
            a1[i] = ' ';
            a1[i + 1] = ' ';
            ans++;
            cout << ans;
            return 0;
        }
        if (a1[i] == 'K' && a1[i + 1] == 'K') {
            a1[i] = ' ';
            a1[i + 1] = ' ';
            ans++;
            cout << ans;
            return 0;
        }
    }
    cout << ans;

    return 0;
}