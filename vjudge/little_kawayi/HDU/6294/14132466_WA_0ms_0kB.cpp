#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    while(T--) {
        cin >> n >> s;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] < s[i + 1]) cout << '<';
            else if(s[i] > s[i + 1]) cout << '>';
            else {
                int num = 0;
                while(s[i] == s[i + 1]) {
                    num++;
                    i++;
                }
                // cout << "num " << num << endl;
                if(i == n - 2) {
                    for(int k = 0; k < num; k++) cout << '>';
                }
                else {
                    if(s[i + 1] < s[i + 2]) {
                        for(int k = 0; k < num; k++) cout << '>';
                        // cout << 111 << endl;
                    }
                    else {
                        for(int k = 0; k < num; k++) cout << '<';
                        // cout << 222 << endl;
                    }
                }
                i--;
            }
        }
        cout << endl;
    }
    return 0;
}