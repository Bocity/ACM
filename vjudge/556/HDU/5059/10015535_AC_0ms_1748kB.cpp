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
#include <sstream>
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
    // ios::sync_with_stdio(false);
    ll a, b;
    string str, sss;
    while (getline(cin, str)) {
        cin >> a >> b;
        cin.get();
        if (str[0] != '-') {
            REP(i, 0, str.size()) {
                if (str[i] > '9' || str[i] < '0') {
                    cout << "NO" << endl;
                    goto exit;
                }
            }
            if (str.size() > 10) {
                cout << "NO" << endl;
                continue;
            }
            istringstream i(str);
            ll temp;
            i >> temp;
            ostringstream o;
            o << temp;
            if (o.str() != str) {
                cout << "NO" << endl;
                goto exit;
            }
            if (temp <= b && temp >= a) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            REP(i, 1, str.size()) {
                if (str[i] > '9' || str[i] < '0') {
                    cout << "NO" << endl;
                    goto exit;
                }
            }
            if (str.size() > 11) {
                cout << "NO" << endl;
                continue;
            }
            istringstream i(str);
            ll temp;
            i >> temp;
            ostringstream o;
            o << temp;
            if (o.str() != str) {
                cout << "NO" << endl;
                goto exit;
            }
            if (temp <= b && temp >= a) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    exit:;
    }
    return 0;
}