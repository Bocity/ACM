#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int *q = new int[n];
    for (int i = 0; i < n; i++)
        cin >> q[i];
    map<int, int> s;
    vector<int> a;
    a.push_back(q[0]);
    for (int i = 1; i < n; i++)
        s[q[i]]++;
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