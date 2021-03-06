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

int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool infer(int x) {
    if(x >= 0 && x <= 99) {
        if((x + 1000) % 4 == 0 && (x + 1000) % 400 != 0) return true;
    }
    return false;
}
bool mon(int x) {
    if(x >= 1 && x <= 12) return true;
    return false;
}
bool day(int x, int m, int y) {
    if(y) {
        if(m == 2) return x >= 1 && x <=29;
        else return x >= 1 && x <= d[m];
    }
    else {
        return x >= 1 && x <= d[m];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    int cnt = 1;
    while(t--) {
        int num = 0;
        cin >> s;
        int a = (s[1] - '0') + (s[0] - '0') * 10;
        int b = (s[4] - '0') + (s[3] - '0') * 10;
        int c = (s[7] - '0') + (s[6] - '0') * 10;
        if(infer(a)) {
            if(mon(b) && day(c, b, 1)) num++;
            if(mon(c) && day(b, c, 1)) num++;
        }
        if(infer(b)) {
            if(mon(a) && day(c, a, 1)) num++;
            if(mon(c) && day(a, c, 1)) num++;
        }
        if(infer(c)) {
            if(mon(a) && day(b, a, 1)) num++;
            if(mon(b) && day(a, b, 1)) num++;
        }
        if(!infer(a)) {
            if(mon(b) && day(c, b, 0)) num++;
            if(mon(c) && day(b, c, 0)) num++;
        }
        if(!infer(b)) {
            if(mon(a) && day(c, a, 0)) num++;
            if(mon(c) && day(a, c, 0)) num++;
        }
        if(!infer(c)) {
            if(mon(a) && day(b, a, 0)) num++;
            if(mon(b) && day(a, b, 0)) num++;
        }
        cout << "Case #" << cnt++ << ": " << num << endl;
    }
    return 0;
}