#include <iostream>
using namespace std;
string s;
long long ans = 0;
long long MOD = 1e9 + 7;
long long f[2000000];
int main() {
    cin >> s;
    long long len = s.length() - 1;
    if (s[len] == 'a') {
        while (s[len] != 'a') len--;
        while (s[len] != 'b') {
            f[len] = f[len + 1] + 1;
            len--;
        }
    } else {
        while (s[len] != 'b') {
            f[len] = f[len + 1] + 1;
            len--;
        }
    }
    for (int i = len; i >= 0; i--) {
        if (s[i] == 'a') {
            f[i] = (f[i + 1]) % MOD;
            ans = (ans + f[i]) % MOD;
            f[i]++;
        } else {
            f[i] = f[i + 1] + 1;
        }
    }
    cout << ans % MOD;
    return 0;
}
//  aabb    abbab   abbbba  bbabbba  bbbbabba bbbbbbaba bbbbbbbbaa
//