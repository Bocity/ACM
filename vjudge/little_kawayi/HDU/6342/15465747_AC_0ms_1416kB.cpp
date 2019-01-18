#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 10;
int infer(char c) {
    if(c == '+' || c == '*') return 1;
    return 0;
}
int r[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int l = s.size();
		s[l]='+';
		bool f = true;
        for(int i = 0; i < l; i++) {
            if(s[i] == '?') {
                if(i == 0) s[i] = '1';
                if(i == 1) {
                    if(s[0] == '0') s[i] = '+';
                    else s[i] = '1';
                }
                else {
                    if((s[i - 1] == '0' && isdigit(s[i - 2])) || s[i - 1] != '0') s[i] = '1';
                    else s[i] = '+';
                }
            }
        }
        for(int i= 0; i < l; i++) {
            if(i == 0) {
                if((s[i] == '0' && isdigit(s[i + 1])) || infer(s[i])) f = false;
            }
            else {
                if(infer(s[i]) && infer(s[i + 1])) f = false;
                if(s[i] == '0' && (infer(s[i - 1]) && isdigit(s[i + 1]))) f = false;
            }
        }
        if(f) {
            for(int i = 0; i < l; i++) cout << s[i];
            cout << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}