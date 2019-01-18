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
    for (int i=s.length()-2;i>=0;i--)
    {
        if (s[i]!='5')
        {

            x+=(s[i]-'0')*t;
            t*=10;
        }
        else{
            a[ii]=x;
            ii++;
            t=1;
            x=0;
        }
    }
    a[ii]=x;
    sort(a,a+ii+1,cmp);
    for (int j=ii;j>0;j--)
    {
        cout<<a[j]<<" ";
    }
    cout<<a[0]<<"\n";
    }
    return 0;
}
