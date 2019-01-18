#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
long long n;
int main()
{

    while (cin>>n)
    {
            if (n>=90&&n<=100) {cout<<"A\n";continue;}
            if (n>=80&&n<=89) {cout<<"B\n";continue;}
            if (n>=70&&n<=79) {cout<<"C\n";continue;}
            if (n>=60&&n<=69) {cout<<"D\n";continue;}
            if (n>=0&&n<=59) {cout<<"E\n";continue;}
            cout<<"Score is error!\n";
    }
    return 0;
}
