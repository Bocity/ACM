#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point
{
	long long x, y, id;
	friend point operator-(point a, point b)
	{
		return point{a.x - b.x, a.y - b.y};
	}
	friend long long operator^(point a, point b)
	{
		return a.x * b.y - a.y * b.x;
	}
} p[3000];
bool cmppa(point a, point b)
{
	return (a - p[0] ^ b - p[0]) > 0;
}
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	p[0].x = -1e9-1;
	p[0].y = -1e9-1;
	while(t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= 3 * n; i++)
		{
			p[i].id = i;
			cin >> p[i].x >> p[i].y;
		}
		sort(p + 1, p + 3 * n + 1, cmppa);
		for (int i = 1; i <= 3 * n; i += 3)
			cout << p[i].id << ' ' << p[i + 1].id << ' ' << p[i + 2].id << endl;
	}
	return 0;
}