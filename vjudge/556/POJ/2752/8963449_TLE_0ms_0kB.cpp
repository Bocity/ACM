#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
long long n, m;
int f[100000];
// text and pattern
void KMP(string p) {
    int m = p.size(), cnt = 0;
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && p[i] != p[j]) j = f[j];
        f[i + 1] = p[i] == p[j] ? j + 1 : 0;
    }
    return;
}
string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> s1) {
        int len = s1.length() - 1;
        int n = 0;
        for (int i = 0; i <= len; i++) {
            if (s1[i] == s1[len] && s1[0] == s1[len - i] && s1.substr(0, 1 + i) == s1.substr(len - i, i + 1)) {
                if (n == 0)
                    cout << i + 1;
                else
                    cout << " " << i + 1;
                n++;
            }
        }
        cout << "\n";
    }
    return 0;
}