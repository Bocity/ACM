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
const int INF = 0x3f3f3f3f;
ll n, m, k;
const long long mod = 1000000007;
int a[10000];
string s;
int t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        s = s ;
        memset(a,0,sizeof a);
        REP(i,0,n){
            cin >> a[i];
        }
        int maxx1 = 0;
        int maxx2 = -1;
        while(maxx2 != maxx1){
            maxx2 = maxx1;
            for(int p = 0; p < n; ++p)
            for(int i = 0; i < n - 1 ; i ++ ){
                int ans = 0;
                int max1 = 0,max2 = 0;
                int pos2 = i + 1,pos1 = i;
                int ans1 = 0,ans2 = 0;
                if (s[i] == '(' && s[i + 1] == ')'){
                    ans = a[i] * a[i + 1];
                    if (i != 0 && s[i - 1] == '('){
                        int j = 0;
                        for(j = i - 1; j >= 0; j--){
                            if (j==')') break;
                            ans1 += a[i + 1] * a[j];
                            if (max1 < ans1){
                                max1 = ans1;
                                pos1 = j;
                                //cout << "sss" << max1 << endl;
                            }
                        }
                    }
                    if (s[i + 2] == ')'){
                        //cout << "fuck";
                        int j = 0;
                        for(j = i + 2; j < n; j++){
                            if (j=='(') break;
                            ans2 += a[i] * a[j];
                            if (max2 < ans2){
                                max2 = ans2;
                                pos2 = j;
                                //cout << "fuck" << max2 << endl;;
                            }
                        }
                    }
                   // cout << "fuck";
                }
                //cout << max1 << " " << max2 << " " << ans << endl;
                if (max1 + max2 + ans > 0){
                    maxx1 += max1 + max2 + ans;
                    swap(a[i],a[i + 1]);
                    swap(s[i],s[i + 1]);
                    REP(j,i + 1,pos2){
                        swap(a[j],a[j + 1]);
                        swap(s[j],s[j + 1]);
                    }
                    PER(j,pos1 + 1,i + 1){
                        swap(a[j],a[j - 1]);
                        swap(s[j],s[j - 1]);
                    }
                }
            }
        }
       // REP(i,0,n) cout << a[i] << " ";
        cout << maxx1 <<endl;
    }
    return 0;
}
