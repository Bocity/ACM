

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
const ll mod = 1e9 + 7;
const ll maxn = 40000000 + 5;
ll phi[maxn+1];
bool isPrime[maxn+1];
int p[maxn];
void Eular()
{
    memset(p,0,sizeof p);
    p[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!p[i])
            for(int j=i;j<=maxn;j+=i)
            {
                if(!p[j])p[j]=j;
                p[j]=p[j]/i*(i-1);
            }
    }
}

ll ans[maxn];
void init() {
    ans[1] = 0, ans[2] = 1, ans[3] = 1;
    for(int i = 1; i < maxn / 2; i++) {
        ans[i] = ans[i - 1] + p[2 * i] / 2;
    }
}
#define endl "\n"
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Eular();
    init();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
