#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef int ll;
const int MAX = 30004;
int t, n;
int mp[MAX][27];
bool mp2[MAX][27];
char S[1005][30];
int main() {
    n = 1;
    memset(mp, 0, sizeof mp);
    memset(mp2, false, sizeof mp2);
    // freopen("1.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while (scanf("%s", S[n])) {
        n++;
    }
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        int p = 0;
        for (int j = 0; j <= strlen(S[i]) - 1; j++) {
            int t = S[i][j] - 'a';
            if (mp[p][t] == 0) {
                sum++;
                mp[p][t] = sum;
                p = sum;
            } else {
                mp2[p][t] = true;
                p = mp[p][t];
                continue;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= strlen(S[i]) - 1; j++) printf("%c", S[i][j]);
        printf(" ");
        int p = 0;
        bool f = false;
        for (int j = 0; j <= strlen(S[i]) - 1; j++) {
            int t = S[i][j] - 'a';
            if (f)
                break;
            else {
                if (!mp2[p][t]) {
                    printf("%c", (char) (t + 'a'));
                    f = true;
                } else {
                    printf("%c", (char) (t + 'a'));
                    p = mp[p][t];
                }
            }
        }
        printf("\n");
    }

    return 0;
}