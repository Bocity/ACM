#include <iostream>
#include <string.h>
using namespace std;
int maxn=10000000;
int a[10000000];
int main()
{
    int n,ans,data;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            cin>>data;
            a[data]++;
        }
        if (a[0]%2==0) ans++;
        for(int i=1;i<maxn;i++)
        {
            a[i]=a[i-1]/2+a[i];
            if(a[i]%2==1)
            ans++;
        }
        cout<<ans;
    return 0;
}
