#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++ i)
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn = 2005;
ll f[maxn];
ll f1[maxn];
ll f2[maxn];
ll f3[maxn];
void stay(){
	int num,n,m;
	cin >> num >> n;
	cout << num << ' ' << (n?f[n]:0)<< ' ' << f1[n] << ' ' << f2[n] << ' ' << f3[n] << endl;
	return ;
}
int main(){
	int t;
	cin >> t;
	f[0] = 1;
	f[1] = 2;
	f[2] = 11;
    f[3] = 44;
	f1[1] = 2;
	f1[2] = 16;
    f1[3] = 92;
	f2[1] = 1;
	f2[2] = 8;
    f2[3] = 50;
	f3[1] = 0;
	f3[2] = 4;
    f3[3] = 24;
	REP(i,4,40)
	{
	    f[i] = f[i-1] * 2 + f[i-2] * 7 + f[i-3] * 8 + f[i-4] * 2;
		f1[i] = f1[i-1] * 2 + f1[i-2] * 7 + f1[i-3] * 8 +               2 * f[i-1] + 8 * f[i-2] + 8 * f[i-3];
		f2[i] = f2[i-1] * 2 + f2[i-2] * 7 + f2[i-3] * 8 + f2[i-4] * 2 +     f[i-1] + 4 * f[i-2] + 8 * f[i-3] + 2 * f[i-4];
		f3[i] = f3[i-1] * 2 + f3[i-2] * 7 + f3[i-3] * 8 + f3[i-4] * 2 +              4 * f[i-2] + 8 * f[i-3] + 4 * f[i-4];
	}
	while(t--)
    {
		stay();
	}
	return 0;
}