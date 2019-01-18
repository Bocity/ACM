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
struct shu {
    int n;
    LL B[N] , C[N];
    void init(int size) {
        n = size;
        memset(B , 0 , N);
        memset(C , 0 , N);
    }
    inline LL _sum(LL* c , int x) {
        LL res = 0;
        for ( ; x > 0 ; x -= x & -x)
            res += c[x];
        return res;
    }
    void add(int l , int r , LL w) {
        for (int i = l ; i <= n ; i += i & -i)
            B[i] += w , C[i] += w * l;
        ++ r;
        for (int i = r ; i <= n ; i += i & -i)
            B[i] -= w , C[i] -= w * r;
    }
    LL sum(int l , int r) {
        LL res = 0; -- l;
        res += (r + 1) * _sum(B , r) - _sum(C , r);
        res -= (l + 1) * _sum(B , l) - _sum(C , l);
        return res;
    }
}Tree;
int t,n,x;
long s[520000];
long a[520000];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--)
    {
      //  cout<<T;
        Tree.init(N);
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        cin>>n;
        a[0]=0;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
 //           Tree.add(i,i,x);
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