#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string str1,str2;
    int t;
    cin >> t;
    while (t--)
    {
        string tmp;
        cin >> str1 >> str2;
        for (int i = 0; i < str2.size(); i++)
        {
            if (isalpha(str2[i]))
                tmp += str2[i];
            else if (str2[i] == '*')
                tmp += str2[i];
            else if (str2[i] == '.')
                tmp += "[a-z]";        }
        regex r(str2);
        if (regex_match(str1,r))
            cout << "yes" <<endl;
        else
            cout <<"no" << endl;
    }
}

