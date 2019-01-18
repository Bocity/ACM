#include <bits/stdc++.h>
using namespace std;
struct candy
{
	int sweet, sour;
	friend bool operator<(candy a, candy b)
	{
		return a.sweet < b.sweet || a.sweet == b.sweet && a.sour < b.sour;
	}
};
int main()
{
	int t;
	ios::sync_with_stdio(0);
	map<candy, int> s;
	while (cin >> t && t)
		for (int i = 0; i < t; i++)
		{
			int x, a, b;
			cin >> x >> a >> b;
			if (x == -1)
			{
				s[candy{a, b}] -= 1;
			}
			else if (x == 1)
			{
				s[candy{a, b}] += 1;
			}
			else
			{
				int ans = -0x3f3f3f3f;
				for (auto i : s)
					if (i.second > 0)
					ans = max(ans, i.first.sweet * a + i.first.sour * b);
				cout << ans << endl;
			}
		}
	return 0;
} 