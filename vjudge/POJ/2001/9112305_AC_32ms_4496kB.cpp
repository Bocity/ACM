#include <algorithm>
#include <cstring>
#include <iostream>
#define endl "\n"
#include <string>
using namespace std;
typedef long long ll;
const int MAX = 30004;
ll t, n;
string s, S[12002];
int mp[MAX][27];
bool mp2[MAX][27];
int main() {
    ios::sync_with_stdio(false);
    n = 1;
    memset(mp, 0, sizeof mp);
    memset(mp2, false, sizeof mp2);
    // freopen("1.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while (cin >> S[n]) {
        n++;
    }
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        int p = 0;
        for (int j = 0; j <= S[i].length() - 1; j++) {
            int t = S[i][j] - 'a';
            if (mp[p][t] == 0) {
                sum++;
                mp[p][t] = sum;
                p = sum;
            } else {
                mp2[p][t] = true;
                p = mp[p][t];
                continue;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << S[i] << " ";
        int p = 0;
        bool f = false;
        for (int j = 0; j <= S[i].length() - 1; j++) {
            int t = S[i][j] - 'a';
            if (f)
                break;
            else {
                if (!mp2[p][t]) {
                    cout << (char) (t + 'a');
                    f = true;
                } else {
                    cout << (char) (t + 'a');
                    p = mp[p][t];
                }
            }
        }
        cout << endl;
    }

    return 0;
}