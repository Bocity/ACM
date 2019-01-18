#include<iostream>
#include<string.h>
using namespace std;
string a, b;
int main()
{

    int la,lb;
    cin>>a>>b;
    la = a.length();
    lb = b.length();
    if(la!=lb)
    {
        cout<<(la>lb?la:lb);
    }
    else if(!(a==b))
    {
        cout<<la;
    }
    else
    {
      cout<<0-1;
    }
    return 0;
}
