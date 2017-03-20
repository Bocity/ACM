#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    for (int i=1;i<=8;i++)
    {
    for(int j=1;j<=8;j++)
    {
        printf("%2d ",i-j);
    }
    cout<<"\n";
    }
    return 0;
}