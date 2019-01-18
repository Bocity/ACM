#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000000,10240000000")
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 4e7 + 7;
const int maxd = 2e7 + 7;
const int mod = 998244353;
 
int phi[maxn], prim[maxn];
void get_ouler(int n) {
  memset(phi, 0, sizeof phi);
  phi[1] = 1;
  int id = 0;
  for(int i = 2; i < n; ++i) {
    if(!phi[i]) {
      phi[i] = i - 1;
      prim[id++] = i;
    }
    for(int j = 0; j < id && prim[j]*i < maxn; ++j) {
      if(i % prim[j]) {
        phi[i*prim[j]] = phi[i] * (prim[j]-1);
      } else {
        phi[i*prim[j]] = phi[i] * prim[j];
        break;
      }
    }
  }
}
ll ans[maxn];
void init() {
    ans[1] = 0;
    for(ll i = 1; i < maxn / 2; i++) {
        ans[i] = ans[i - 1] + phi[2 * i] / 2;
    }
}
int main() {
    get_ouler(maxn);
    init();
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
        // cout << ans[n] << endl;
    }
    return 0;
}