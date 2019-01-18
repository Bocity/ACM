#include <iostream>
using namespace std;
long long x;
int main() {
    while (cin >> x) cout << ((x % 4 == 2) ? "yes\n" : "no\n");
    return 0;
}