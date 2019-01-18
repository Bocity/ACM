#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node
{
    int num;
    int w;
    bool operator <(const node a)
    {
        return w==a.w?(num>a.num):(w>a.w);
    }
}a[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q[35];
        memset(q,0,sizeof q);
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].num;
            ans2^=a[i].num;
            int pos=a[i].num;
            while(pos!=0)
            {
                if(pos&1)
                    q[a[i].w]++;
                a[i].w++;
                pos>>=1;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
        }
        sort(a,a+n);
        int pos;
        for(int i=34;i>=0;i--)
        {
            if(q[i]%2!=0)
            {
                pos=i;
                break;
            }
        }
        pos++;
        for(int i=0;i<n;i++)
        {
            if(a[i].w==pos)
            {
                ans1=a[i].num;
                break;
            }
        }
        if(ans1==(ans2^ans1))
        {
            cout<<"D"<<endl;
        }else if(ans1>(ans2^ans1))
        {
            cout<<"Q"<<endl;
        }else
        {
            cout<<"T"<<endl;
        }
    }
}
