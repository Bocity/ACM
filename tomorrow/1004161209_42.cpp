#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;
int n, sum1 = 0, sum2 = 0, sum3 = 0;
int cmp(string s1, string s2)
{
    if (s1 == "C" && s2 == "J")
        return 1;
    if (s1 == "J" && s2 == "B")
        return 1;
    if (s1 == "B" && s2 == "C")
        return 1;
    if (s1 == s2)
        return 0;
    return -1;
}
int main()
{
    cin >> n;
    string s1, s2;
    map<string, int> q1;
    map<string, int> q2;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2;
        if (cmp(s1, s2) == 0)
        {
            sum3++;
            continue;
        }

        if (cmp(s1, s2) == 1)
        {
            q1[s1]++;
            sum1++;
        }
        else
        {
            q2[s2]++;
            sum2++;
        }
    }
    cout << sum1 << " " << sum3 << " " << sum2 << "\n";
    cout << sum2 << " " << sum3 << " " << sum1 << "\n";
    if (q1["B"] >= q1["C"] && q1["B"] >= q1["J"])
        cout << "B ";
    else if (q1["C"] > q1["B"] && q1["C"] >= q1["J"])
        cout << "C ";
    else
        cout << "J ";
    if (q2["B"] >= q2["C"] && q2["B"] >= q2["J"])
        cout << "B";
    else if (q2["C"] > q2["B"] && q2["C"] >= q2["J"])
        cout << "C";
    else
        cout << "J";

    return 0;
}