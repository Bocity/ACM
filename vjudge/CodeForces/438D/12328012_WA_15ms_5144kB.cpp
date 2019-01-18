#include<bits/stdc++.h>
using namespace std;
#define ll int
#define INF 1e9+7
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-8
#define pi acos(-1)
#define lrt rt<<1
#define rrt rt<<1|1
#define lson l,m,lrt
#define rson m+1,r,rrt
const int MAXN=100005;
ll sum[MAXN<<2]; 
ll maxx[MAXN<<2];
//int add[MAXN<<2];

void pushup(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	maxx[rt]=maxx[rt<<1]+maxx[rt<<1|1];
}

//void pushdown(int rt,int m)
//{
//	if(add[rt]!=0)
//	{
//		add[rt*2]=add[rt];
//		add[rt*2+1]=add[rt];
//		sum[rt*2]=add[rt]*(m-m/2);
//		sum[rt*2+1]=add[rt]*(m/2);
//		add[rt]=0;
//	}
//}

void build(int l,int r,int rt)
{
   // add[rt]=0;
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		maxx[rt]=sum[rt];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update1(int L,int c,int l,int r,int rt)
 {
 	if(L==l&&l==r)
 	{
 		sum[rt]=c;
 		maxx[rt]=c;
 		return;
	}
	int m=(l+r)>>1;
	if(L<=m)
	    update1(L,c,l,m,rt<<1);
	else
	    update1(L,c,m+1,r,rt<<1|1);
	pushup(rt);
	return;
 }
 
void update2(int L,int R,int c,int l,int r,int rt)
{
	if(maxx[rt]<c)
	{
		return;
	}
	if(L<=l&&r<=R&&l==r)
	{
		sum[rt]%=c;
		maxx[rt]%=c;
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)
	    update2(L,R,c,l,m,rt<<1);
	if(R>m)
	    update2(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
	return;
}


//区间更新  区间内所有的值赋为c 
//void update(int L,int R,int c,int l,int r,int rt)
//{
//	if(L<=l&&r<=R)
//	{
//		add[rt]=c;
//		sum[rt]=c*(r-l+1);
//		return;
//	}
//	pushdown(rt,r-l+1);
//	int m=(l+r)/2;
//	if(L<=m)
//	    update(L,R,c,l,m,rt*2);
//	if(m<R)
//	    update(L,R,c,m+1,r,rt*2+1);
//	pushup(rt);
//	return;
//}

ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return sum[rt];
	}
	//pushdown(rt,r-l+1);
	int m=(l+r)>>1;
	ll ret=0;
	if(L<=m)
	    ret+=query(L,R,l,m,rt<<1);
	if(R>m)
	    ret+=query(L,R,m+1,r,rt<<1|1);
	return ret; 
}

int main()
{
	int n,m,L,R,flag;
	int p;
	scanf("%d%d",&n,&m);
   	build(1,n,1);
   	while(m--)
   	{
   		scanf("%d%d%d",&flag,&L,&R);
   		if(flag==3)
   		{
   			update1(L,R,1,n,1);
		}
		 if(flag==2)
		{
			scanf("%d",&p);
			update2(L,R,p,1,n,1);
		}
		else if(flag==1)
		{
			printf("%lld\n",query(L,R,1,n,1));
		}
	}

	return 0;
}