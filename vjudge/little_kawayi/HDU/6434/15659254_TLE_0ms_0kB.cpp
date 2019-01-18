
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
void Eular() {
    for(ll i = 1; i <= maxn; i++) phi[i] = i;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    phi[1] = 0;
    for(ll i = 2; i <= maxn; i++) {
        if(isPrime[i]) {
            for(ll j = i; j <= maxn; j += i) {
                isPrime[j] = false;
                phi[j] -= phi[j] / i;
            }
        }
    }
}
ll ans[maxn];
void init() {
    ans[1] = 0, ans[2] = 1, ans[3] = 1;
    for(ll i = 1; i < maxn / 2; i++) {
        ans[i] = ans[i - 1] + phi[2 * i] / 2;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Eular();
    init();
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
