#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
struct  node
{
    string name;
    int p,c,t,r;
};
node a[105];
int sum,n;
vector<node> ans;
bool check(int x)
{
    int t=a[x].t,r=a[x].r,c=a[x].c;
    int cnt=1;
    while(1)
    {
        if(((t+r)*cnt)%10080==0)
            break;
        else
            cnt++;
    }
    cnt = (t+r)*cnt/10080;
    while (cnt > 100000);
    int pos=0;
    for(int i=1;i<=cnt;i++)
    {
        int ssum=0;
        int pos1 = pos+10080;
        ssum+=t*c*(pos1)/(t+r);
        ssum-=min(t,pos)*c;
        pos=pos1-(t+r)*pos1/(t+r);
        ssum+=min(t,pos)*c;
        if(ssum<sum)
            return 0;

    }
    return 1;

}
signed main()
{

    cin>>sum>>n;
    getchar();
    string c;

    int minn=100000000;
    for(int cnt=0; cnt<n; cnt++)
    {
        getline(cin,c);
        for(int i=0; i<c.size(); i++)
            if(c[i]==',')
            {
                c[i]=' ';
            }
            else if(c[i]==' ')
            {
                c[i]=1;
            }
        stringstream in;
        in<<c;
        in>>a[cnt].name>>a[cnt].p>>a[cnt].c>>a[cnt].t>>a[cnt].r;

        if(check(cnt))
        {
            if(a[cnt].p<minn)
            {
                ans.clear();
                ans.push_back(a[cnt]);
                minn=a[cnt].p;
            }
            else if(a[cnt].p==minn)
            {
                ans.push_back(a[cnt]);
            }
        }
    }
    if(ans.size()==0)
    {
        cout<<"no such mower"<<endl;
        return 0;
    }
    for(auto e:ans)
    {
        string c1=e.name;
        for(int i=0; i<c1.size(); i++)
            if(c1[i]==1)
                cout<<" ";
            else
                cout<<c1[i];
        cout<<endl;
    }
}