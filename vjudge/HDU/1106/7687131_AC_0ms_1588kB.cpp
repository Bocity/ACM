#include <iostream>
#include<algorithm>
using namespace std;
long long a[2000];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    string s;

    while (cin>>s){
    long long x=0,ii=0,t=1;
    for (int i=s.length()-1;i>=0;i--)
    {
        while (s[i]=='5'&&i>=0) i--;
        if (i==-1) break;
        while (s[i]!='5'&&i>=0)
        {
            x+=(s[i]-'0')*t;
            t*=10;
            i--;
        }
        ii++;
        a[ii-1]=x;
        x=0;
        t=1;
    }
    sort(a,a+ii,cmp);
    for (int j=ii-1;j>0;j--)
    {
        cout<<a[j]<<" ";
    }
    cout<<a[0]<<"\n";
    }
    return 0;
}
