#include <bits/stdc++.h>
 #pragma GCC optimize(2) 
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

	while (cin >> t && t)
    {set<candy> s;
		for (int i = 0; i < t; i++)
		{
			int x, a, b;
			cin >> x >> a >> b;
			if (x == -1)
			{
				s.erase(candy{a,b});
			}
			else if (x == 1)
			{
				s.insert(candy{a,b});
			}
			else
			{
				int ans = -0x3f3f3f3f;
				set<candy>::iterator iter;
				for ( iter=s.begin();iter!=s.end();iter++)
				{
				    candy pos=(candy) *iter;
				    ans=max(ans,pos.sweet*a+pos.sour*b);
				}
				cout << ans << endl;
			}
		}
    }
	return 0;
}
