//CUGBACM15级寒假训练#1
//A - FATE
//http://acm.hdu.edu.cn/showproblem.php?pid=2159
// 多重背包 有 k 个物品 每个物品有s件   n为背包容量(经验) m 为(耐心)背包价值
// f[i][v]=max{f[i-1][v-j*b[i]]+j*a[i]|0<=j<=k} i怪兽 v剩余总耐心
// 求 f[i][v] 中 大于 n 的最小值
#include <iostream>
#include <cstring>
using namespace std;
int n,m,k,s,f[200][200],cur,result,a[200],b[200];
int main()
{

    while (  cin>>n>>m>>k>>s)
    {
        for (int i=1; i<=k; i++)
        {
            cin>>a[i]>>b[i];
        }
        // m 忍耐度 n经验值 k 怪物种类 s 最多杀怪数
        memset(f,0,sizeof(f));
        for (int i = 1; i <= k; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                for (int c = 0; c <=s; c ++)
                {
                    if (j - c*b[i] >= 0)
                    {
                        cur = f[i - 1][j - c * b[i]] + c * a[i];
                        f[i][j] = f[i][j] > cur ? f[i][j] : cur;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            result=-1;
            for (int i=m; i>=0; i--)
            {
                if (f[k][i]>=n)
                {
                    result=i;
                    break;
                }
            }
            cout<<result<<"\n";
        }
    }
    return 0;
}
