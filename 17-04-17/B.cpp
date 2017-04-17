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
ll ans = 0;
string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    for (int i = 0; i <= s1.length() - 1; i++) {
        if (s1[i] < s2[i]) {
            cout << 0 - 1;
            return 0;
        }
    }
    for (int i = 0; i <= s1.length() - 1; i++) {
        if (s1[i] == s2[i]) {
            cout << s1[i];
            continue;
        }
        cout << s2[i];
    }

    return 0;
}