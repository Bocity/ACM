#include<iostream>
#include <cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,p,sum=0;
string s;
int main()
{
    cin>>x>>y;
    cin>>s;
    string s2(s);
    for (int i=0; i<x; i++)
    {
        p=max(abs(s[i]-'a'),abs(s[i]-'z'));
        if (abs(s[i]-'a')==p) s2[i]='a';
        else s2[i]='z';
        sum+=p;
        if (sum>=y)
        {
            int t=sum-y;
            if (s2[i]-'a'>=t) s2[i]-=t;
            else s2[i]+=t;
            cout<<s2;
            break;
        }
    }
    if (sum<y) cout<<-1;


    return 0;
}
