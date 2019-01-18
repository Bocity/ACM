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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a = 0, b = 0, c = 0;
        int n, m, beg;
        cin >> n >> beg;
        for(int i = 0; i < n; i++) {
            cin >> m;
            if(m == 1) a++;
            else if(m == 2) b++;
            else c++;
        }
        bool f = false;
        if(n % 3 == 0) {
            if(a == n) f = true;
            if(a == n - 2 && b == 2) f = true;
            if(a == n - 2 && b == 1 && c == 1) f = true;
        }
        else if(n % 3 == 1) {
            if(a == n) f = true;
            if(a == n - 1) f = true;
            if(a == n - 2 && b) f = true;
        }
        else if(n % 3 == 2) {
            if(a == n || a == n - 1) f = true;
        }
        if(f) {
            if(beg == 1) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
        else {
            if(beg == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}