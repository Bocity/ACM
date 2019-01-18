#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 200000 + 10;
int rcd[maxn][30], r[maxn], m, l;
char s[maxn], c, q[10];
int main() {
    scanf("%s %d", s + 1, &m);
    l = strlen(s + 1);
    memset(rcd, -1, sizeof(rcd));
    for(int i = l - 1; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(s[i + 1] - 'a' == j) rcd[i][j] = i + 1;
            else rcd[i][j] = rcd[i + 1][j];
        }
    }
    int step = 1;
    r[0] = 0;
    while(m--) {
        scanf("%s", q);
        if(q[2] == 's') {
            scanf(" %c", &c);
            if(r[step - 1] == -1) r[step] = -1;
            else r[step] = rcd[r[step - 1]][c - 'a'];
            step++;
        }
        else step--;
        // printf("%s %c ----\n", q, c);
        if(r[step - 1] != -1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}