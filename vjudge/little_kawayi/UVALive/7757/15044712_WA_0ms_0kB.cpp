#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int ans[maxn];
int r(int a, int b, int c) {
    return a * 4 + b * 2 + c;
}
int main() {
    string s;
    while(cin >> s) {
        int n = s.size();
        int k = 0;
        for(int i = 0; i + 2 < n; i += 3) {
            // cout << 55555 << endl;
            int a = s[i] - '0', b = s[i + 1] - '0', c = s[i + 2] - '0';
            if(i == 0 ||(i > 0 && s[i - 1] == '0')) {
                if(r(a, b, c) == 0) ans[k++] = i;
                if(r(a, b, c) == 1) ans[k++] = i + 1, s[i + 2] = '0';
                if(r(a, b, c) == 3) ans[k++] = i;
                if(r(a, b, c) == 7) ans[k++] = i, s[i + 2] = '0';
            }
            else if(s[i - 1] == '1') {
                if(r(a, b, c) == 0) ans[k++] = i, s[i + 2] = '1';
                if(r(a, b, c) == 4) ans[k++] = i;
                if(r(a, b, c) == 6) ans[k++] = i, s[i + 2] = '1';
                if(r(a, b, c) == 7) ans[k++] = i;
            }
        }
        cout << k << endl;
        for(int i = 0; i < k; i++) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}