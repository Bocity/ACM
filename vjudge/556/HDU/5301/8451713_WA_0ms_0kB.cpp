#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <climits>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
long long n,m,T,x,y,min1,ans,flag;
int main()
{
    while(cin>>m>>n>>x>>y)
    {
        min1=min(m,n);
        if (min1==m)
        {
            ans=max(min1-x,x-1);
            int ans1=min(min1-x,x-1);
            if(ans1<=(long long)ceil(min1/2.0))
            ans=min((long long)ceil(min1/2.0),ans);
            else ans=max((long long)ceil(min1/2.0),ans);
        }
        else if(min1==n)
        {
            ans=max(min1-y,y-1);
            int ans2=min(min1-x,x-1);
             if(ans2<=(long long)ceil(min1/2.0))
            ans=min((long long)ceil(min1/2.0),ans);
            else ans=max((long long)ceil(min1/2.0),ans);
        }
       // if(m==n&&x==y&&x==m/2+1)cout<<m/2<<endl;
       // else 
        cout<<ans<<endl;
    }
    return 0;
}