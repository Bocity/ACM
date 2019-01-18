	// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define llp(i,x,y) for(int i=x;i<y;++i) // [x,y) x->y
#define rlp(i,x,y) for(int i=y-1;i>=x;--i)  // [x,y) y->x
#define mem(a,x) memset(a,x,sizeof a)
#define REP(i,x,n) for(int i = x; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;

const ll MOD=1e9+7;
const ll N=1e5+50;
const ll INF=2e18;

ll qpower(ll x,ll p,ll M=MOD){ll ans=1;while(p){if (p&1) ans=ans*x%M;p>>=1;x=x*x%M;}return ans;}
ll gcd(ll a,ll b){ll x;while(b){x = a%b;a = b;b = x;}return a;}

ll modp(ll x,ll p = MOD){return (x%p+p)%p;} //常数较大
ll addp(ll x,ll y,ll p = MOD){return x+y>=p?x+y-p:x+y;}
ll subp(ll x,ll y,ll p = MOD){return x-y<0?x-y+p:x-y;}

const double eps=1e-9;
int ifloor(double x){return x>0?int(x+eps):int(x-eps);}//浮点数注意精度误差
bool fequal(double x,double y){return fabs(x-y) <= eps; }

typedef unsigned long long ull;
// typedef __int128 ull;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

// std::ios::sync_with_stdio(false);
// srand((unsigned)time(NULL));
int t;
const int maxn = 1e5 + 5;
double ans[maxn];
int main(){
  // ios::sync_with_stdio(0);
  // cin >> t;
  scanf("%d",&t);
  int cass = 0;
  int n;
  int anss = 0;
  while(t--){
    cass ++;
    anss = 0;
    scanf("%d",&n);
    ans[0] = 0;
    n++;
    REP(i,1,n){
      scanf("%lf",ans+i);
    }
    double fuck = ans[n - 1] - ans[n - 2];
    anss += 1;
    for(int i = n - 2; i >= 1; --i){
      if (ans[i] - ans[i - 1] >= fuck){
        int qq =  (int) (ans[i] - ans[i - 1] + fuck - 1) / (int)fuck;
        anss += qq;
        fuck = (ans[i] - ans[i - 1]) / qq;
      }else{
        fuck = ans[i] - ans[i - 1];
        anss += 1;
      }
    }
    printf("Case #%d: %d\n",cass,anss);
    // cout << "Case #" << cass << ": " << anss << endl;
  }
  return 0;
}