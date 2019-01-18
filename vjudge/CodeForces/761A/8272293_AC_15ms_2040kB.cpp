#include<iostream>
#include<cmath>
using namespace std;
int a,b;
int main()
{

    cin>>a>>b;
    if(abs(a-b)<=1&&(b!=0||a!=0))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
