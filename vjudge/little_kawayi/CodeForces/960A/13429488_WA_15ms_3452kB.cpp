#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> *s;
bool *v;
multiset<int> *ms;
ll c(int n, int m)
{
    ll ans = 1;
    for (int i = m - 1; i >= 0; i--)
        ans = ans * (n - i) / (m - i);
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string str;
    cin >> str;
    string tmp = str;
    sort(tmp.begin(), tmp.end());
    if (tmp != str)
        cout << "NO" << endl;
    else if (count(str.begin(),str.end(),'a') == count(str.begin(),str.end(),'c') || count(str.begin(),str.end(),'b') == count(str.begin(),str.end(),'c'))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
