#include <bits/stdc++.h>
#define next asjifhjasiufhjsew
#define REP(i,x,n) for(int i = x;i < n; ++i)
using namespace std;
const int maxn = 1e6+5;
int f[maxn];
int next[maxn];
void getnext(int len){      
    next[0] = next[1] = 0;
    REP(i, 1, len) {
        int j = next[i];
        while (j && f[i] != f[j]) j = next[j];
        next[i + 1] = f[i] == f[j] ? j + 1 : 0;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n; i ++){
        cin >> f[i];
    }
    reverse(f,f+n);
    getnext(n);
    int minx = 1e9+8;
    int x,y;
    for(int i = 1;i <= n; ++i){
        int kp = i-next[i] + n-i;
        if(minx > kp){
            x = n-i;
            y = i-next[i];
            minx = kp;
        }
    }
    cout << x << " "  << y << endl;
    return 0;
}