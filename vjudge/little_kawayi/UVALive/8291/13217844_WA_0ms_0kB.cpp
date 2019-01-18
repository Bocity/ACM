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
	f1[1] = 2;
	f1[2] = 16;
	f2[1] = 1;
	f2[2] = 8;
	f3[1] = 0;
	f3[2] = 4;
	REP(i,3,40)
	{
	    f[i] = f[i-1] * 2 + f[i-2] * 7 + f[i-3] * 8;
		f1[i] = f1[i-1] * 2 + f1[i-2] * 7 + f1[i-3] * 8 + 2 * f[i-1] + 8 * f[i-2] + 8 * f[i-3];
		f2[i] = f2[i-1] * 2 + f2[i-2] * 7 + f2[i-3] * 8 +     f[i-1] + 4 * f[i-2] + 8 * f[i-3];
		f3[i] = f3[i-1] * 2 + f3[i-2] * 7 + f3[i-3] * 8 +              4 * f[i-2] + 8 * f[i-3];
	}
	while(t--)
    {
		stay();
	}
	return 0;
}