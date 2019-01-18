#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define LL long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1000000;
int t,n,x;
long s[520000],a[520000];
int main()
{
     ios::sync_with_stdio(false);
    cin>>t;
    while (t--)
    {
      //  cout<<T;
        memset(s,0,sizeof(s));
        cin>>n;
        a[0]=0;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
           a[i]+=a[i-1];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                //cout<<Tree.sum(i,j)<<"\n";
                s[a[j]-a[i]]+=j-i;
            }
        }    
        int p=a[n]-a[0];
        for(int i=0;i<=p;i++)
        {
            cout<<s[i]<<"\n";
        }    
    }
}