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
		int l = 1,r = n;
		int* s = new int[n+1];
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		while (l < n && s[l] < s[l+1])
			l++;
		while (r > 0 && s[r-1] > s[r])
			r--;
		if (l != r || l <= 1 || l >= n)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
    return 0;  
}  