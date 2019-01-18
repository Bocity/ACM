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
const int mod = 24 * 60;
const int maxn = 100000 + 10;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, m;
    double x;
    char c;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d UTC", &h, &m);
        scanf("%c", &c);
        scanf("%lf", &x);
        int tim = h * 60 + m;
        // cout << x - 8.0 << endl;
        if(c == '-') x *= -1;
        double add = round((x - 8.0) * 60);
        // cout << round(add) << endl;
        // cout << fixed << setprecision(6) << add << ' ' << (int)add << endl;
        tim = (tim + (int)add + mod) % mod;
        printf("%02d:%02d\n", tim / 60, tim % 60);
    }
    return 0;
}
/*
10
12 54 UTC-12
11 11 UTC+8
11 12 UTC+9
11 23 UTC+0
0 0 UTC-11.1
12 00 UTC-4
*/
