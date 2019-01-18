#include <bits/stdc++.h>
using namespace std;
char str[600002];
int main()
{
	ios::sync_with_stdio(0);
	int n, aim, tmp, flag[3]{0};
	cin >> n >> aim;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp < aim)
			flag[0] = 1;
		else if (tmp > aim)
			flag[2] = 1;
		else
			flag[1] = 1;
	}
	if (flag[1])
		cout << 1 << endl;
	else if (flag[0] && flag[2])
		cout << 2 << endl;
	else
		cout << -1 << endl;
	return 0;
}