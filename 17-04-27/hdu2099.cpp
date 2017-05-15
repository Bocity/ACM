#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;
int main() {
    ll a, b;
    while (cin >> a >> b && b != 0) {
        a *= 100;
        ll sum = 0;
        for (int i = 0; i < 100; i++) {
            if (a % b == 0) {
                sum++;
                if (sum > 1)
                    printf(" %02d", i);
                else
                    printf("%02d", i);
            }
            a++;
        }
        cout << "\n";
    }

    return 0;
}