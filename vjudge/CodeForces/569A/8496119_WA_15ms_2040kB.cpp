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
long double T,t1,s,q;
long long ans,fin,TT,n,m;
int main()
{
     fin=0;
     cin>>T>>s>>q;
     cout<<ceil(q*(T-s)/(T*(q-1)));
    return 0;
}