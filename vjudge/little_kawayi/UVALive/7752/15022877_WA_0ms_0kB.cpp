#include <bits/stdc++.h>
using namespace std;
int s[100002];
int main()
{
	int n;
	while (cin >> n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp != s[i])
				if (tmp && s[i])
					ans += 2;
				else
					ans += 1;
		}
		cout << ans << endl;
	}
	return 0;
}