#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {


    unsigned long long a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bool jc=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( a[j]<a[i])
            {
                jc=1;
                break;
            }
        }
    }
    if(jc)
    cout<<"no"<<endl;
    else
cout<<"yes"<<endl;
    }
}
