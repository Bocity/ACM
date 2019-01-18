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
	cout << num << " " << f[n] << " " << f1[n] << " " << f2[n] << " " <<f3[n] << endl;
	return ;

}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	f[0] = 1;
	f[1] = 2;
	f1[1] = 2;
	f2[1] = 1;
	f3[1] = 0;
	REP(i,2,20000){
		f[i] = f[i-1] * 2 + f[i-2] * 7 + ((i-3 < 0)? 0 : f[i-3] * 8);
		// f1[i] = f1[i-1] + f[i-1] * 3 + f[i-2] * 8 + ((i-3 < 0)? 0 : f[i-3] * 8);
		// f2[i] = f2[i-1] + f[i-1] + f[i-2] * 4 + ((i-3 < 0)? 0 : f[i-3] * 8);
		// f3[i] = f3[i-1] + f[i-2] * 4 + ((i-3 < 0)? 0 : f[i-3] * 8);
		f1[i] =  f1[i-2] + f[i-2] * 16 + ((i-3 < 0)? 0 : f[i-3] * 8);
		f2[i] = f2[i-2] + f[i-2] * 8 + ((i-3 < 0)? 0 : f[i-3] * 8);
		f3[i] = f3[i-2] + f[i-2] * 4 + ((i-3 < 0)? 0 : f[i-3] * 8);
	} 
	while(t--){
		stay();
	}
	
	return 0;
}