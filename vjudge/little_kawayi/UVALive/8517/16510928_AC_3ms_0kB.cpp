#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        cout<<fixed<<setprecision(5)<<n/(double)(n+m)<<endl;
    }
}

