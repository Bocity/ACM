#include<iostream>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int p[1005][1005];
int vis[1005];
int vis0[1005];
int n,m,x,y;
int bfs(int x){
    queue<int> q;
    while(!q.empty()){
        q.pop();
    }
    q.push(x);
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(p[x][i]==1&&vis0[i]==0){
                if(vis[i]==0){
                    q.push(i);
                    vis0[i]=1;
                    vis[i]=3-vis[x];
                }else if(vis[i]!=3-vis[x]){
                    return 0;
                }else if(vis[i]==3-vis[x]){
                    q.push(i);
                    vis0[i]=1;
                }
            }
        }
    }
    return 1;
}
int main(){
    while(cin>>n>>m>>x>>y){
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        memset(vis0,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            p[a][b]=1;
            p[b][a]=1;
        }
        for(int i=1;i<=x;i++){
            int a;
            cin>>a;
            vis[a]=1;
        }
        for(int i=1;i<=y;i++){
            int a;
            cin>>a;
            vis[a]=2;   
        }
        // for(int i=1;i<=n;i++){
        //     cout<<vis[i]<<" ";
        // }
        // cout<<endl;
        int ans=1;
        for(int i=1;i<=n;i++){
            int flag=0;
            for(int j=1;j<n;j++){
                if(p[i][j]){
                    flag=1;
                    break;
                }
            }
            if(!flag&&vis[i]==0){
                // cout<<"!"<<endl;
                ans=0;
                break;
            }
            if(vis[i]!=0&&vis0[i]==0){//当前点已被涂色
                vis0[i]=1;
                if(!bfs(i)){
                    ans=0;
                    // cout<<"1"<<endl;
                    break;
                }
            }//待优化
        } 
        if(ans!=0){
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    vis0[i]=1;
                    vis[i]=1;
                    if(!bfs(i)){
                        ans=0;
                        // cout<<"2"<<endl;
                        break;
                    }
                }
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    } 
    return 0;
}