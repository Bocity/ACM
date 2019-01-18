#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200002;
struct point
{
	ll x, y;
	friend point operator-(point a, point b)
	{
		return point{a.x - b.x, a.y - b.y};
	}
	friend ll operator^(point a, point b)
	{
		return a.x * b.y - a.y * b.x;
	}
} p[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y;
	ll ans = 9e18;
	p[0] = p[n];
	p[n + 1] = p[1];
	for (int i = 1; i <= n; i++)
		ans = min(ans, p[i] - p[i - 1] ^ p[i + 1] - p[i - 1]);
	cout << ans << endl;
	
    return 0;
}