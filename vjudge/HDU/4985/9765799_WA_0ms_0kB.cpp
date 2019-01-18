#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
vector <int > q;
bool vis[100005];
int a[100005];
void print(){
    cout<<"(";
    for(int i=0;i<q.size()-1;i++){
        cout<< q[i]<<" ";
    }
    cout<<q[q.size()-1]<<")";
    q.clear();
}
void dfs(int x){
    if (vis[x]){
        print();
        return ;
    }
    vis[x]=true;
    q.push_back(x);
    dfs(a[x]);
    return ;
}
int n;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        memset(vis,0,sizeof vis);
        for(int i= 1;i<= n;i++){
            cin>>a[i];
        }
        for(int i=1 ;i<=a[i];i++){
            if (!vis[i]){
                dfs(i);
            }
        }
        cout<<endl;
    }
    return 0;
}