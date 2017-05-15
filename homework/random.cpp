#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() {
    srand((int) time(0));
    for (int i = 0; i <= 9; i++) {
        int n;
        n = rand() % 8 + 1;
        char s2[] = "test0.in";
        s2[4] = s2[4] + i;
        freopen(s2, "w", stdout);
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            int x, y;
            x = rand() % 201 - 100;
            y = rand() % 201 - 100;
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}