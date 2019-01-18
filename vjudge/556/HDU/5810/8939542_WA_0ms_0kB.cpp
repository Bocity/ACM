#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std;
#define ll long long

int main(){
    ll n,m;
    while(scanf("%Ild %lld",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        ll fz=n*(m-1);
        ll fm=m*m;
        ll gcd=__gcd(fz,fm);
        fz=fz/gcd;
        fm=fm/gcd;
        printf("%Ild/%Ild\n",fz,fm);
    }
    return 0;
}