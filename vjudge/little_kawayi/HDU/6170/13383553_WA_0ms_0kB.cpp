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
string s1,s2;
const long long mod = 1000000007;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        cin >> s1 >> s2;
        int j = 0;
        int flag = true;
        REP(i,0,s1.size()){
            if (s1[i]!=s2[j]&&s2[j]!='.' && s2[j]!='*'){
                flag =  false;
                break;
            }else{
                if (s2[j] == s1[i] || s2[j] == '.'){
                    j++;
                }else{
                    if (s2[j-1]!='.'){
                        if (i+1 < s1.size() && s1[i+1] == s1[i]){
                            while(i+1 < s1.size() && s1[i+1] == s1[i]){
                                i++;
                            }
                        }
                    }else{
                        if(s1[i-1]!=s1[i]){
                            flag = false;
                            break;
                        }
                    }
                    j++;
                }
            }
        }
        if (!flag){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }
    return 0;
}
