#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
int a, b, c;
int x[100];
int main()
{
    cin >> a;
    if (a == 6174)
    {
        cout << "7641 - 1467 = 6174";
        return 0;
    }
    while (a != 6174)
    {
        int m, n;
        x[1] = a / 1000;
        x[2] = a % 1000 / 100;
        x[3] = a % 100 / 10;
        x[4] = a % 10 / 1;
        if (x[1] == x[2] && x[2] == x[3] && x[3] == x[4])
        {
            cout << a << " - " << a << " = 0000\n";
            return 0;
        }
        sort(x + 1, x + 5, cmp);
        n = x[1] * 1000 + x[2] * 100 + x[3] * 10 + x[4] * 1;
        cout << x[1] << x[2] << x[3] << x[4] << " - ";
        sort(x + 1, x + 5);
        m = x[1] * 1000 + x[2] * 100 + x[3] * 10 + x[4] * 1;
        cout << x[1] << x[2] << x[3] << x[4] << " = ";
        a = n - m;
        x[1] = a / 1000;
        x[2] = a % 1000 / 100;
        x[3] = a % 100 / 10;
        x[4] = a % 10 / 1;
        cout << x[1] << x[2] << x[3] << x[4] << "\n";
    }
    return 0;
}