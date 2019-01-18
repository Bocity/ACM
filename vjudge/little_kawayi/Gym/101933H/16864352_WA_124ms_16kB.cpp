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
    for (int i = 1; i <= 100000; i++)
        if (10080 * i / (a[x].t + a[x].r) * (a[x].c * a[x].t) + max(10080 * i % (a[x].t + a[x].r), a[x].t) < i * sum)
            return 0;
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
