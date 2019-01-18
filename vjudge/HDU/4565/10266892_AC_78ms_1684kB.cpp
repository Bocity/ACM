#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
using namespace std;  
typedef long long LL;  
const int MAXN = 2;  
struct Matrix{  
    LL mat[MAXN][MAXN];  
};  
LL MOD;  
Matrix Multi_Matrix(Matrix a, Matrix b){  
    Matrix c;  
    for(int i=0; i<MAXN; i++){  
        for(int j=0; j<MAXN; j++){  
            c.mat[i][j] = 0;  
            for(int k=0; k<MAXN; k++){  
                c.mat[i][j] += a.mat[i][k]*b.mat[k][j];  
                c.mat[i][j] = (c.mat[i][j]%MOD + MOD) % MOD;  
            }  
        }  
    }  
    return c;  
}  
Matrix Pow_Matrix(Matrix a, LL b){  
    Matrix ans;  
    ans.mat[0][0] = 1, ans.mat[0][1] = 0;  
    ans.mat[1][0] = 0, ans.mat[1][1] = 1;  
    while(b){  
        if(b & 1)  
            ans = Multi_Matrix(ans, a);  
        b>>=1;  
        a = Multi_Matrix(a, a);  
    }  
    return ans;  
}  
int main()  
{  
    LL a, b, n;  
    while(~scanf("%lld%lld%lld%lld",&a,&b,&n,&MOD)){  
        Matrix p;  
        p.mat[0][0] = 2*a, p.mat[0][1] = 1;  
        p.mat[1][0] = b-a*a, p.mat[1][1] = 0;  
        p = Pow_Matrix(p, n-1);  
        LL ans = (2*a*p.mat[0][0] % MOD + 2*p.mat[1][0]) % MOD;  
        ans = (ans%MOD+MOD) % MOD;  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  