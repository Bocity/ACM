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
int s[7][7];
int cas, n, m, o, flag;
int **jl, *jll;
pair<int, int> **p;
bool ok()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = -1; k <= 1; k++)
                for (int l = -1; l <= 1; l++)
                    if (k||l)
                    {
                        int nx = i + k;
                        int ny = j + l;
                        if (0 <= nx && 0 <= ny && nx < n && ny < m)
                            if (s[i][j] == s[nx][ny])
                                return 0;
                    }
    return 1;
}
void nxt(int deep)
{
    if (deep == o)
    {
        if (ok())
        {
            cout << cas << endl;
            for (int i = 0;i < n; i++)
            {
                cout << s[i][0];
                for (int j = 1; j < m; j++)
                    cout << ' ' << s[i][j];
                cout <<endl;
            }
            flag = 1;
        }
        return;
    }
    do
    {
        for (int i = 0; i < jll[deep]; i++)
            s[p[deep][i].first][p[deep][i].second] = jl[deep][i];
        nxt(deep + 1);
        if (flag)
            return;
    }while(next_permutation(jl[deep], jl[deep] + jll[deep]));
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        flag = 0;
        cin >> cas >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                char tmp;
                cin >> tmp;
                if (isdigit(tmp))
                    s[i][j] = tmp - '0';
            }
        cin >> o;
        p = new pair<int, int>*[o];
        jl = new int*[o];
        jll = new int[o];
        for (int i = 0; i < o; i++)
        {
            int l,x,y;
            char tmp;
            cin >> l;
            jll[i] = l;
            p[i] = new pair<int, int>[l];
            jl[i] = new int[l];
            for (int j = 0; j < l; j++)
            {
                jl[i][j] = j + 1;
                cin >> tmp >> x >> tmp >> y >> tmp;
                x--,y--;
                p[i][j].first = x;
                p[i][j].second = y;
            }
        }
        nxt(0);
    }
    return 0;
}