#include<bits/stdc++.h>
using namespace std;
struct  node
{
    string name;
    int p,c,t,r;
};
int main()
{
    int sum,n;
    cin>>sum>>n;
    getchar();
    string c;
    node a[n];
    vector<node> ans;
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
        //cout<<a[cnt].name<<" "<<a[cnt].p<<" "<<a[cnt].c<<endl;
        int pos = 10080/(a[cnt].t+a[cnt].r);
        int pos1= min(10080 - pos*(a[cnt].t+a[cnt].r),a[cnt].t);
        int num = pos*(a[cnt].t)*a[cnt].c + pos1*(a[cnt].c);
//        cout<<pos<<" "<<pos1<<" "<<num<<endl;
        if(num>=sum)
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
