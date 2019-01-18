#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std;
#define LL long long

int main(){
    LL n,m;
    while(scanf("%I64d %I64d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        LL fz=n*(m-1);
        LL fm=m*m;
if (fz!=0){
        LL gcd=__gcd(fz,fm);
        fz=fz/gcd;
        fm=fm/gcd;
}
else {
fm=1;
}
        printf("%I64d/%I64d\n",fz,fm);
    }
    return 0;
}