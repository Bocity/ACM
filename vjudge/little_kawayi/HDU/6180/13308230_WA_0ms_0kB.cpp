#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
struct node{
    int x;
    int y;
};
bool operator < (node x,node y){
    return x.y < y.x;
}
#define pii pair<int,int>
vector<pii> q;

int t;
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        q.clear();
        REP(i,0,n){
            int x,y;
            cin >> x >> y;
            q.push_back(pii(x,y));
        }
        sort(q.begin(),q.end());
        int ans = 0;
        int ans2 = 0;
        int ans3 = 0;
        priority_queue<int,vector<int>,greater<int>>p;
        priority_queue<int,vector<int>,less<int>>Q;
        REP(i,0,q.size()){
            if (!p.empty() && q[i].first > p.top()){
                while(!p.empty() && q[i].first > p.top()){
                    p.pop();
                    ans2++;
                }
            }else{
                //cout << "fuck";
                if (ans2!=0){
                    ans2--;
                }else{
                    ans++;
                    Q.push(q[i].first);
                }
            }
            p.push(q[i].second);
        }
        REP(i,0,ans){
            ans3+=p.top()-Q.top();
            p.pop();
            Q.pop();
        }
        cout << ans << " " << ans3 << endl;

        //cout << ans << endl;
    }
    return 0;
}