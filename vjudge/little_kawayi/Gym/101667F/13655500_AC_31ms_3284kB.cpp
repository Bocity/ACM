#include <bits/stdc++.h>
using namespace std;
int x = 0,y = 0;
void dfs(int n,int pos){
  if (n == 1){
    if (pos == 1){
      x++;
      y++;
    }
    else if(pos == 2){
      x++;
      y += 2;
    }
    else if (pos == 3){
      x += 2;
      y += 2;
    }
    else {
      x += 2;
      y ++;
    }
    return ;
  }
  int k = n / 2 * n / 2;
  if (pos > 3*k){
    dfs(n/2,pos - 3*k);
    int t = x;
    x = n / 2  + n / 2 - y + 1;
    y = n / 2 - t + 1;
  }
  else if (pos > 2 * k){
    dfs(n/2,pos - 2 *k);
    x += n/ 2;
    y += n/2;
  }else if (pos >  k ){
    dfs(n/2,pos-k);
    y += n / 2;
  }else{
    dfs(n/2,pos);
    swap(x,y);
  }

}
main(){
  int n,m;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  dfs(n,m);
  cout << x << " " << y;
  return 0;
}