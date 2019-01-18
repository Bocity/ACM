#include <bits/stdc++.h>
using namespace std;
        map<int, int> s;
        vector<int> b;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        s.clear();
        b.clear();
        vector<int> a;
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        for (int i = 1; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            s[tmp]++;
            b.push_back(tmp);
        }
        int lena = sqrt(2*n) - 1;
        int ans = 0;
        for(auto x:b)
        {
            if (s[x] <= 0) continue;
            for (int i = 0; i < a.size(); i++){
                    if (s.find(a[i]+x) != s.end())
                    s[a[i]+x]--;
            }
            a.push_back(x);
            ans++;
            s[x]--;
            if (ans*(ans-1)/2 == n-ans )break;
        }
        cout << a.size() << endl;
        cout << a[0];
        for (int i = 1; i < a.size(); i++)
            cout << ' ' << a[i];
        cout << endl;
    }
}