#include <bits/stdc++.h>
#define REP(i,x,n) for(int i =(x); i < (n); ++i)
#define endl "\n"
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	ll n,m;
	ll ans = 0;
	REP(i,0,t){
		int x;
		ans = 0;
		cin >> x;
		cin >> 	n >> m;
		while(m != 0){
			ll p = m % n;
			ans += p*p;
			m -=p;
			m/=n;
		}
		cout << x << " " << ans << endl;
	}
	return 0;
}
