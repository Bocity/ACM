#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int k, tmp = 1;
	int dist[4] = {0,0,0,0};//0右 1上 2左 3下 
	int ward = 0;// 0右 1上 2左 3下 
	cin >> k;
	while (1)
	{
		cin >> tmp;
		
		cout << dist[ward] + 1;
		dist [(ward + 2) % 4] += dist[ward] + 1;
		dist[ward] = 0;
		cin >> tmp;
		if (tmp == 0)
			break;
		ward = (ward + tmp + 4) % 4;
		cout << ' ';
	}
	cout << endl;
	return 0;
}