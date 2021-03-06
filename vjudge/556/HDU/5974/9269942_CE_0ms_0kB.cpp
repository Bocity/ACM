#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll a,b;
int main() {
    ios::sync_with_stdio(false);
    while(cin>>a>>b){
        bool flag =false;
        ll sum,ans,pp,gcd,x1,x2;
        if (a*a-4b>=0)
        for(int i=1;i<=a/2;i++){
            gcd = __gcd((ll)i,a-i);
            ans=a*a-4*b*gcd;
            if (ans<0) continue;
            pp=sqrt(a*a-4*b*gcd);
            if ((pp+(a&1))&1)
            continue;
            if (pp*pp!= a*a -4*b*gcd) 
                continue;
            x1=(a-pp)>>1;
            x2=(a+pp)>>1;
            if ((x1!=i)||(x2!=a-i)) continue;
            flag=true;
            break;
        }
        if (flag)
        cout<<x1<<" "<<x2<<endl;
        else
        cout<<"No solution"<<endl;
    }
    return 0;
}