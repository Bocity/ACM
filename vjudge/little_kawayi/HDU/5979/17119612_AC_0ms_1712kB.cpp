#include <bits/stdc++.h>
using namespace std;
double s[11];
int main()
{
	int n;
	double d;
	while (cin >> n >> d)
	{
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		double ans = 0;
		for (int i = 1; i <= n; i++)
			ans += d * d * sin(s[i] * acos(-1) / 180);
		cout << setprecision(3) << fixed << ans / 2 << endl;
	}
} 