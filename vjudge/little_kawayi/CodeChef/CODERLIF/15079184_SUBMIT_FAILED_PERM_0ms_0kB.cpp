#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9+7;
const int maxn = 100 + 10;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x[maxn];
    cin >> t;
    while(t--) {
        for(int i = 1; i <= 30; i++) {
            cin >> x[i];
        }
        bool f = true;
        for(int i = 6; i <= 30; i++) {
            if(x[i - 5] == 1 && x[i - 4] == 1 && x[i - 3] == 1 && x[i - 2] == 1 && x[i - 1] == 1 && x[i] == 1) f = false;
        }
        if(!f) cout << "#coderlifematters" << endl;
        else cout << "#allcodersarefun" << endl;
    }
    return 0;
}