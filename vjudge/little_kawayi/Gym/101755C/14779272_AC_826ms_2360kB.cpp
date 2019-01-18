#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
struct seg
{
	int l, r;
	friend bool operator<(seg a, seg b)
	{
		return a.r < b.r;
	}
} s[N];
int ans[N], cnt;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i].l >> s[i].r;
	sort(s, s + n);
	int tail = 0;
	for (int i = 0; i < n; i++)
		if (s[i].l > tail)
			ans[cnt++] = tail = s[i].r;
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << (i ? " " : "") << ans[i];
	cout << endl;
    return 0;
}