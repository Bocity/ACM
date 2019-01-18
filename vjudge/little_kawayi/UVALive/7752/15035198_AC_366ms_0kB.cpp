#include <bits/stdc++.h>
using namespace std;
int par[100001];
int aim[100001];
int ans;
void dfs(int x) {
	if(par[x] == 0) return ;
	ans++;
	dfs(par[x]);
	par[x] = 0;
}
int main() {
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n) {
		ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> par[i];
		for (int i = 1; i <= n; i++)
			cin >> aim[i];
		for(int i = 1; i <= n; i++) {
			if(par[i] != aim[i])
				dfs(i);
		}
		for(int i = 1; i <= n; i++) {
			if(par[i] != aim[i]) {
				ans++;
				dfs(aim[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}