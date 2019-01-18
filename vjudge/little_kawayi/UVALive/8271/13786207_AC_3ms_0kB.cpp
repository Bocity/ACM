#include<iostream> 
#include<cstring>
using namespace std;  
bool vis[10010];
int n,k,x,y,n1,n2,m;  
int graph[510][510],link[10010];  
bool Find(int x)
{
    for(int i=1;i<=n;i++){
          if(graph[x][i]&&!vis[i]){
              vis[i]=1;//为了下一条语句中调用find做准备的，以免重复 
              if(!link[i]||Find(link[i])){
                  link[i]=x;
                  return true;
              }
         }
    }
    return false;
}

int main()  
{    
    while (cin >> n1  && n1 != 0){
        cin >> n2 >> m;
        n = n1 + n2;
        memset(link,0,sizeof(link));  
        memset(graph,0,sizeof(graph));  
        for(int i=1;i<=m;i++){  
            cin>>x>>y;  
            x++;
            y++;
            y+= n1;
            graph[x][y]=1;  
        }  
        int ans=0;  
        for(int i=1;i<=n;i++){  
            memset(vis,0,sizeof(vis));  
            if(Find(i))  
                ans++;  
        }  
        cout<<ans<<endl;    
    }
} 