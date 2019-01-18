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
long double T,s,q;  
int ans=0,tt;
int main()
{
     cin>>T>>s>>q;
     double fin=s;
     ans=1;
     while(fin<T)
     {
        fin+=q*s;
        s = fin;
        ans++;
     }
     cout<<ans;
    // cout<<ceil(q*(T-s)/(T*(q-1)));
    return 0;
}