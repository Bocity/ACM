#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int f[2000][2000] = {0};
string a, b;
int main() {
    cin >> a;
    cin >> b;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            if (a[i] == a[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else if (i > 0 && j > 0)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    cout << f[a.length() - 1][b.length() - 1];
    return 0;
}