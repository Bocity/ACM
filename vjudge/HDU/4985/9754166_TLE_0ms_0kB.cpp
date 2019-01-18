#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
int fa[200005];
bool vis[200005];
struct ss{
	int x,y;
}q[200005];
int n;
vector<int> qq[100005];
int a[100005];
int t =0;
bool cmp(ss x,ss y){
	return x.y>y.y;
}
int read(){
	int n=0,f=1;
	char ch = getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
inline int find(int x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline void Union (int a,int b){

	int fa1= find(a);
	int fa2= find(b);
	if (fa1<=n&&fa2<=n){
		t++;
		fa[a]=n+t;
		fa[b]=n+t;
		q[t].x=n+t;
		q[t].y+=2;

	}
	else if (fa1<=n){
		fa[a]=fa2;
		q[fa2-n].y++;
	}
	else if (fa2<=n){
		fa[b]=fa1;
		q[fa1-n].y++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		t=0;
		for(int i = 1;i<=2*n ;i++){
			fa[i]=i;
		}
		for(int i=1 ;i<=n;i++){
			a[i]= read();
		}
		for(int i=1;i<=n;i++){
			Union(i,a[i]);
		}
		for(int j=1;j<=n;j++){
			int p =find(a[j])-n;
			qq[p].push_back(a[j]);
		}
		for(int i=1;i<=t;i++){
			cout<<"(";
			for(int j=0;j<qq[i].size()-1;j++){
				cout<<qq[i][j]<<" ";
			}
			cout<<qq[i][qq[i].size()-1]<<")";
		}
		cout<<endl;

		for(int i=1;i<=t;i++)
		qq[i].clear();
	}
	return 0;
}
