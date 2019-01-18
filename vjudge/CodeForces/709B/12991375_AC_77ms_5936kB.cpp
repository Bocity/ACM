#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
long long a[500000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    REP(i,0,n){
        cin >> a[i];
    }
    sort(a,a+n);
    long long ans1,ans2,ans3,ans4;
    if (n == 1){
        cout << 0;
    }else if (n == 2){
        cout << min(abs(a[0]-m),abs(a[1]-m));
    }else{
        if (m <= a[0]){
            cout << abs(a[n-2]-m);
        }else if (m >= a[n-1]){
            cout << abs(a[1] - m);
        }else{
            ans1 = abs(m-a[1])*2 + abs(a[n-1] - m);
            ans2 = abs(m-a[1])+abs(a[n-1]-m)*2;
            ans3 = abs(m-a[n-2])*2+abs(a[0]-m);
            ans4 = abs(m-a[n-2])+abs(a[0]-m)*2;
            long long ans5 = min(min(ans1,ans2),min(ans3,ans4));
            if (m < a[n-1] && m >= a[n-2]){
                cout << min(ans5,abs(a[0]-m));
            }else if (m > a[0] && m <= a[1]){
                cout << min(ans5,abs(a[n-1]-m));
            }else{
                cout << ans5;
            }

        }
    }
    return 0;
}