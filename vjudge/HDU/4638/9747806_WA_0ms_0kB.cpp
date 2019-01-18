#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
const long long N = 300005;
typedef long long ll;
ll n,m,k;
ll pos[N];
ll c[N];
ll s[N];
ll ans=0;
struct data{
   ll l,r,id,a;
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
    memset(s,0,sizeof s);
	for(ll i=1;i<=n;i++)
	   cin>>c[i];
	ll block=ll(sqrt(n));
	for(ll i=1;i<=n;i++)
	   pos[i]=(i-1)/block+1;
	for(ll i=1;i<=m;i++)
	{
	    cin>>a[i].l>>a[i].r;
	    a[i].id=i;
	}
}
void update(ll p,ll add)
{
	ans-=s[c[p]]*s[c[p]]*c[p];
	s[c[p]]+=add;
	ans+=s[c[p]]*s[c[p]]*c[p];
}
void work(){
for(ll i=1,l=1,r=0;i<=m;i++)
	{
		for(;r<a[i].r;r++)
			update(r+1,1);
		for(;r>a[i].r;r--)
		    update(r,-1);
		for(;l<a[i].l;l++)
		    update(l,-1);
		for(;l>a[i].l;l--)
		    update(l-1,1);
		a[i].a=ans;
	}
}
int main(){
    init();
    sort(a+1,a+m+1,cmp);
    work();
    sort(a+1,a+1+m,cmp_id);
    for(ll i = 1;i <= m ;i++){
        cout<<a[i].a<<"\n";
    }
    
    
    return 0;
}