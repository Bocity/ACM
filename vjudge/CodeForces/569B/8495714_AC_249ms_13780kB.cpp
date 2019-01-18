#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
const double eps = 1e-8;
long long n,x;

int b[1000000],a[1000000],c[1000000];
int main()
{
cin>>n;
memset(a,0,sizeof(a));
for (int i=1;i<=n;i++)
{
    cin>>x;
    b[i]=x;
    a[x]++;
}
int ans=0;
for (int i=1;i<=n;i++)
{
    if (a[i]==0)
    {
        ans++;
        c[ans]=i;
    }
}
for (int i=1;i<=n;i++)
{
    if (a[b[i]]>1||b[i]>n)
    {
        a[b[i]]--;
        b[i]=c[ans];
        ans--;
    }

}
for(int i=1;i<=n;i++)
cout<<b[i]<<" ";
    return 0;
}