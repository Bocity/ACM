#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 50001;
typedef long long ll;
ll n,m,k;
ll pos[N];
ll c[N];
ll s[N];
ll ans=0;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll sqr(ll x){return x*x;}
struct data{
   ll l,r,id,a,b;
}a[N];
bool cmp(data a,data b)
{
	if(pos[a.l]==pos[b.l])return a.r<b.r;
	return a.l<b.l;
}
bool cmp_id(data a,data b)
{return a.id<b.id;}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	   cin>>c[i];
	int block=int(sqrt(n));
	for(int i=1;i<=n;i++)
	   pos[i]=(i-1)/block+1;
	for(int i=1;i<=m;i++)
	{
	    cin>>a[i].l>>a[i].r;
	    a[i].id=i;
	    }
}
void update(int p,int add)
{
	ans-=sqr(s[c[p]]);
	s[c[p]]+=add;
	ans+=sqr(s[c[p]]);
}
void work(){
for(int i=1,l=1,r=0;i<=m;i++)
	{
		for(;r<a[i].r;r++)
			update(r+1,1);
		for(;r>a[i].r;r--)
		    update(r,-1);
		for(;l<a[i].l;l++)
		    update(l,-1);
		for(;l>a[i].l;l--)
		    update(l-1,1);
		if(a[i].l==a[i].r)
		{
			a[i].a=0;a[i].b=1;
			continue;
		}
		a[i].a=ans-(a[i].r-a[i].l+1);
		a[i].b=(ll)(a[i].r-a[i].l+1)*(a[i].r-a[i].l);
		ll k=gcd(a[i].a,a[i].b);
		a[i].a/=k;a[i].b/=k;
	}
}
int main(){
    init();
    sort(a+1,a+m+1,cmp);
    work();
    sort(a+1,a+1+m,cmp_id);
    for(int i = 1;i <= m ;i++){
        cout<<a[i].a<<"/"<<a[i].b<<endl;
    }
    
    
    return 0;
}