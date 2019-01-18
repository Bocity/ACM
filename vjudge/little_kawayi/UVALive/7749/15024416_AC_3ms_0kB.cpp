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
char x[maxn];
double dis(int a, int b) {
    double len = (double)(b - a);
    if((x[a] == 'S' && x[b] == 'T') || (x[a] == 'T' && x[b] == 'S')) {
        return sqrt((b - 0.5 - a) * (b - 0.5 - a) + (7.0 / 4.0 - sqrt(3.0))) + len + 2.0;
    }
    if((x[a] == 'S' && x[b] == 'C') || (x[a] == 'C' && x[b] == 'S')) {
        return (len + 0.5) * 2.0;
    }
    if((x[a] == 'T' && x[b] == 'C') || (x[a] == 'C' && x[b] == 'T')) {
        double tmp = sqrt(len * len + 1.0 - sqrt(3.0) / 2.0);
        double tmp2 = PI / 2.0 - atan((sqrt(3.0) / 2.0 - 0.5) / len) - acos(1.0 / (2.0 * tmp));
        return sqrt(len * len + 3.0 / 4.0 - sqrt(3.0) / 2.0) + (tmp2) / 2.0 + len + 0.5;
    }
    if(x[a] == 'S' && x[b] == 'S') {
        return (len + 1.0) * 2.0;
    }
    if(x[a] == 'T' && x[b] == 'T') {
        return len * 2.0 + 1.0;
    }
    if(x[a] == 'C' && x[b] == 'C') {
        return len * 2.0;
    }
}
int main() {
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; i++) cin >> x[i];
        double ans = 0;
        if (n == 1) {
            if (x[1] == 'T') ans = 3.0;
            else if (x[1] == 'S') ans = 4.0;
            else if (x[1] == 'C') ans = PI;
        }
        else {
            int num = 0;
            for(int i = 2; i < n; i++) {
                if(x[i] != 'T') num++;
            }
            if(num == 0) ans = dis(1, n);
            else if(num == 1) {
                int pos = -1;
                for(int i = 2; i < n; i++) {
                    if(x[i] != 'T') {
                        pos = i;
                        break;
                    }
                }
                ans = dis(1, pos) + dis(pos, n);
                if(x[pos] == 'S') ans -= 2.0;
            }
            else {
                int p1 = -1, p2 = n + 1;
                for(int i = 2; i < n; i++) {
                    if(x[i] != 'T') {
                        p1 = i;
                        break;
                    }
                }
                for(int j = n - 1; j > 1; j--) {
                    if(x[j] != 'T') {
                        p2 = j;
                        break;
                    }
                }
                ans = dis(1, p1)+ dis(p1, p2) + dis(p2, n);
                int cnt = 0;
                if(x[p1] == 'S') cnt++;
                if(x[p2] == 'S') cnt++;
                ans -= (double)(2.0 * cnt);
            }
            if (x[1] == 'C') ans += PI * 0.5;
            else ans += 1.0;
            if (x[n] == 'C') ans += PI * 0.5;
            else ans += 1.0;
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}