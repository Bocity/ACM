#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
const int S = 20; //随机算法判定次数，S越大，判错概率越小
ll mult_mod(ll a, ll b, ll mod) {
    return (a * b - (ll)(a / (long double) mod * b + 1e-3) * mod + mod) % mod;
}
//计算  x^n %c
ll pow_mod(ll x, ll n, ll mod) { // x^n%c
    if (n == 1) return x % mod;
    x %= mod;
    ll tmp = x;
    ll ret = 1;
    while (n) {
        if (n & 1) ret = mult_mod(ret, tmp, mod);
        tmp = mult_mod(tmp, tmp, mod);
        n >>= 1;
    }
    return ret;
}

//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(ll a, ll n, ll x, ll t) {
    ll ret = pow_mod(a, x, n);
    ll last = ret;
    for (int i = 1; i <= t; i++) {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1) return true; //合数
        last = ret;
    }
    if (ret != 1) return true;
    return false;
}

// Miller_Rabin()算法素数判定
//
bool Miller_Rabbin(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false; //偶数
    ll x = n - 1;
    ll t = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    for (int i = 0; i < S; i++) {
        ll a = rand() % (n - 1) + 1;         // rand()需要stdlib.h头文件
        if (check(a, n, x, t)) return false; //合数
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    ll t = n;
    ll p = 0;
    bool flag = 0;
    while(t > 0){
        ll x = t % 10;
        t /= 10;
        if (x == 3 || x == 4 || x == 7){
            flag = 1;
            break;
        }
        p *= 10;
        if (x == 6) x = 9;
        else if (x == 9) x = 6;
        p += x;
    }
    if (flag){
        cout << "no" << endl;
    }else{
        bool flag1 = Miller_Rabbin(n);
        bool flag2 = Miller_Rabbin(p);
        if (flag1 && flag2){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}