#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;
void to(char &x)
{
    if (x >= 'A' && x <= 'Z')
        x = ' ';
}
void to2(char &x)
{
    if (x >= 'A' && x <= 'Z')
        x = x - 'A' + 'a';
}
char s1[20000000], s2[20000000];
int si1 = 0, si2 = 0;
int main()
{

    cin.getline(s1, 1e6, '\n');
    cin.getline(s2, 1e6, '\n');
    while (s1[si1] != '\0')
        si1++;
    while (s2[si2] != '\0')
        si2++;
    bool pan = false;
    for (int i = 0; i <= si1 - 1; i++)
    {

        if (s1[i] == '+')
            pan = true;
    }
    for (int i = 0; i <= si1 - 1; i++)
    {
        to2(s1[i]);
        for (int j = 0; j <= si2 - 1; j++)
        {
            if (pan)
                to(s2[j]);
            if (s2[j] == s1[i] || s2[j] == s1[i] + 'A' - 'a')
                s2[j] = ' ';
        }
    }
    bool flag = false;
    for (int i = 0; i <= si2; i++)
    {
        if (s2[i] != ' ')
        {
            cout << s2[i];
            flag = true;
        }
    }
    if (!flag)
        cout << "\n";
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