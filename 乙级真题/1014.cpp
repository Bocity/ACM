#include<iostream>
#include<cstring>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
string a,b,c,d;
string p[100]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
bool isn(char x)
{
    if ('0'<=x&&x<='9') return true;
    return false;
}
int hour(char x)
{
    if (isn(x))
    {
       return x-'0';
    }
    else
    {
        return (x-'A'+10);
    }
}
bool ischar(char x)
{
    if (x>='A'&&x<='Z') return true;
     if (x>='a'&&x<='z') return true;
    return false;
}
bool isda(char x)
{
    if ('A'<=x&&x<='Z') return true;
    else return false;
}
int main()
{
    int k,j;
    cin>>a>>b>>c>>d;
    k=min(a.length(),b.length());
    for (int i=0;i<k;i++)
    {
        if (isda(a[i]))
        {
            if (a[i]==b[i]&&a[i]<='G') {cout<<p[a[i]-'A']<<" ";j=i;break;}
        }
    }
    for (int i=j+1;i<k;i++)
    {
        if (a[i]==b[i]&&((isda(a[i])&&a[i]<='N')||isn(a[i])))
        {
            int t=hour(a[i]);
            if (t<10) cout<<0;
            cout<<t<<":";
          break;
        }
    }
    k=min(c.length(),d.length());
    for (int i=0;i<k;i++)
    {
        if ((c[i]==d[i])&&ischar(c[i]))
        {
            if (i<10) cout<<0;
            cout<<i;
            break;
        }
    }
    return 0;
}
