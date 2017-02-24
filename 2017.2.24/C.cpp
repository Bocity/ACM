#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const  int maxn=1000000+32;
int a[maxn];
int main()
{
    int n,ans,data;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data);
            a[data]++;
        }
        ans=a[0]%2;
        for(int i=1;i<maxn;i++)
        {
            a[i]=a[i-1]/2+a[i];
            if(a[i]%2==1)
            ans++;
        }
        printf("%d\n",ans);  
    return 0;
}
