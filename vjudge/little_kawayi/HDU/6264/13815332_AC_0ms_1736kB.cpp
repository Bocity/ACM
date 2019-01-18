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
const int maxn = 1000000 + 10;
int r1[30], r2[30];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        memset(r1, 0, sizeof(r1));
        memset(r2, 0, sizeof(r2));
        for(int i = 0; i < s.size(); i++) {
            if(i % 2) r1[s[i] - 'a']++;
            else r2[s[i] - 'a']++;
        }
        int m1 = 0, m2 = 0;
        for(int i = 0; i < 26; i++) {
            m1 = max(m1, r1[i]);
            m2 = max(m2, r2[i]);
        }
        cout << s.size() - m1 - m2 << endl;
    }
    return 0;
}