#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x; i < n; ++i)
using namespace std;
void stay(){
    int n,m,p;
    cin >> n >> m >> p;
    int now = n * m - 1;
    int cnt = 0;
    while(now > p){
        int tmp = (now - 1)/p + 1;
        cnt += tmp*(tmp-1)/2*(p-1);
        now -=tmp;
    }
    if(cnt & 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        stay();
    }
    return 0;
}