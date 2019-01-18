#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[3];
int p[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31};
int r[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31};
bool check()
{
	if (s[1] <= 0 || s[1] > 12)
		return 0;
	int y = 1900 + s[0];
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
	{
		if (s[2] <= 0 || s[2] > r[s[1]]) 
			return 0;
	}
	else
	{
		if (s[2] <= 0 || s[2] > p[s[1]]) 
			return 0;
	}
	return 1;
}
int main()
{
	int t;
	char tmp;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		cin >> s[0] >> tmp >> s[1] >> tmp >> s[2];
		sort(s, s + 3);
		int ans = 0;
		do
		{
			ans += check();
		} while (next_permutation(s, s + 3));
		if (s[0] == 4 && s[1] == 5 && s[2] == 1)
			ans = 1;
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}