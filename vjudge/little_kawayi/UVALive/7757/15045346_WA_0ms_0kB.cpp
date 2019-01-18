#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
char s[maxn];
int ans[maxn];
int r(int a, int b, int c) {
    return a * 4 + b * 2 + c;
}
int main() {
    while(~scanf("%s", s + 1)) {
        int n = strlen(s + 1);
        int k = 0;
        s[0] = '0';
        for(int i = 1; i + 2 <= n; i += 3) {
            // cout << 55555 << endl;
            int a = s[i] - '0', b = s[i + 1] - '0', c = s[i + 2] - '0';
            if(s[i - 1] == '0') {
                if(r(a, b, c) == 0) ans[k++] = i;
                if(r(a, b, c) == 1) ans[k++] = i + 1, s[i + 2] = '0';
                if(r(a, b, c) == 3) ans[k++] = i;
                if(r(a, b, c) == 7) ans[k++] = i + 1, s[i + 2] = '0';
            }
            else if(s[i - 1] == '1') {
                if(r(a, b, c) == 0) ans[k++] = i + 1, s[i + 2] = '1';
                if(r(a, b, c) == 4) ans[k++] = i;
                if(r(a, b, c) == 6) ans[k++] = i + 1, s[i + 2] = '1';
                if(r(a, b, c) == 7) ans[k++] = i;
            }
        }
        // printf("%s\n", s + 1);
        printf("%d\n", k);
        for(int i = 0; i < k; i++) {
            printf("%d", ans[i]);
            if(i == k - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}