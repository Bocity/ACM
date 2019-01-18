#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long check(long long x){
    long long p = x;
    long long num=0;
   long long ans= 0;
    bool flag= false;
    while (p!=0){
         if (!flag){
            ans += p%10;
            flag =true;
        }
        else{
            ans-= p%10;
            flag= false;
        }
        p/=10;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    ll n,m,anss,t,l,r;
    n=1;
    cin>>t;
    while(t--){
        cin>>l>>r;
    bool flag = false;
    for(long long i=r;i>=l;i--){
        m=i;
        if (m%11==3&&(check(i)!=3)||(m%11!=3&&(check(i)==3))){
            flag=true;
            cout<<m<<endl;
            break;
        }
    }
        if (!flag){
             cout<< -1<<endl;
        }
    }

    return 0;
}