#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int cnt = 1;
    long long n,m;
    while(t--) {
        cin>>n>>m;
        int ans=0;
        int k=__gcd(n,m);
        n=n/k,m=m/k;
        while(1)
        {
            if(n>m)
                swap(n,m);
            ans++;
            if(m%(n+1)==0)
                m=m/(n+1);
            else
                break;


        }
    cout<<"Case #"<<cnt++<<": "<<ans<<endl;
    }

}
