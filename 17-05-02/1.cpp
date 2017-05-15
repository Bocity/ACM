#include <iostream>
#define endl "\n"

using namespace std;
typedef long long ll;

ll sum = 0;
ll data[1000];
ll tmp = 0;
ll multi(ll x, ll y, ll z) {
    ll ret = 0;
    while (y > 0) {
        if (y & 1) ret = (ret + x) % z;
        y >>= 1;
        x = (x << 1) % z;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int n, p;
    data[1] = 4;
    cin >> n;
    while (n--) {
        sum = 1;
        cin >> p;
        sum <<= p;
        sum -= 1;
        for (int i = 2; i <= p - 1; i++) {
            tmp = multi(data[i - 1], data[i - 1], sum);
            data[i] = (tmp - 2) % sum;
        }
        if (p == 2)
            cout << "yes" << endl;
        else {
            if (data[p - 1] == 0)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    return 0;
}