#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++ i)
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn = 20005;
ll f[maxn]{0};
ll f1[maxn]{0};
ll f2[maxn]{0};
ll f3[maxn]{0};
void stay(){
	int num,n,m;
	cin >> num >> n;
	cout << num << " " << f[n]<<" " << f1[n]<< " " << f2[n] << " " <<f3[n]<< endl;
	return ;

}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	f[0] = 1;
	f[1] = 2;
	f1[1] = 2;
	f1[2] = 14;
	f2[1] = 1;
	f2[2] = 7;
	f3[1] = 0;
	f3[2] = 4;
	REP(i,2,2000){
		f[i] = f[i-1] * 2 + f[i-2] * 7 + ((i-3 < 0)? 0 : f[i-3] * 8);
	}
	REP(i,3,2000){
		f1[i] =  f1[i-1] * 2 + f1[i-2] * 7 + f1[i-3] * 8 + 2 * f[i-1] + 8 * f[i-2] + 8 * f[i-3];
		f2[i] =  f2[i-1] * 2 + f2[i-2] * 7 + f2[i-3] * 8 + f[i-1] + 4 * f[i-2] + 8 * f[i - 3];
		f3[i] =  f3[i-1] * 2 + f3[i-2] * 7 + f3[i-3] * 8 + 4 * f[i-2] + 8 * f[i-3];
	}

	while(t--){
		stay();
	}
	return 0;
}