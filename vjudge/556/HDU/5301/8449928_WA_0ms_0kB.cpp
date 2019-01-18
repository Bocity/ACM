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
        ans=max((long long)ceil(min1/2.0),ans);
        }
        else
        {
        min1=max(min1-y,y-1);
        ans=max((long long)ceil(min1/2.0),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}