#include <iostream>
using namespace std;
typedef long long ll;
// ll f[1000];
ll x;

int main() {
    // f[0] = 7;
    // f[1] = 11;
    // for (int i = 3; i <= 100; i++) f[i] = f[i - 1] + f[i - 2];
    // for (int i = 1; i <= 100; i++)
    //     if (f[i] % 3 == 0) cout << i << " ";
    while (cin >> x) {
        if (x % 4 == 2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}