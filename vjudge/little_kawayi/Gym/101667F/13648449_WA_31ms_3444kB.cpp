#include <bits/stdc++.h>
using namespace std;
pair<int, int> f(int x1, int x2,int x3,int x4,int z, int s,int y, int x,int k, int zds)//四个象限，左上右下坐标， 当前k值, 每象限点数 
{
	if (z == y)
		return pair<int, int>(z,s);
	int xx = 1;
	while (k > zds)
	{
		k -= zds;
		xx++;
	}
	if (xx == 1)xx = x1;
	if (xx == 2)xx = x2;
	if (xx == 3)xx = x3;
	if (xx == 4)xx = x4;
	if (xx == 1)
		return f(1,4,3,2,z,s+x+1>>1,z+y>>1,x,k,zds>>2);
	else if (xx == 2)
		return f(1,2,3,4,z,s,z+y>>1,s+x>>1,k,zds>>2);
	else if (xx == 3)
		return f(1,2,3,4,z+y+1>>1,s,y,s+x>>1,k,zds>>2);
	else
		return f(3,2,1,4,z+y+1>>1,s+x+1>>1,y,x,k,zds>>2);
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	
	pair<int, int> ans = f(1,2,3,4,1,1,n,n,k,n * n / 4);
	cout << ans.first << ' ' << n + 1 - ans.second << endl;
	return 0;
}