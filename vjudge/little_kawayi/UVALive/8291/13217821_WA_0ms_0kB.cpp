#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++ i)
#define endl "\n"
typedef unsigned long long ll;
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
	f[0] = 1LL;
	f[1] = 2LL;
	f1[1] = 2LL;
	f1[2] = 16LL;
	f2[1] = 1LL;
	f2[2] = 8LL;
	f3[1] = 0LL;
	f3[2] = 4LL;
	REP(i,2,2000){
		f[i] = f[i-1] * 2LL + f[i-2] * 7LL + ((i-3 < 0)? 0 : f[i-3] * 8LL);
	}
	REP(i,3,2000){
		f1[i] =  f1[i-1] * 2LL+ f1[i-2] * 7LL + f1[i-3] * 8LL + 2LL * f[i-1] + 8LL * f[i-2] + 8LL * f[i-3];
		f2[i] =  f2[i-1] * 2LL + f2[i-2] * 7LL + f2[i-3] * 8LL + f[i-1] + 4LL * f[i-2] + 8LL * f[i - 3];
		f3[i] =  f3[i-1] * 2LL + f3[i-2] * 7LL + f3[i-3] * 8LL + 4LL * f[i-2] + 8LL * f[i-3];
	}

	while(t--){
		stay();
	}
	return 0;
}