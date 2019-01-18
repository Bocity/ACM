#include <bits/stdc++.h>
using namespace std;
long long a[100000];
long long b[100000];
int n;
long long ans=0;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
            int t=0,p;
            long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                t++;
                b[t]=a[i]+a[j];
            }
        }
        p=unique(b+1,b+1+t)-b;
       // cout<<p<<endl;
        for(int i=1;i<p;i++){
        //    cout<<b[i]<<" ";
            ans+=b[i];
        }
       cout<<ans<<endl;

    }
    return 0;
}