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
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
struct fuck {
    string a;
    fuck() {
        this->a = "";
    }
    fuck operator++(int) {
        string &temp = this->a;
        if (!temp.size() || *temp.rbegin() >= 'H') {
            bool cf = true;
            for (int i = temp.size() - 1; i >= 0; i--) {
                if (!cf) break;
                if (temp[i] == 'H') {
                    temp[i] = 'A';
                    cf = true;
                } else {
                    temp[i]++;
                    cf = false;
                }
            }
            if (cf) temp += 'A';
        } else
            temp[temp.size() - 1]++;
        return *this;
    }
};
int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        fuck you;
        REP(i, INF) {
            if (str.find(you.a) == string::npos) {
                cout << you.a << endl;
                break;
            }
            you++;
        }
    }
}