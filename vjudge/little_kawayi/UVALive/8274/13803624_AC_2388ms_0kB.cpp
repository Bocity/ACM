#include <bits/stdc++.h>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
const int N = 10005, inf = 0x3f3f3f3f;
int nxt[N], r[N][N], f[N];
char s[N];

void get_next(const char *s) {
    int len = strlen(s);
    nxt[0] = -1;
    for (int i = 1, j; i < len; ++i) {
        j = nxt[i - 1];
        while (j != -1 && s[j + 1] != s[i]) j = nxt[j];
        if (s[j + 1] == s[i]) nxt[i] = j + 1;
        else nxt[i] = -1;
    }
}

int main() {
    int T, i, j,n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        f[0] = 0;
        FOR(i,1,n) f[i] = inf;
        FOR(i,1,n)
        {
            get_next(s + i);
            FOR(j,1,n)
            {
                if (j < i) continue;
                int len = (j - i) - nxt[j - i];
                if ( (nxt[j - i] + 1) % len  == 0) r[i][j] = len;
                else r[i][j] = j - i + 1 ;
                f[j] = min(f[j], f[i - 1] + r[i][j]);
            }
        }

        printf("%d\n", f[n]);
    }
    return 0;
}