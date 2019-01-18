#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9+7;
#define endl "\n"
const int maxn = 500;
int a[1000][1000],b[1000][1000],c[1000][1000],d[1000][1000],ans[2000][2000];
int main()
{
    int pos=0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1000;
    int  f = 1;
    int posx,posy;
    memset(a,0,sizeof a);
    for(int i = f; i < n; i += f)
    {
        posx=i;
        posy=0;
        for(int j=i; j< n; j++)
        {
            a[posx][posy]=1;
            posx++;
            posy++;
        }
        f++;
    }
    f = 2;
    memset(b,0,sizeof b);
    for(int i = f; i < n; i += f)
    {
        posx=i;
        posy=0;
        for(int j=i; j< n; j++)
        {
            b[posx][posy]=1;
            posx++;
            posy++;
        }
        f++;
    }
    f = 3;
    memset(c,0,sizeof c);
    for(int i = f; i < n; i += f)
    {
        posx=i;
        posy=0;
        for(int j=i; j< n; j++)
        {
            c[posx][posy]=1;
            posx++;
            posy++;
        }
        f++;
    }
    memset(d,0,sizeof d);
    f = 4;
    for(int i = f; i < n; i += f)
    {
        posx=i;
        posy=0;
        for(int j=i; j< n; j++)
        {
            d[posx][posy]=1;
            posx++;
            posy++;
        }
        f++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j]=a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-1-i+n]=b[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[(n-1-i)+n][n-1-j+n]=c[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[(n-1-j)+n][i]=d[i][j];

        }
    }
    cout<<2*n<<endl;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {

            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}