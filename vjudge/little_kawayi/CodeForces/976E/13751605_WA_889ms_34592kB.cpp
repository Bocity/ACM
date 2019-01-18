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
bool cmp2(node x,node y){

  if (x.hp - x.fuck == y.hp - y.fuck){
    return x.hp > y.hp;
  }else{
    return x.hp - x.fuck > y.hp - y.fuck;
  }
}
bool cmp3(node x,node y){
  return x.hp > y.hp;
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
  //  cout << f[i].cha << " ";
  }
    sort(f,f+n,cmp);
  // ll ansss = 0;
  // ansss += f[0].z;
  // cout << f[0].z << endl;
  // REP(i,1,n){
  //   ansss += max(f[i].hp,f[i].fuck);
  //   cout << max(f[i].hp,f[i].fuck) << " ";
  // }
  // cout << endl;
  // cout << ansss << endl;

  ull ans = 0;
  bool flag = false;
  int pos = 0;
  REP(i,0,n){
    if (f[i].cha > 0 && b){
      ans += f[i].z;
      b--;
      pos = i;
      break;
    }else{
      ans+= f[i].fuck;
    }
  }
  if (b != 0)
  sort(f+pos+1,f+n,cmp2);
  else   sort(f+pos+1,f+n,cmp3);
  int pos2 = pos;
  pos = n;
  REP(i,pos2 + 1,n){
    if (b == 0){
      pos = i;
      break;
    }
    if (f[i].hp - f[i].fuck > 0 ){
      b--;
      ans += f[i].hp;
    }else{
      ans += f[i].fuck;
    }
  //  cout << ans << " ";
  }
  REP(i,pos,n){
    ans += f[i].fuck;
  }
  cout << ans << endl;
  return 0;
}