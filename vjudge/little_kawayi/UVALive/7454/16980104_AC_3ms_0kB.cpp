#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char s[101];
		cin >> s;
		int tmp = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(')
				tmp++;
			else
				tmp--;
			if (tmp < 0)
			{
				tmp+=2;
				ans++;
				s[i] = '(';
			}
		}
		tmp = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == ')')
				tmp++;
			else
				tmp--;
			if (tmp < 0)
			{
				tmp+=2;
				ans++;
				s[i] = ')';
			}
		}
		cout << ans << endl;
	}
}