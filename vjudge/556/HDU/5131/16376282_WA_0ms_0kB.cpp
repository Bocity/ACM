#include <bits/stdc++.h>
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
typedef long long ll;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
struct node {
    string name;
    int rank;
} s[maxn];
bool cmp(node x, node y) {
    if (x.rank == y.rank) {
        return x.name < y.name;
    }
    return x.rank > y.rank;
}
vector<int> q;
map<int, int> vis;
map<string,int> viss;
map<string,int> visss;
int main() {
    while (cin >> n && n) {
        vis.clear();
        viss.clear();
        visss.clear();
        q.clear();
        REP(i, 0, n) {
            cin >> s[i].name >> s[i].rank;
            viss[s[i].name] = s[i].rank;
            if (!vis[s[i].rank]) {
                q.push_back(s[i].rank);
            }
            vis[s[i].rank]++;
        }
        sort(s, s + n, cmp);
        for(int i = 0; i < n; ++i){
            cout << s[i].name << " " << s[i].rank << endl;
            visss[s[i].name] = i + 1;
        }
        cin >> m;
        string ch;
        REP(i,0,m){
            cin >> ch;
            if (vis[viss[ch]] == 1){
                cout << visss[ch] << endl;
            }else{
                int x = lower_bound(q.begin(),q.end(),viss[ch]) - q.begin() + 1;
                int y = 0;
                for(int j = 0; j < n; ++j){
                    if (s[j].name == ch){
                        y ++;
                        break;
                    }
                    if (s[j].rank == viss[ch]){
                        y++;
                    }
                }
                if (y == 1){
                    cout << x - 1 << endl;
                    continue;
                }
                cout << x - 1 << " " << y << endl;
            }
        }
    }
    return 0;
}
