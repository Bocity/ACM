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
int xx[8] = {4, 16, 37, 58, 89, 145, 42, 20};
int find(int n) {
    for(int i = 0; i < 8; i++) {
        if(n == xx[i]) return 1;
    }
    return 0;
}
int f(int n) {
    int ans = 0;
    while(n) {
        int tmp = n%10;
        n/=10;
        ans += tmp * tmp;
    }
    return ans;
}
int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        n = f(n);
        if(find(n)) {
            cout << "UNHAPPY" <<endl;
            return 0;
        }
    }
    cout << "HAPPY" << endl;
    return 0;
}