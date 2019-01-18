#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int n,x,maxx;
int a[3000000];
int main()
{
    cin >>n;
    maxx=0;
    int t=0;
    int k,p,sum2=0;
    memset(a,0,sizeof(a));
    int sum=0;
    for (int i=0; i<n; i++)
    {
        cin>>x;
        a[x]++;
        sum++;
        maxx=x>maxx?x:maxx;
    }
    for (int i=0; i<=maxx; i++)
    {
        if (a[i]==0) continue;
        k=2;
        p=i;
        x:;
        sum2=0;
        while (a[p]>=k)
        {
            a[p]-=k;
            k*=2;
            sum2++;
        }
        p+=sum2;
        if (a[p]>0&&p<3000000){ k=1;goto x;}
        t++;
    }


    cout<<t;
    return 0;
}
