#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
struct seg
{
	int l, r;
	friend bool operator<(seg& a, seg& b)
	{
		return a.l < b.l;
	}
} s[N];
int ans[N + 1];
int q[N + 1], cnt;
inline void push(const int& x)
{
	q[++cnt] = x;
	for (int i = cnt; i >> 1; i >>= 1)
		if (q[i >> 1] > q[i])
			swap(q[i >> 1], q[i]);
}
inline void pop()
{
	q[1] = q[cnt--];
	for (int i = 1; i << 1 <= cnt;)
	{
		int nxt = i << 1;
		if (nxt + 1 <= cnt)
			nxt += q[nxt] > q[nxt + 1];
		if (q[i] > q[nxt])
			swap(q[i], q[nxt]);
		i = nxt;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		cnt = 0;
		for (int i = 1; i <= n; i++)
			push(i);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &s[i].l, &s[i].r);
		memset(ans, 0, n + 1 << 2);
		int l = s[0].l, r = s[0].r;
		for(int i=l;i<=r;i++) ans[i]=q[1],pop();
		for (int i = 1; i < m; i++)
		{
			if(s[i].r<=r)
                continue;
            if(r<s[i].l)
            {
                for(int j=l;j<=r;j++)
                    push(ans[j]);
                l=s[i].l,r=s[i].r;
                for(int j=l;j<=r;j++)
                    ans[j]=q[1],pop();
            }else
            {
                for(int j=l;j<s[i].l;j++)
                    push(ans[j]);
                l=r+1,r=s[i].r;
                for(int j=l;j<=r;j++)
                    ans[j]=q[1],pop();
            }
		}
		for (int i = 1; i <= n; i++)
			if (ans[i] == 0)
				ans[i] = 1;
		printf("%d", ans[1]);
		for (int i = 2; i <= n; i++)
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}
