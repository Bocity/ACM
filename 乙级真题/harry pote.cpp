#include <iostream>
#define maxn 105
using namespace std;
int mat[maxn][maxn];
int a[500][500];
// int djs(int s, int n)
// {
//     int v[maxn], low[maxn];
//     memset(v, 0, sizeof(v));
//     for (int i = 1; i <= n; i++)
//         low[i] = a[s][i];
//     v[s] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         int min = 0xffff;
//         int temp;
//         for (int j = 1; j <= n; j++)
//             if (!v[j] && low[j] < min)
//             {
//                 min = low[j];
//                 temp = j;
//             }
//         v[temp] = 1;
//         for (int j = 1; j <= n; j++)
//             if (!v[j] && low[j] > low[temp] + mat[temp][j])
//                 low[j] = low[temp] + mat[temp][j];
//     }
//     return low[n];
// }

int main()
{
    int n, m;
    int min = 0xffff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            mat[i][j] = 0xffff;
        mat[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, lenth;
        cin >> a >> b >> lenth;
        mat[a][b] = lenth;
        mat[b][a] = lenth;
    }
    int casee = 0;
    for (int i = 1; i <= n; i++)
        if (min > djs(i, n))
        {
            min = djs(i, n);
            casee = i;
        }
    cout << casee << " " << min << endl;
}