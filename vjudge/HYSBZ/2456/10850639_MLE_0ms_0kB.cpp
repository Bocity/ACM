#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    long long a, b;
    int x = 0;
    int n;
    cin >> n;
    cin >> a;
    b = a;
    x = 1;
    n--;
    while (n--) {
        cin >> a;
        if (a != b) {
            x--;
            if (x == 0) {
                cin >> b;
                x++;
                n--;
            } else {
                x--;
            }
        } else {
            x++;
        }
    }
    cout << b << endl;
    return 0;
}