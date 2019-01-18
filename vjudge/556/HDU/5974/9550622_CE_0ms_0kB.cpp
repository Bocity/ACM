#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b;
int main() {
    ll gcd, X, Y, A, B;
    while (cin >> a >> b) {
        gcd = __gcd(a, b);
        A = gcd * b;
        B = a;
        if (B * B - 4 * A < 0) {
            cout << "No Solution" << endl;
            continue;
        }
        int delt = sqrt(B * B - 4 * A);
        if (delt * delt != B * B - 4 * A) {
            cout << "No Solution" << endl;
            continue;
        }
        if ((B + delt) % 2 == 1) {
            cout << "No Solution" << endl;
            continue;
        }
        X = (B + delt) >> 1;
        Y = (B - delt) >> 1;
        if (X <= 0 || Y <= 0) {
            cout << "No Solution" << endl;
            continue;
        }
        if (X > Y) swap(X, Y);
        cout << X << " " << Y << endl;
    }
    return 0;
}