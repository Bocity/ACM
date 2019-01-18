#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int miu[N], prime[N], cnt;
bool isprime[N]; 
signed main() 
{
	memset(miu, -1, sizeof miu);
	memset(isprime, 1, sizeof isprime);
	miu[1] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1e5; i++)
	{
		if (isprime[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] <= 1e5; j++)
		{
			isprime[i * prime[j]] = 0;
			miu[i * prime[j]] = -miu[i];
			if (i % prime[j] == 0)
			{
				miu[i * prime[j]] = 0;
				break;
			}
		}
	}
	int t, a, b, c, d, e;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		cin >> a >> b >> c >> d >> e;
		cout << "Case " << cas << ": ";
		if (e == 0)
		{
			cout << 0 << endl;
			continue;
		}
		b /= e;
		d /= e;
		int ans1 = 0, ans2 = 0;
		for (int i = 1, ult = min(b, d); i <= ult; i++)
		{
			ans1 += miu[i] * (ult / i) * (ult / i + 1) / 2;
			ans2 += miu[i] * (ult / i) * (max(b, d) / i - ult / i);
		}
		cout << ans1 + ans2 << endl;
	}
	return 0;
}
/*
1 1
1 2
1 3
1 4
1 5
2 1
2 3
2 5
3 1
3 2
3 4
3 5
*/