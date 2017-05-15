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
    for (int i = 0; i <= 9; i++) {
        char s1[] = "test0.in";
        char s2[] = "test0.out";
        s1[4] = s1[4] + i;
        s2[4] = s2[4] + i;
        freopen(s1, "r", stdin);
        freopen(s2, "w", stdout);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            cout << max(max(x + y, x - y), max(y - x, x * y)) << "\n";
        }
    }
    return 0;
}