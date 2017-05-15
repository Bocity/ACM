#include <cstdio>
#include <iostream>
using namespace std;
int a[100] = {0};
int n, x, j;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 1; i <= n; i++) {
        if (a[i] == x) {
            a[i] = 0;
            j = i;
        }
    }
    for (int i = j; i <= n; i++) {
        a[i] = a[i + 1];
    }
    for (int i = 1; i <= n - 1; i++) {
        cout << a[i] << " ";
    }
    return 0;
}