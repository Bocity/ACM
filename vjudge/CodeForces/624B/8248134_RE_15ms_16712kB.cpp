#include<iostream>
#include<string.h>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,maxx,p=0;
int a[3000000];
bool b[3000000]={0};
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    cin >>n;
   for (int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++)
    {
        if (!b[a[i]])
        {
            b[a[i]]=true;
            p+=a[i];
        }
        else
        {
                while (b[a[i]])
                {
                    a[i]--;if (a[i]<0) break;
                }
                if (a[i]<0) break;
                b[a[i]]=true;
                p+=a[i];
        }


    }
    cout<<p;

    return 0;
}
