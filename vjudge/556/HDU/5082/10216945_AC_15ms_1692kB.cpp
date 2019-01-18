#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    while (cin >> a >> b) {
        cout << a.substr(a.find('_') + 1) + "_small_" + b.substr(b.find('_') + 1) << endl;
    }
}