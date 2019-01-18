#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < n; ++i)
using namespace std;
struct po{
    int x, y;
};
vector<po> q;
int a[100000];
int b[100000];
int t,m,n;
bool cmp(po x,po y){
    return x.x < y.y ;
}
void fuckstay(){
    q.clear();
    cin >> n;
    REP(i,0,n){
        cin >> a[i];
    }
    cin >> m;
    REP(i,0,m){
        cin >> b[i];
    }
    po o;
    REP(i,0,n){
        o.x = a[i];
        o.y = 1;
        q.push_back(o);
        REP(j,i + 1,n){
           o.x ^=  a[j]; 
           o.y = j - i + 1; 
           q.push_back(o);
        }
    }
    int ans ,anss ,pp;
    REP(j,0,m){
         ans = 100000000, anss = 0;
        REP(i,0,q.size()){
        pp = abs(b[j]-q[i].x);
        if (ans > pp){
            ans = pp;
            anss = q[i].y; 
        }else if(ans == pp){
            if (anss < q[i].y){
                anss = q[i].y;
            }
        } 
      }
          cout << anss << endl;
    }
    cout << endl;
}
int main(){
    cin.tie(0);
    cin >> t;
    while(t--){
        fuckstay();
    }
    return 0;
}