#include <bits/stdc++.h>
#define endl "\n"
#define De puts("--------------")
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
typedef long long ll;
struct f{
    int id;
    int v;
    int type;
}aa[500000];
struct ans{
    int ans;
    int id;
}b[500000];
bool cmp(f x, f y){
    if (x.v == y.v){
        return x.type < y.type;
    }
    return  x.v < y.v;
}
bool cmp2(ans x, ans y){
    return x.id < y.id;
}
int main(){
    int n ,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    REP(i,0,n){
        cin >> aa[i].v;
        aa[i].id = i;
        aa[i].type = 0;
    }
    REP(i,0,m){
        cin >> aa[i + n].v;
        aa[i + n].id = i;
        aa[i + n].type = 1;
    }
    sort(aa,aa+n+m,cmp);
    int anss = 0;
    int pos = 0;
    REP(i,0,n+m){
        if (!aa[i].type){
            anss++;
        }else{
            b[pos].ans = anss;
            b[pos].id = aa[i].id;
            pos++;
        }
    }
    sort(b,b+m,cmp2);
    REP(i,0,m){
        cout << b[i].ans << " ";
    }
    return 0;
}