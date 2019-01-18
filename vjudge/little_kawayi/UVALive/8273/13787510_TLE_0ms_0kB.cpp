#include<iostream>  
#include<stdio.h>   
#include<string.h>  
#define N 30  
#define next asfhisua
#define inf 0x3f3f3f3f  
using namespace std;  
  
int color[N]={0};  
int n;//n个点   
bool next[N][N]={0};   
int best;  
  
void dfs(int x)//给x号涂色   
{  
    if(x==n+1)  
    {  
        int sum=0;  
        /*for(int i=1;i<=n;i++) 
        { 
            cout<<color[i]; 
        } 
        cout<<endl;*/  
        int l[30]={0};  
        for(int i=1;i<=n;i++)  
        {  
            if(l[color[i]]==0)  
            {  
                l[color[i]]=1;  
                sum++;  
                //cout<<sum;  
            }  
        }  
        if(best>sum)best=sum;  
        return;  
    }  
    for(int i=1;i<=best;i++)  
    {  
        bool flag=1;  
        for(int j=1;j<=n;j++)  
        {  
            if(next[j][x]==1&&color[j]==i)  
            {  
                flag=0;  
                break;  
            }  
        }  
        if(flag==1)  
        {  
            color[x]=i;  
            dfs(x+1);  
            color[x]=0;  
        }  
    }  
}  
  
int main()  
{  
    int t;
    cin >> t;
    while(t--)  
    {  
        cin>>n;
        best=26;  
        int p = 0;
        cin >>p;
        for(int i = 0 ; i < p; ++ i){
            int xx,yy;
            cin >> xx >> yy;
            xx++;
            yy++;
            next[xx][yy] = 1;
            next[yy][xx] = 1;

        }
        dfs(1);  
        if(best<=3)  
        {  
            cout<<"Y"<<endl;  
        }  
        else  
        {  
            cout<<"N"<<endl;  
        }  
        memset(color,0,sizeof(color));  
        memset(next,0,sizeof(next));  
    }  
} 