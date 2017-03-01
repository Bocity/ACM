#include<iostream>
using namespace std;
int a[10000],n;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    cin>>a[i];
    int i=7;
    for (int i=1;i<=n-i+1;i++)
    if (i%2==1)
    swap(a[i],a[n-i+1]);
    for (int i=1;i<=n;i++)
    cout<<a[i]<<" ";
    return 0;
}
