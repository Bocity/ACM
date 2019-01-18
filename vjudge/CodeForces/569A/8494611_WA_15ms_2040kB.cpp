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
double T,t1;
long q,s,ans,fin,TT,n,m;
int E(double x)
{
    if ((x>0 &&x<eps)||(x<0 &&-x<eps)) return 0;
    return 1;
}
int main()
{
    double fin=0;
    cin>>T>>q>>s;
    fin=T-q;
    t1=(double)(s-1)/(double)s;
    double leave=T-q;
    //cout<<leave;
    //cout<<(leave/t1+0.5);
    //cout<<(leave/t1+0.5)/T;
    ans=ceil(((leave/t1)/T));
    cout<<ans;
    return 0;
}