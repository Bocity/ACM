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
//ll n, m, k;
const long long mod = 1000000007;
typedef pair<int,int> pii;
int x,y,z,d,n;
bool vis[10485760]{0};
int a[1005];
void stay(){
    int pos = -1,ans = 0;
    REP(i,0,n){
        cin >> a[i];
    }
    REP(i,1,n){
        if (abs(a[i] - a[i-1]) > d){
            if (i == n-1){
                ans ++;
               // cout << "fuck";
                continue;
            }
            if (abs(a[i + 1] - a[i]) > d ){
                if (abs(a[i + 1] - a[i - 1]) > 2 * d){
                    cout << "N" << endl;
                    return;
                }else{
                    ans ++;
                    i++;
                }
            }else if (abs(a[i + 1] - a[i]) <= d){
                ans ++;
            }
        }
    }
    if (ans > 1){
        cout << "N" << endl;
    }else{
        cout << "Y" << endl;
    }
}
int main() {
    int t;
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << (1 << 20);
    while(cin >> n  && n != 0){
        cin >> d ;
        stay();
    }
    return 0;
}

