#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int cas, fm;
    long double xs;
    long double cj;
    cin >> t;
    while (t--)
    {
        cin >> cas >> fm >> xs;
        long double mins = 1;
        int minfz = 0;
        int minfm = fm;
        for (int i = fm / 2; i < fm; i++)
        {
            int fz = i * xs + 0.5;
            cj = abs((long double)fz / i - xs);
            if (cj < mins)
            {
                minfz = fz;
                mins = cj;
                minfm = i;
            }
        }
        int gc = gcd(minfz,minfm);
        cout << cas << ' ' << minfz/gc << '/' << minfm/gc << endl;
    }
    return 0;
}
