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
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
const int maxn = 10005;
const long long mod = 1000000007;
int f1[] = {0,0,1,-1};
int f2[] = {1,-1,0,0};
int w[200];
int h[200];
int vis[200][200];
int a[200];
int c,H,W;
void fill(int x,int y,int ii,int fang){
    if (fang == -1){
        REP(i,x,w[i] + 1){
            REP(j,y,h[i] + 1){
                vis[i][j] = ii;
            }
        }
    }else{
        REP(i,x,h[i] + 1){
            REP(j,y,w[i] + 1){
                vis[i][j] = ii;
            }
        }
    }

}
bool check(int x,int y,int fang){
    if (fang == -1){
        REP(i,x,w[i] + 1){
            REP(j,y,h[i] + 1){
                if (vis[i][j]) return false;
            }
        }
    }else{
        REP(i,x,w[i] + 1){
            REP(j,y,h[i] + 1){
                if (vis[j][i]) return false;
            }
        }
    }
    return true;
}
bool dfs(int x,int y,int nn){
    bool flag = 0;
    if (nn == W * H){
        return true;
    }
    if (vis[x][y]) return false;
    REP(f,0,4){
        int xx = x + f1[f];
        int yy = y + f2[f];
        if (vis[xx][yy])continue;
        REP(i,0,c){
            if (a[i]){
                a[i]--;
                if (check(xx,yy,1)){
                    fill(xx,yy,i + 1,1);
                    flag |= dfs(xx,yy,nn + w[i] * h[i]);
                    if (flag) return true;
                }else if(check(xx,yy,-1)){
                    fill(xx,yy,i + 1,-1);
                    flag |= dfs(xx,yy,nn + w[i] * h[i]);
                    if (flag) return true ; 
                }else{
                    break;
                }
            }else{
                continue;
            }
            a[i] ++;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin >> W >> H;
    cin >> c;
    REP(i,0,c){
       cin >> a[i] >> w[i] >> h[i]; 
    }   
    bool flag = dfs(1,1,0);
    cout << (flag?"yes":"no") << endl;
}