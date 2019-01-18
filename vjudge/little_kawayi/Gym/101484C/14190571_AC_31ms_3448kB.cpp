#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct team
{
	int acnums, time;
	int problems[14];
	team()
	{
		acnums = time = 0;
		memset(problems, 0, sizeof(problems));
	}
};
int main()
{
	ios::sync_with_stdio(0);
	int n, m, p, ans = 0;
	string ourteam;
	cin >> n >> m >> p;
	unordered_map<string, team> s;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		if (i == 0)
			ourteam = tmp;
		s[tmp] = team();
	}
	int maxs = 0, maxt = 0, pret = 0;
	bool flag = 1;
	for (int i = 0; i < m; i++)
	{
		int tim;
		char pros;
		string tname, isok;
		cin >> tname >> pros >> tim >> isok;
		if (s[tname].problems[pros - 'A'] != 1)
			if (isok == "OK")
			{
				s[tname].acnums++;
				s[tname].time += -20 * s[tname].problems[pros - 'A'] + tim;
				s[tname].problems[pros - 'A'] = 1;
				if ((s[tname].acnums > maxs || (s[tname].acnums == maxs && (tname == ourteam ? s[tname].time <= maxt : s[tname].time < maxt))))//刷新第一
				{
					maxs = s[tname].acnums;
					maxt = s[tname].time;
					if (flag == 1)
						ans += tim - pret;
					pret = tim;
					flag = tname == ourteam;
				}
			}
			else
				s[tname].problems[pros - 'A'] -= 1;
	}
	if (flag == 1)
		ans += 300 - pret;
	cout << ans << endl;
	//system("pause");
	return 0;
}