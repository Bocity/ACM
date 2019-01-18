#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
long long n, m;
string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> s1) {
        int len = s1.length() - 1;
        int n = 0;
        for (int i = 0; i <= len; i++) {
            if (s1.substr(0, 1 + i) == s1.substr(len - i, i + 1)) {
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