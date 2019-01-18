#include <iostream>
using namespace std;
int a[100005], n, t, sum;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 4) {
            cout << "no\n";
            continue;
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (a[i] > sum / 4) {
                cout << "no\n";
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "yes\n";
        }
    }
    return 0;
}