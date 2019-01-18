#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string str;
    cin >> str;
    string tmp = str;
    sort(tmp.begin(), tmp.end());
    int cnta = count(str.begin(),str.end(),'a');
    int cntb = count(str.begin(),str.end(),'b');
    int cntc = count(str.begin(),str.end(),'c');
    if (tmp == str && cnta && cntb && (cntc == cnta || cntc == cntb))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
