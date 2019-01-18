#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<queue>  
using namespace std;  
const int maxn=111;  
struct node  
{  
    int x;  
    int y;  
    int key;  
    int ans;  
};  
int n,m,sx,sy,movex[4]={1,-1,0,0},movey[4]={0,0,1,-1};  
char map[maxn][maxn];  
bool vis[maxn][maxn][21];  
queue<node> q;  
int GetNum(char op)  
{  
    switch(op)  
    {  
    case 'B':case 'b':return 0;  
    case 'Y':case 'y':return 1;  
    case 'R':case 'r':return 2;  
    case 'G':case 'g':return 3;  
    }  
}  
void BFS()  
{  
    while(!q.empty())  
    q.pop();  
    memset(vis,0,sizeof(vis));  
    q.push((node){sx,sy,0,0});  
    vis[sx][sy][0]=1;  
    while(!q.empty())  
    {  
    node v=q.front();  
    q.pop();  
    for(int i=0;i<4;i++)  
    {  
        int itx=v.x+movex[i];  
        int ity=v.y+movey[i];  
        if(map[itx][ity]=='#')  
        continue;  
        if(map[itx][ity]=='X')  
        {  
        printf("Escape possible in %d steps.\n",v.ans+1);  
        return;  
        }  
        int key=v.key;  
        if(map[itx][ity]>='A'&&map[itx][ity]<='Z')  
        {  
        int index=GetNum(map[itx][ity]);  
        if(key&(1<<index))  
        {  
           if(!vis[itx][ity][key])  
           {  
               q.push((node){itx,ity,key,v.ans+1});  
               vis[itx][ity][key]=1;  
           }  
             
        }  
        }  
        else if(map[itx][ity]>='a'&&map[itx][ity]<='z')  
        {  
        int index=GetNum(map[itx][ity]);  
        key=key|(1<<index);  
        if(!vis[itx][ity][key])  
        {  
            q.push((node){itx,ity,key,v.ans+1});  
            vis[itx][ity][key]=1;  
        }  
        }  
        else  
        {  
        if(!vis[itx][ity][key])  
        {  
            q.push((node){itx,ity,key,v.ans+1});  
            vis[itx][ity][key]=1;  
        }  
        }  
    }  
    }  
    printf("The poor student is trapped!\n");  
}  
int main()  
{  
    while(scanf("%d%d",&n,&m)&&(n+m))  
    {  
    for(int i=1;i<=n;i++)  
        scanf("%s",map[i]+1);  
    for(int i=0;i<=n+1;i++)  
        map[i][0]=map[i][m+1]='#';  
    for(int i=0;i<=m+1;i++)  
        map[0][i]=map[n+1][i]='#';  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=m;j++)  
        if(map[i][j]=='*')  
        {  
            sx=i;  
            sy=j;  
            break;  
        }  
    BFS();  
    }  
    return 0;  
}  