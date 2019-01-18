#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x; i < n; ++i)
using namespace std;
int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-') f= - 1;
        ch = getchar();
    }
    while(ch >='0' && ch <= '9'){
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;

}
int n,m,x = 0;
int main(){
    cin >> n;
    REP(i,0,n){
        cin >> m;
        if (m != 1) x++;
    }
    cout << x << endl;
    return 0;
}
