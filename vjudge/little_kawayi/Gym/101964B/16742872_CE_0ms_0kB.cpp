#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 100000 + 10;
void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void print(__int128 x)
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
     if(x > 9) print(x/10);
    putchar(x%10 + '0');
}
int main() {
    __int128 n, mod =(__int128)1<<64;
    // print(mod);
    // cout<<endl;
    int a,b,c;
    while(cin >> a >> b >> c)
    {
        // scan(b);
        // scan(c);
        getchar();
        scan(n);
        __int128 k;
        if(a==b&&a==c)
        {k=1;}
        else
        if(a==b||a==c||b==c)
        {
            k=2;

        }else
            k=6;
        __int128 ans1,ans2;
        ans1= (n)*(n-1)*(n-2);
        ans1/=6;
        if(n%2==0)
        {
            ans2 = (n/2)*(n/2-1)*(n/2-2);
            ans2 -= (n/2 -1)*(n/2-2)*(n/2-3);
            ans2/=6;
            ans2*=n;
        }else
        {
            ans2 = (n/2+1)*(n/2-1)*(n/2);
            ans2 -= (n/2)*(n/2-2)*(n/2-1);
            ans2/=6;
            ans2*=n;
        }
        // print(ans1);
        // cout << endl;
        // print(ans2);
        // cout << endl;
        print(((ans1-ans2)*k)%mod);
        cout<<endl;
    }
    return 0;
}