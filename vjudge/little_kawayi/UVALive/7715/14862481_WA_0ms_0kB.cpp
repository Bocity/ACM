#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l[3], r[3], n;
const ll pos2=5e8+4;
const ll mod=1e9+7;
ll getans(int x)
{
	ll pos=(1+x+1)%mod;
	pos=pos*(x+1)%mod;
	return (pos*pos2)%mod;
}
ll sum(int x)//[0, x] 
{
	if(x==-1)
	return 0;
	ll ans = 0;	
	if(x<=r[0])
	{
		ans+=getans(x);
		ans%=mod;
	}else
	if(x<=r[1])
	{
		ans=getans(r[0])+(x-r[0]+1)*(r[0]+1);
		ans%=mod;
	}else
	{
		ans=getans(r[0])+(r[1]-r[0])*(r[0]+1)%mod+(getans(r[0]-1)-getans(x-r[2]-1)+mod)%mod;
		ans%=mod;
	}
	return ans;
}
main()
{
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
	for (int i = 0; i < 3; i++)
	{
		cin >> l[i] >> r[i];
		r[i] -= l[i];	
	}
	cin >> n;
	n -= l[0] + l[1] + l[2];
	sort(r, r + 3);
	int L = max(0ll, n - r[2]), R = min(n, r[0] + r[1]);
	ll ans = 0;
	ans=sum(R)-sum(L-1);
	cout<<"Case #"<<cas<<": ";
	if(n<0)
	cout<<0<<endl;
	else
	cout<<(ans+mod)%mod<<endl;
}
	return 0;
}