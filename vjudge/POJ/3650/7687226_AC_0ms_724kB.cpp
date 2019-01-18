#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string s;
    while (getline(cin,s)&&s!="#")
    {
        for (int i=0;i<=s.length()-1;i++)
        {
            if (s[i]==' ') {cout<<"%20";continue;}
            if (s[i]=='!') {cout<<"%21";continue;}
            if (s[i]=='$') {cout<<"%24";continue;}
            if (s[i]=='%') {cout<<"%25";continue;}
            if (s[i]=='(') {cout<<"%28";continue;}
            if (s[i]==')') {cout<<"%29";continue;}
            if (s[i]=='*') {cout<<"%2a";continue;}
            cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}
