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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    REP(i,1,n+1){
        REP(j,1,m+1){
            if (i%2 ==0 && i % 4 !=0){
                cout << ((j==m)?"#":".");
            }else if (i % 4 ==0){
                cout << ((i%4 == 0 && j == 1)?"#":".");
            }else{
                cout << "#";
            }
        }
        cout << endl;
    }

    return 0;
}