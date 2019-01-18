#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
struct zb
{
	int r, c;
};
char s[3][3];
int wr[4] = {0, 0, 1, 1};
int wc[4] = {0, 1, 0, 1};
zb tt[2][2][2];
int main()
{
	tt[0][0][0] = zb{0, 1};
	tt[0][0][1] = zb{1, 1};
	tt[0][1][1] = zb{1, 0};
	tt[0][1][0] = zb{0, 0};
	tt[1][0][0] = zb{1, 0};
	tt[1][1][0] = zb{1, 1};
	tt[1][1][1] = zb{0, 1};
	tt[1][0][1] = zb{0, 0};
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> s[i][j];
		for (int i = 0; i < n; i++)
		{
			char opt[3];
			cin >> opt;
			int w = opt[1] == 'R';
			int p = opt[0] - '1';
			char tmp[2][2];
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					tmp[tt[w][i][j].r][tt[w][i][j].c] = s[wr[p] + i][wc[p] + j];
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					s[wr[p] + i][wc[p] + j] = tmp[i][j];
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << s[i][j];
			cout << endl;
		}
				
	}
	return 0;
}