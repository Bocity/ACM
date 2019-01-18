#include <bits/stdc++.h>
using namespace std;
//2 | 3
//--|--
//1 | 4
pair<int, int> dir(int k, int sl)//回到小一层变化，当前层k，当前层边长 
{
	if (sl == 1)
		return pair<int, int>(1, 1);
	pair <int, int> p = dir((k-1) % (sl * sl >> 2) + 1, sl>>1); //点在上层坐标
	switch ((k-1) / (sl * sl >> 2))//转化成在这层坐标
	{
		case(0):
			swap(p.first, p.second);
		break;
		case(1):
			p.second += sl>>1;
		break;
		case(2):
			p.first += sl>>1, p.second += sl>>1;
		break;
		case(3):
			swap(p.first, p.second);
			p.first = sl+1 - p.first;
		break;
	}
	return p;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	pair<int, int> ans = dir(k, n);
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}