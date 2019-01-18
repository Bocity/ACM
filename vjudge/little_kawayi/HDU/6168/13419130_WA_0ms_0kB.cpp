#include <bits/stdc++.h>
using namespace std;
        map<int, int> s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        s.clear();
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
        }
        int lena = sqrt(2*n) - 1;
        int ans = 0;
        for(auto kk:s)
        {
            for (int i = 0; i < a.size(); i++)
                    s[a[i]+(kk).first]--;
            a.push_back((kk).first);
            ans++;
            s[(kk).first]--;
            if (ans*(ans-1)/2 == n-ans )break;
        }
        cout << a.size() << endl;
        cout << a[0];
        for (int i = 1; i < a.size(); i++)
            cout << ' ' << a[i];
        cout << endl;
    }
}