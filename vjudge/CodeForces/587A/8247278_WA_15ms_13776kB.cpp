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
    memset(a,0,sizeof(a));
    for (int i=0; i<n; i++)
    {
        cin>>x;
        a[x]++;
        maxx=x>maxx?x:maxx;
    }
    for (int i=0; i<=maxx; i++)
    {
        while (a[i]>=2)
        {
            int p=i;
            x:;
            int k=2;
            int sum=0;
            while (a[p]>=k)
            {
                k*=2;
                sum++;
            }
            k/=2;
            a[p]-=k;
            p+=sum;
            a[p]++;
            if (a[p]>=2) goto x;

t++;
        }

        if (a[i]>0) t++;
    }
    cout<<t;
    return 0;
}

