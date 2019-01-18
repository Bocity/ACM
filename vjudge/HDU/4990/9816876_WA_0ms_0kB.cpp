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

long long mod,x,y;
void extend_Euclid(long long a, long long b)  
{  
    if(b==0)  
    {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a%b);  
    long long t = x;  
    x = y;  
    y = t - a/b*y;  
} 
long long a[100000];
long long b[100000];
long long n,m,ans;
long long a1;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        a1= 1%m;
        mod= m;
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
            long long xx=pow(2,n-1,m);
            long long y=pow(4,N-2,m);
          //  cout<< x << " "<<y;
            extend_Euclid(3,m);
            x=(x%mod+mod)%mod;
            ans = (xx)%m+(y)%m+(y-1)*x%m;
        }
        else{
            long long N=n/2;
            long long xx=pow(2,n-1,m);
            long long y=pow(4,N-2,m);
           // cout<< x<<" "<<y<<en
            extend_Euclid(3,m);
            x=(x%mod+mod)%mod;
            ans = xx%m+2*y%m+2*(y-1)*x%m;
        }
        cout<<ans%m<<endl;
    }
    return 0;
}