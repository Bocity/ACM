#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 1;
bool isprime[N];
int prime[N / 10], cnt;
const int p[10] = {0,1,2,-1,-1,5,9,-1,8,6};
bool Isprime(long long x)
{
	if (x < 2)
		return 0;
	long long ult = sqrt(x);
	for (int i = 0; i < cnt && prime[i] <= ult; i++)
		if (x % prime[i] == 0)
			return 0;
	return 1;
}
int main()
{
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (isprime[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && (long long)i * prime[j] <= N; j++)
		{
			isprime[i * prime[j]] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
	long long n, nn = 0;
	cin >> n;
	if (!Isprime(n))
	{
		cout << "no" << endl;
		return 0;
	}
	do
	{
		int now = p[n % 10];
		if (now == -1)
		{
			cout << "no" << endl;
			return 0;
		}
		nn = nn * 10 + now;
		n /= 10;
	} while (n);
	
	
	if (!Isprime(nn))
	{
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
	return 0;
}