#include<bits/stdc++.h>
using namespace std;
const int n=1000005;
int cnt[n];
long prime[n]={0};
int a[n]={1,1};
int num_prime=0;
void peime(int m)
{
    int i,j;
    for(int i=2;i<m;i++)
    {
        if(!a[i])
            prime[num_prime++]=i;
        for(j=0;j<num_prime && i*prime[j]<m;j++)
        {
            a[i*prime[j]]=1;//合数标为1，同时，prime[j]是合数i*prime[j]的最小素因子
            if(!(i%prime[j]))//即比一个合数大的质数和该合数的乘积可用一个更大的合数和比其小的质数相乘得到
                break;
        }
    }
    cnt[0]=0;
    for(int i=1;i<n;i++)
    {
        cnt[i]=cnt[i-1];
        if(a[i]!=1)
        {
            cnt[i]++;
        }
        //cout<<cnt[i]<<" ";
    }
    cnt[1]=0;
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    peime(n);
    //cout<<cnt[1]<<endl;
    while(t--)
    {
        long long  n,d;
        cin>>n>>d;
	if (d > n/2){
		cout << 0 << endl;
		continue;
	}
        long long dd=d*d;
        long long ans=min(n-1,dd)/d;
        //cout<<ans<<" ";
        
        cout<<cnt[ans]<<endl;
    }
}