#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<list>  
#include<set>  
#include<map>  
#include<stack>  
#include<queue>  
#include<deque>  
#define mem(x,y) memset(x,y,sizeof(x))  
#define pb push_back  
using namespace std;  
typedef long long ll;  
typedef unsigned long long ull;  
typedef pair<int,double> pii;  
#define bug puts("===========");  
#define zjc puts("");  
const double pi=(acos(-1.0));  
const double eps=1e-8;  
const ll INF=1e18+10;  
const ll inf=1e9+10;  
//const int mod=1e9+7;  
const int maxn=100000+10;  
/*=======================================*/  
char cl[105],cr[105];  
ll add[10];  
ll p10[105],fz[105];  
ll calc(char s[],ll mod){  
    ll len=strlen(s);  
    ll ans=0,f=1,sum=0;  
    for(ll i=0;i<len;i++,f=-f){  
        ll now=s[i]-'0';  
        ll cha=len-i-1;  
        if(now){  
            int fuck=now;  
            if(i==0) fuck--;  
            ans += ((sum*(fuck)+f*add[now-1])%mod*p10[cha]%mod-f*fuck*fz[cha])%mod;  
            ans%=mod;  
        }  
        if(len>i+1) ans += 45*p10[len-i-2]-9*fz[len-i-2];  
        sum=(sum+f*now)%mod;  
    }  
    return (ans+sum)%mod;  
}  
ll calc(ll mod){  
    p10[0]=1;  
    fz[0]=0;  
    for(ll i=1;i<105;i++) {  
        p10[i]=p10[i-1]*10%mod;  
        fz[i]=(fz[i-1]*(-10)+45*p10[i-1])%mod;  
    }  
    ll ret=calc(cr,mod)-calc(cl,mod);  
    return (ret%mod+mod)%mod;  
}  
int main()  
{  
    for(ll i=1;i<=9;i++) add[i]=add[i-1]+i;  
    ll T_T;  
    scanf("%I64d",&T_T);  
    while(T_T--){  
        scanf("%s%s",cl,cr);  
        if(cl[0]!='0') {  
            ll len=strlen(cl);  
            for(ll i=len-1;i>=0;i--) if(cl[i]!='0'){  
                cl[i]--;  
                for(ll j=len-1;j>i;j--) cl[j]='9';  
                if(cl[0]=='0') for(int j=0;j<len;j++) cl[j]=cl[j+1];  
                break;  
            }  
        }  
        ll ans1=calc(9);  
        ll ans2=calc(1e9+7);  
      //  cout<<ans2<<endl;  
        ll ans3=calc(1e9+9);  
        if(ans1==0&&(ans2||ans3)) ans1=9;  
        if(ans1==0) puts("Error!");  
        else printf("%I64d\n",calc(ans1));  
    }  
    return 0;  
}  