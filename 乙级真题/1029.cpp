#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cstdio>
using namespace std;
char s1[20000000], s2[20000000];
int si1 = 0, si2 = 0;
map<char, bool> q;
char to(char x)
{
    if (x >= 'a' && x <= 'z')
        return (x + 'A' - 'a');
    return x;
}
int main()
{
    cin.getline(s1, 1e6, '\n');
    cin.getline(s2, 1e6, '\n');
    while (s1[si1] != '\0')
        si1++;
    while (s2[si2] != '\0')
        si2++;
    for (int i = 0; i <= si1 - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j <= si2 - 1; j++)
        {
            if (s2[j] == s1[i])
                flag = true;
        }
        if (!flag && !q[to(s1[i])])
        {
            cout << to(s1[i]);
            q[to(s1[i])] = true;
        }
    }
    // stringstream my(s2);
    // int i = 1;
    // while (my >> s3[i])
    // {
    //     i++;
    // }
    // if (s3[1][0] == '\0')
    //     cout << '\n';
    // else
    // {
    //     for (int j = 1; j < i; j++)
    //         cout << s3[j];
    // }

    return 0;
}