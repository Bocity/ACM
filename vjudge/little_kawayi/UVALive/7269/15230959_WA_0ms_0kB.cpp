#include<bits/stdc++.h>
using namespace std;
int a[505][506];
int fx[4][2]={0,1,1,0,0,-1,-1,0};
int maxnx,maxny;
void dfs(int num,int cnt,int fxx,int x,int y)
{
    //cout<<x<<" "<<y<<" "<<num<<" "<<cnt<<endl;
    if(num==-1&&cnt==-1)
        return;
    a[x][y]=num;
    cnt--;
    int nx=x+fx[fxx][0],ny=y+fx[fxx][1];
    if(cnt==0||nx==0||nx==(maxnx+1)||ny==0||ny==(maxnx+1)||a[nx][ny]!=0)
    {
        fxx++;
        fxx%=4;
    }nx=x+fx[fxx][0],ny=y+fx[fxx][1];
    if(cnt==0)
    {
        num-=2;
        cnt=num;
    }
    dfs(num,cnt,fxx,nx,ny);
}
struct node
{
    int x,y;
    node(int xx,int yy)
    {
        x=xx;y=yy;
    }
};
vector<node>ans[505];
//bool cmp(node a,node b)
//{
//    return a.x==b.x?(a.y<b.y)
//}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<505;i++)
            ans[i].clear();
        memset(a,0,sizeof a);
        maxnx=(n+1)/2;
        int js=n;
        if(n%2==0)
            js=n-1;
        dfs(js,js,0,1,1);
        for(int i=1;i<=maxnx;i++)
        {
            for(int j=1;j<=maxnx;j++)
//            {
//                cout<<a[i][j];
//            }
//            cout<<endl;
                ans[a[i][j]].push_back(node(i,j));
        }
        memset(a,0,sizeof a);
        int posx=1,posy=1;bool jc=1;
        for(int i=n/2*2;i>=2;i-=2)
        {

            if(jc==1)
            {
                for(int j=1;j<=i/2;j++)
                {
                    if(n%2==0)
                    {
                        ans[i].push_back(node(posx+n/2,posy+j-1));
                        ans[i].push_back(node(posx+1+n/2,posy+j-1));
                    }else
                    {
                        ans[i].push_back(node(posx,posy+j-1+n/2+1));
                        ans[i].push_back(node(posx+1,posy+j-1+n/2+1));
                    }
                    a[posx][posy+j-1]=i;
                    a[posx+1][posy+j-1]=i;
                }
                posx=posx+2;
                posy=i/2;
                jc=0;
            }else
            {
                for(int j=1;j<=i/2;j++)
                {
                    if(n%2==0)
                    {
                        ans[i].push_back(node(posx+j-1+n/2,posy));
                        ans[i].push_back(node(posx+j-1+n/2,posy-1));
                    }else
                    {
                        ans[i].push_back(node(posx+j-1,posy+n/2+1));
                        ans[i].push_back(node(posx+j-1,posy-1+n/2+1));
                    }
                    a[posx+j-1][posy]=i;
                    a[posx+j-1][posy-1]=i;
                }
                posy=1;
                jc=1;
            }
        }
        for(int i=2;i<=n;i+=2)
        {
            for(auto e:ans[i])
            swap(e.x,e.y);
        }
//        for(int i=1;i<=n/2*2;i++)
//        {
//            for(int j=1;j<=n/2*2+1;j++)
//                cout<<setw(3)<<a[i][j];
//            cout<<endl;
//        }
        if(n%2==0)
            cout<<n/2<<" "<<n+1<<endl;
        else
            cout<<n/2+1<<" "<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
//                for(int j=0;j<ans[i].size();j++)
//                    cout<<ans[i][j].x<<" "<<ans[i][j].y<<" ";
//                cout<<endl;
                for(int j=0;j<ans[i].size();j+=2)
                    cout<<ans[i][j].x<<" "<<ans[i][j].y<<" ";
                for(int j=ans[i].size()-1;j>=0;j-=2)
                     cout<<ans[i][j].x<<" "<<ans[i][j].y<<" ";
//                cout<<endl;
            }else

            for(auto e:ans[i])
            {
                cout<<e.x<<" "<<e.y<<" ";
            }

            cout<<endl;
        }
    }
}
