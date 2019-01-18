#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
int main()  
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n,qs = 0;
		string s;
		cin >> n >> s;
		if (n % 4 == 1 || n % 4 == 2)
		{
			cout << -1 << endl;
			continue;
		}
		else if (n % 4 == 3)
		{
			qs = 3;
			cout << (s[0] == '1' ? 3 : 1);
			cout << (s[1] == '1' ? 3 : 1);
			cout << (s[2] == '1' ? 4 : 2);
		}
		for (int i = qs; i < n; i ++)
			if (s[i] == '1')
				cout << (((i-qs) % 4 == 0 || (i-qs) % 4 == 3) ? 3 : 4);
			else
				cout << (((i-qs) % 4 == 0 || (i-qs) % 4 == 3) ? 1 : 2);
		cout << endl;
	}
    return 0;  
}