#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n == 1)
        cout << 0;
    else if (n == 3)
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            cout << max(max(x + y, x - y), max(y - x, x * y)) << " "
                 << "\n";
        }
    else
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            cout << max(max(x + y, x - y), max(y - x, x * y)) << "\n";
        }
    return 0;
}