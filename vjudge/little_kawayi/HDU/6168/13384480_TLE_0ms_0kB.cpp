#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> s;
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
    map<int,int>::iterator it = s.begin();
    while (lena--)
    {
        for (int i = 0; i < a.size(); i++)
                s[a[i]+(*it).first]--;
        a.push_back((*it).first);
        s[(*it).first]--;
        while (!(*it).second)
            it++;
    }
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
        cout << ' ' << a[i];
    cout << endl;

}
