#include <bits/stdc++.h>
#include <unordered_map>
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
		string s;
		cin >> s;
		int* w = new int[n];
		for (int i = 0; i < n; i++)
			cin >> w[i];
		unordered_map<string, int> m;
		queue<string> q;
		string b(n, 0);
		for (int i = 0; i < n; i++)
			b[i] += i;
		m[b] = 0;
		int maxs = 0;
		q.push(b);
		while (!q.empty())
		{
			string nxt, now = q.front();
			q.pop();
			maxs = max(maxs, m[now]);
			for (int i = 0; i < n - 1; i++)
				if (s[now[i]] == '(' && s[now[i+1]] == ')')
				{
					nxt = now;
					swap(nxt[i],nxt[i+1]);
					if (!m.count(nxt) || m[nxt] < m[now] + w[now[i]] * w[now[i + 1]])
					{
						m[nxt] = m[now] + w[now[i]] * w[now[i + 1]];
						q.push(nxt);
					}
				}
		}
		cout << maxs << endl;
	}
    return 0;
}