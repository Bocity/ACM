#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include<algorithm>
#define zero(x) (((x)>0?(x):-(x))<eps)
#define eps 1.0E-8
using namespace std;
double Y,result;
int T;
int calc(double x)
{
    double t=8*x*x*x*x+7*x*x*x+2*x*x+3*x+6-Y;
    if (zero(t))
        return 0;
    return t>0?1:-1;

}

double cha(double l,double r)
{
    double mid =(l+r)/2;
    int tt=calc(mid);
    if (tt==0) return mid;
    if (tt<0) return cha(mid,r);
    return cha(l,mid);
}
int main()
{
    cin>>T;
    for (int i=1; i<=T; i++)
    {
        cin>>Y;
        result=-1;
        for (int j=0; j<100; j++)
        {
            if (calc((double) j)==0)
            {
                result=j;
                break;
            }
            if (calc((double)j)+calc((double)(j+1))==0)
            {
                result=cha(j,j+1);
                break;
            }
        }
        if (result>0)
            printf("%.4lf\n",result);
        else  printf("No solution!\n");
    }
    return 0;
//阿斯达所多撒
}
