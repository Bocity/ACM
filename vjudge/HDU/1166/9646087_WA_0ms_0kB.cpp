#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 500000;
//long long a[N];
// struct node{
//     int l,r,id;
// }Q[maxn];
int n,m,k;
int L=1,R=0;
long long Ans=0;
// int pos[maxn];
// long long ans[maxn];
// long long flag[maxn];
//int a[maxn];
inline int read(){
    int n=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
struct BIT {
    ll a[N], n;
    void init(int i) {
        memset(a, 0, sizeof a);
        n = i;
    }
    inline int lowbit(int x) {
        return (x & -x);
    }
    void update(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) a[i] += v;
    }
    ll sum(int x) {
        ll res = 0;
        for (int i = x; i; i -= lowbit(i)) res += a[i];
        return res;
    }
} T;
int t;
int main(){
    ios::sync_with_stdio(false);
    string s;
    cin>>t;
    int casee=0;
    while(t--){
        T.init(N);
        casee++;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            T.update(i,x);
        }
        int i=0;
        printf("Case %d:\n",casee);
        int x,y;
        while(cin>>s){
            if (s=="End")break;
            cin>>x>>y;
            //cout<<s<<endl;
            if (s=="Add"){
              //  scanf("%d%d",&x,&y);
              //  DE();
                T.update(x,y);
            }
            if (s=="Sub"){
               // int x,y;
                //scanf("%d%d",&x,&y);
                T.update(x,-y);
            }
            if (s=="Query")
            {//int l ,r;
               // scanf("%d%d",&l,&r);
                printf("%d\n",T.sum(y)-T.sum(x-1));
              //  DE();
            }

        }
    }
    return 0;
}