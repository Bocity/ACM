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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    int n;
    int a[] = {1, 2, 4, 7, 15};
    vector<int> v;
    while (cin >> n) {
        v.clear();
        PER(i, 0, 5) {
            if (n - a[i] > 0) v.push_back(n - a[i]);
        }
        cout << v[0];
        for (int i = 1; i < v.size(); i++) cout << " " << v[i];
        cout << endl;
    }
    return 0;
}