#include <bits/stdc++.h>
#define REP(i,x,n) for(int i= x;i < n; ++i)
#define endl "\n"
#define hash Hasdhfiuew
#define maxn  100005
#define N 100005
using namespace std;
typedef long long ll;
int n,m,k;
int L = 1, R = 0;
int pos[maxn];
int a[maxn];
int ans[maxn];
int prime[N],tot = 0;
bool vis[N] = {true,true};
vector<int> A[maxn];
vector<int> B[maxn];
void screen(){
    for(int i = 2; i < N; ++i){
        if (!vis[i]) prime[tot++] = i;
        for(int j = 0; j < tot && (ll) i * prime[j] < N;j ++){
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int t;
void stay(){
    cin >> n >> m;
    int sz = sqrt(n);
    REP(i,0,100005) B[i].clear();
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    REP(i,1,n + 1){
        for(auto &x:A[a[i]]){
            B[x].push_back(i);
        }
    }
    REP(i,0,m){
        int l,r,d;
        bool flag = 1;
        cin >> l >> r >> d;
        for(auto &x:A[d]){
            int p = upper_bound(B[x].begin(),B[x].end(),r) - upper_bound(B[x].begin(),B[x].end(),l - 1);
            int D = d;
            int ans = 0;
            //cout << x<<" " << p << endl;;
            while (D % x == 0){
                D /=x;
                ans ++;
            }
            if (p < ans){
                cout << "No" << endl;
                flag = 0;
                break;
            }
        }
        if (flag){
            cout << "Yes" << endl;
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << log2(1e5);
    screen();
    for(int i = 2; i < 1e5 + 1; ++i){
         int temp = i;
         int ppos = 0;
        while(temp > 1 && temp >= prime[ppos]){
            if (!vis[temp]) {A[i].push_back(temp);break;}
            while (temp % prime[ppos] == 0){
                temp /= prime[ppos];
                A[i].push_back(prime[ppos]);
            }
            ppos ++;
        }
    }
    cin >> t;
    while(t--){
        stay();
    }
    return 0;
}
/*
1
5 4
6 4 7 2 5
1 2 24
1 3 18
2 5 17
3 5 35
*/