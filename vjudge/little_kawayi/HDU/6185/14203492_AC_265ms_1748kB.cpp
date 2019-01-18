#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define MAXN 120
const int mod=1e9+7;
typedef long long ll;
const int n=4;
struct mat
{
    ll m[5][5];//矩阵结构体
} unit; //unit为单位矩阵，即主对角线全部为1，这样任何矩阵与单位矩阵相乘都为它本身

mat msub(mat a,mat b)//矩阵相乘函数
{
    mat ret;
    ll x;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            x=0;
            for(int k=0; k<n; k++)
            {
                x+=((a.m[i][k]*b.m[k][j])%mod);//取余
            }
            ret.m[i][j]=x%mod;//取余
        }
    }
    return ret;
}


void init_unit()//初始化单位矩阵
{
    for(int i=0; i<5; i++)
    {
        unit.m[i][i]=1;
    }
}

mat qpow(mat a,ll x)//快速幂
{
    mat ans=unit;
    while(x)
    {
        if(x&1) ans=msub(ans,a);
        a=msub(a,a);
        x>>=1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    while(cin>>x)
    {
        init_unit();
        mat    a,pos;
        memset(a.m,0,sizeof a.m);
                memset(pos.m,0,sizeof pos.m);

        a.m[0][0]=36;
        a.m[1][0]=11;
        a.m[2][0]=5;
        a.m[3][0]=1;
        pos.m[0][0]=1;
        pos.m[0][1]=5;
        pos.m[0][2]=1;
        pos.m[0][3]=-1;
        pos.m[1][0]=1;
        pos.m[2][1]=1;
        pos.m[3][2]=1;

        if(x<=4)
        {
            cout<<a.m[n-(x)][0]<<endl;
        }
        else
        {
            pos=qpow(pos,x-4);

            a=msub(pos,a);
            cout<<(a.m[0][0]+mod)%mod<<endl;
        }

    }
}
