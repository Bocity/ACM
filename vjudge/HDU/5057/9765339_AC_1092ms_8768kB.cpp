#include <bits/stdc++.h>
#define endl "\n"
using namespace std;  
const int MAX=100001;  
int tree[MAX][10];      //第二维表示数字是几  
int num[MAX];  
int mark[MAX];  
int n,m;  
  
struct node  
{  
    int p;  
    int a,b,c,d,ans;  
} op[MAX];  
  
int lowbit(int x)  
{  
    return (x)&(-x);  
}  
  
void update(int a,int b,int v)  
{  
    while (a<=n)  
    {  
        tree[a][b]+=v;  
        a+=lowbit(a);  
    }  
}  
  
int sum(int a,int b)  
{  
    int s=0;  
    while (a>0)  
    {  
        s+=tree[a][b];  
        a-=lowbit(a);  
    }  
    return s;  
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
        for(int i = 1;i <= m;i++){
            char s;
            cin>>s;
            if (s=='Q'){
                op[i].p = 2;
                cin>> op[i].a>> op[i].b>> op[i].c>> op[i].d;
            }
            else{
                op[i].p=1;
                cin >> op[i].a >> op[i].b;
            }
        }
        long long int pp= 1;
        for(int i= 1;i<=10;i++){
            for(int t=1;t<=n;t++){
                for(int k = 0;k<=9;k++){
                    tree[t][k]=0;

                }
            }
            for(int t =1; t<=n ;t++){
                int v= (num[t]/pp)%10;
                update(t,v,1);
                mark[t]=v;
            }
            for(int t=1;t<=m;t++){
                if (op[t].p==1){
                    int v= (op[t].b/pp)%10;
                    update(op[t].a,v,1);
                    update(op[t].a,mark[op[t].a],-1);
                    mark[op[t].a]=v;
                }
                else if (op[t].c==i)
                op[t].ans=sum(op[t].b,op[t].d)-sum(op[t].a-1,op[t].d);
            }
            pp*=10;
        }
        for (int i=1;i<=m;i++){
            if (op[i].p==2)
            cout<<op[i].ans<<endl;
        }
    }
    return 0;
}