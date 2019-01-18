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
            int p;
            if (i==0)
                p=1;
            else
                p=i*2;
            a[i]-=2;
            while (p<=3000000&&a[p]>0)
            {
                a[p]--;
                p*=2;
            }
            t++;

        }
        if (a[i]>0) t++;
    }
    cout<<t;
    return 0;
}
