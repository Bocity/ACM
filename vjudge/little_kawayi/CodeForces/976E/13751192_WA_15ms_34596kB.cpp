#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x; i < n; ++i)
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node{
  ll cha;
  ll hp;
  ll fuck;
  ll z;
}f[1000000];
bool cmp(node x,node y){
  return x.cha > y.cha;
}
main(){
  int a,b,c,n;
  cin >> n >> a >> b;
  ll pp = 1 << a;
  REP(i,0,n){
    cin >> f[i].hp >> f[i].fuck;
  }
  REP(i,0,n){
    f[i].z = pp * f[i].hp;
    f[i].cha = f[i].z - f[i].fuck;
    //cout << f[i].cha << " ";
  }
  sort(f,f+n,cmp);
  ull ans = 0;
  bool flag = false;
  REP(i,0,n){
    if (b <= 0){
      ans += f[i].fuck;
    }else{
      if (f[i].cha <= 0){
        ans += f[i].fuck;
      }else{
        if (!flag){
        flag = true;
        b--;
        ans += f[i].z;
        }else{
          b--;
          ans += f[i].hp;
          continue;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}