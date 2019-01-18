#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 200000 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int l = s.size();
    // bool flag = true;
    int spos = -1, bpos = -1;
    for(int i = 0, j = l - 1; i < l && j >= 0; i++, j--) {
        if(spos == -1 && s[i] != t[i]) spos = i;
        if(bpos == -1 && s[j] != t[j]) bpos = j;
        if(spos != -1 && bpos != -1) break;
        // if(spos != -1 && s[i] == t[i]) bpos = i - 1;
        // if(bpos != -1 && s[i] != t[1]) {
        //     cout << "NO" << endl;
        //     return 0;
        // }
    // cout << "i " << i << " j " << j << endl;
    }
    // cout << "spos " << spos << " bpos " << bpos << endl;
    if(spos == -1 && bpos == -1) {
        // cout << 2 << endl;
        cout << "YES" << endl;
    }
    else {
        string ss = s.substr(spos, bpos - spos + 1);
        string tt = t.substr(spos, bpos - spos + 1);
        reverse(ss.begin(), ss.end());
        // cout << ss << endl << tt << endl;
        if(ss == tt) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}