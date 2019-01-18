#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
using namespace std;
typedef long long ll;
#define maxn 10000000
#define MAX maxn
int pri[MAX+10],tot;
bool zs[MAX+10];
ll phi[MAX+10];
void pre()
{
    zs[1]=true;phi[1]=1;
    for(int i=2;i<=MAX;++i)
    {
        if(!zs[i])pri[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&pri[j]*i<=MAX;++j)
        {
            zs[i*pri[j]]=true;
            if(i%pri[j])phi[i*pri[j]]=phi[i]*phi[pri[j]];
            else{phi[i*pri[j]]=phi[i]*pri[j];break;}
        }
    }
    for(int i=1;i<=MAX;++i)phi[i]+=phi[i-1];
}
map<ll,ll> q;
// S[n] = n * (n + 1) / 2  -  \sum2..n S(n/i)
ll S(ll u) {
    if (u < maxn - 1) return phi[u];
    if (q[u]) return q[u];
    ll ans = u * (u + 1) / 2;
    for (ll l = 2, r; l <= u; l += r) {
        r = u / (u / l);
        ans -= (r - l + 1) * S(u / l);
    }
    return q[u] = ans;
}
ll n;
int main() {
    pre();
    cin >> n;
    cout << S(n) << endl;
    return 0;
}