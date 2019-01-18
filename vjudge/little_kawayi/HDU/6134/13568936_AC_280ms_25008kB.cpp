#include<stdio.h>  
#include<string.h>  
#define mod 1000000007  
#define LL long long  
LL cnt[1000005], sum[1000005] = {0,1}, ans[1000005] = {0,1};  
int main(void)  
{  
    LL n, i, j;  
    for(i=1;i<=1000000;i++)  
    {  
        for(j=i;j<=1000000;j+=i)  
            cnt[j]++;  
    }  
    for(i=2;i<=1000000;i++)  
        sum[i] = (sum[i-1]+cnt[i-1]+1)%mod;  
    for(i=1;i<=1000000;i++)  
    {  
        for(j=i+i;j<=1000000;j+=i)  
            sum[j] = ((sum[j]-sum[i])%mod+mod)%mod;  
    }  
    for(i=2;i<=1000000;i++)  
        ans[i] = (sum[i]+ans[i-1])%mod;  
    while(scanf("%lld", &n)!=EOF)  
        printf("%lld\n", ans[n]);  
    return 0;  
}  