#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1,str2;
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        string tmp;
        getline(cin,str1);
        getline(cin,str2);
        for (int i = 0; i < str2.size(); i++)
        if (i == str2.size() - 1)
        {
            if (str2[i] == '.')
                tmp += "[A-Za-z]";
            else
                tmp += str2[i];
        }  
        else
        {
            if (str2[i] == '.')
                if (str2[i+1] == '*')
                    tmp += "([a-zA-Z])?\\1*";
                else
                    tmp += "[A-Za-z]";
            else
                tmp += str2[i];
        }
        if (regex_match(str1,regex(tmp)))
            cout << "yes" <<endl;
        else
            cout << "no" << endl;
    }
}
