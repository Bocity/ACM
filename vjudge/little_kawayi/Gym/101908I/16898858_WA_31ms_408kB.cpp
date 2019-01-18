#include<bits/stdc++.h>
using namespace std;
bool b[1001];
vector<int> s[1001];
int main()
{
    int n, m;
    cin >> n >> m;
    int tmp;
    cin >>tmp;
    for (int i = 1; i <= tmp; i++)
    {
        int tmp2;
        cin >> tmp2;
        b[tmp2] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp2;
        cin >> tmp2;
        for (int j = 1; j <= tmp2; j++)
        {
            int tmp3;
            cin >> tmp3;
            s[i].push_back(tmp3);
        }
    }
    int rst;
    int flag = -1;
    rst = 0;
    for (int j = 1; j <= m; j++)
        rst += b[j];
    if (rst == 0)
    {
        flag = 0;
        goto end;
    }
    if (flag == -1)
    for (int a = 0; a <= 1; a++)
    for (int i = 1; i <= n; i++)
    {
        for (int j : s[i])
            b[j] = !b[j];
        rst = 0;
        for (int j = 1; j <= m; j++)
            rst += b[j];
        if (rst == 0)
        {
            flag = a * m + i;
            goto end;
        }
    }
    end:;
    cout << flag << endl;


}
