#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <climits>
#include <cmath>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n,k,x,y,a[500][500],p,sum,ans;
int main()
{
    while(cin>>n>>k)
    {
        memset(a,0,sizeof(a));
        sum=0;
        ans=0;
        for(int i=1;i<n;i++)
        {
            cin>>x>>y;
            a[x][y]=1;
        }
        for(int p=1;p<=n;p++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if (a[i][k]!=0&&a[k][j]!=0)
            a[i][j]=1;
        }
        for(int i=1;i<=n;i++)
        {
            sum=0;
        for(int j=1;j<=n;j++)
        {
            if ((i!=j)&&a[i][j]==1) sum++;
        }
        if (sum==k) ans++;
        }
        cout<<ans<<"\n";
    }
}