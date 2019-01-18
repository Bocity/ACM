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

__gnu_pbds::gp_hash_table<int, int> hash1;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
//        __gnu_pbds::cc_hash_table<int, int> hash1;
//unordered_map<int,int>hash1;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
string s1,s2;
const long long mod = 1000000007;
vector<int> a;
vector<int> b;
int main()
{
    int x;
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(cin >> n){
        int ans = 0;
        a.clear();
        b.clear();
        hash1.clear();
        REP(i,0,n){
            cin >> x;
            a.push_back(x);
            hash1[x]++;
        }
        b.push_back(a[0]);
        hash1[a[0]]--;
        ans = 1;
        REP(i,1,n){
                if (hash1[a[i]] > 0){
                    hash1[a[i]]--;
                   // cout << "---" << a[i] << " " << a[i] <<" "<< hash1[a[i]] << endl;
                    int t = b.size();
                    REP(j,0,t){
                        hash1[a[i] + b[j]]--;
                    }
                    b.push_back(a[i]);
                    ans ++;
                    if (ans*(ans-1)/2 == n-ans){
                        break;
                    }
                }
        }
        cout << b.size() << endl;
        cout << b[0] ;
        REP(i,1,b.size()){
            cout  << " " << b[i];
        }
        cout << endl;
    }
}