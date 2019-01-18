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
		int n, m;
		int ww;
		int booll = 0, boolw = 0;
		cin >> n >> m;
		int* s = new int[n];
		for (int i = 0; i < n; i++)
		{
			char ch;
			cin >> ch;
			if (ch == 'W')
			{
				s[i] = 0;
				boolw = 1;
				ww = i;
			}
			else
			{
				int tmp;
				cin >> tmp;
				if (ch == 'C')
					s[i] = tmp;
				else if (ch == 'B')
					s[i] = m + tmp;
				else if (ch == 'D')
					s[i] = 2 * m + tmp;
			}
		}
		if (n > 1 && s[1] && s[0] > s[1])
			booll = 1;

		if (booll)
		{
			cout << 1 << endl;
		}
		else if (boolw)
		{
			int l = ww ? s[ww-1] : 0, r = ww < 3 * m ? s[ww+1] : 3 * m + 1;
			if (ww == 1)
				l--;
			cout << r - l - 1 << endl;
		}
		else
		{
			cout << 3 * m - n + 1 << endl;
		}
	}
    return 0;
}