#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long pow(long long a, long long b, long long p) { // return a^b %p
    if (b==0) return 1%p;
    long long t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
long long a[100000];
long long b[100000];
long long n,m,ans;
long long a1;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        a1= 1%m;
        if (n==1){
            cout<<1%m<<endl;
            continue;
        }
        if (n==2){
            cout<<2%m<<endl;
            continue;
        }
        if (n&1){
            long long N=(n+1)/2;
           // cout<<N<<"---"<<endl;
            long long x=pow(2,n-1,m);
            long long y=pow(4,N-2,m);
          //  cout<< x << " "<<y;
            while ((y-1)%3!=0){
                y+=m;
            }
            ans = (x)%m+(y)%m+(y-1)/3%m;
        }
        else{
            long long N=n/2;
            long long x=pow(2,n-1,m);
            long long y=pow(4,N-2,m);
           // cout<< x<<" "<<y<<en
                       while ((y-1)%3!=0){
                y+=m;
                       }
            ans = x%m+2*y%m+2*(y-1)/3%m;
        }
        cout<<ans%m<<endl;
    }
    return 0;
}