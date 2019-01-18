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
bool vis[500][500]{0};
string s[1000];
int f1[4]={1,-1,0,0};
int f2[4]={0,0,1,-1};
int n,m;
int dfs(int x,int y,int ff){
    int ans = 0 ;
    if (vis[x][y]) return 1;
    vis[x][y] = 1;
    REP(i,0,4){
        if (x+f1[i] >= 0 && x+f1[i] < n && y + f2[i] >=0 && y + f2[i] < m && s[x+f1[i]][y+f2[i]] == s[x][y] ){
            if (ff==1 && i ==0 ) continue;
            if (ff==2 && i ==3 ) continue;
            if (ff==0 && i ==1 ) continue;
            if (ff==3 && i ==2 ) continue;
            ans |= dfs(x+f1[i],y + f2[i],i);
            if (ans ) return 1;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    REP(i,0,n){
        cin >> s[i];
    }
    int ans = 0;
    REP(i,0,n){
        REP(j,0,m){
            if (!vis[i][j]){
                ans |= dfs(i,j,-1);
                if (ans){ cout << "Yes" << endl;return 0;}
            }
        }
    }
    cout << "No" << endl;
    return 0;
}