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
		int n;
		cin >> n;
		int* s = new int[n+1];
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		for (int i = 2; i < n; i++)
		{
			bool flag = 1;
			for (int j = 1; j < i; j++)
				if (s[j] >= s[j+1])
					flag = 0;
			for (int j = i; j < n; j++)
				if (s[j] <= s[j+1])
					flag = 0;
			if (flag)
				goto ok;
		}
		cout << "No" << endl;
		continue;
		ok:;
		cout << "Yes" << endl;
	}
    return 0;  
}  