#include <bits/stdc++.h>
using namespace std;
int n,N;
int x[301];
int cost[301];
const int MAXN = 100000000;
int m[301];
int DP[301][1<<9];

int ans = MAXN;
int dp(int cur,int mask){
	if(cur == n+1){
		if(mask == (1 << N) -1) return 0;
		return MAXN;
	}
	int &ret = DP[cur][mask];
	if (ret!=-1) return ret;
	ret = MAXN;
	ret = min(ret,dp(cur+1,mask));
	ret = min(ret,dp(cur+1,mask |m[cur]) + cost[cur]);
	return ret;
}
int MAIN(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> cost[i];
	}
	for(int i =1; i <= n; ++i){
		vector<int > pFactors;
		int t = x[i];
		for(int j = 2; j*j <= t; ++j){
			if (t%j == 0){
				pFactors.push_back(j);
				while(t % j ==0) t/=j;
			}
		}
		if (t > 1){
			pFactors.push_back(t);
		}	
		N = pFactors.size();
		for(int j = 1; j <=n ; ++j){
			m[j] = 0;
			for(int k =0; k < N; ++k){
				if(x[j] % pFactors[k] != 0){
					m[j] |= (1 << k);
				}
			}
		}
		memset(DP,0xff,sizeof DP);
		ans = min(ans,cost[i] + dp(1,0));
	}
	if (ans == MAXN)
		ans = -1;
	cout << ans << endl;
	return 0;
}
		
int main(){
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);
	return MAIN();
	
