#include <iostream>
using namespace std;
string s;
long long ans = 0, ans2 = 0;
;
long long MOD = 1e9 + 7;
long long f[2000000];
int main() {
    cin >> s;
    long long len = s.length() - 1;
    for (int i = len; i >= 0; i--) {
        if (s[i] == 'a') {
            ans2++;
            ans = (ans * 2) % MOD;
        } else
            ans++;
    }
    cout << (ans - s.length() + ans2) % MOD;
    return 0;
}
//  aabb    abbab   abbbba  bbabbba  bbbbabba bbbbbbaba bbbbbbbbaa
//