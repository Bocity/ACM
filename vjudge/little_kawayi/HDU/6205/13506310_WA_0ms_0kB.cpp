#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct card
{
    int num, cost;
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    card *s = new card[n];
    for (int i = 0; i < n; i++)
        cin >> s[i].num;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].cost;
        s[i].cost = s[i].num - s[i].cost;
    }
    int start = 0;
    int maxans = 0;
    int index = 0;
    int bnow = 0;
    while (1)
    {

        system("pause>>nul");
        int now = bnow, sum = 0, ans = 0, cnt = 0;
        while (cnt++ < n && sum >= 0)
        {
            sum += s[now].cost;
            ans += s[now].num;
            now = (now + 1) % n;
        }
        if (maxans < ans)
        {
            index = bnow;
            maxans = ans;
        }

        //cout << bnow << ' ' << ans << endl;

        if (now <= bnow)
            break;
        else
            bnow = now;
    }
    cout << index << endl;
    return 0;
}
