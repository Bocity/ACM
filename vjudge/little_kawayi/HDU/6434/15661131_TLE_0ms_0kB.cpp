#include <bits/stdc++.h>
#pragma GCC optimize(2)
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
bool isPrime[maxn+1];
int euler[maxn];
void Eular()
{
    for(int i=1;i<=maxn;i++)
    euler[i]=i;
    for(int i=2;i<=maxn;i+=2)
    euler[i]>>=1;
    for(int i=3;i<=maxn;i++)
    {
        if(euler[i]==i)
        {
            for(int j=i;j<=maxn;j+=i)
            euler[j]=(euler[j]/i)*(i-1);//先进行除法是为了防止中间数据的溢出
        }
    }
}

ll ans[maxn];
void init() {
    ans[1] = 0, ans[2] = 1, ans[3] = 1;
    for(int i = 1; i < maxn / 2; i++) {
        ans[i] = ans[i - 1] + euler[2 * i] / 2;
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
