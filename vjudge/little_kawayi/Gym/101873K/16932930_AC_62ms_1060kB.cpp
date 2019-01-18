#include<bits/stdc++.h>
using namespace std;
int n,d,k;
struct node
{
    string name;
    int sal;
};
bool cmp(node a,node b)
{
    return a.sal>b.sal;
}
int main()
{
    cin>>n>>d>>k;
    node a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].sal;
    }
    sort(a,a+n,cmp);
    vector<string> ans;
    int pos=0;
    for(int i=0;i<k;i++)
    {
        pos+=a[i].sal;
        ans.push_back(a[i].name);
        if(pos>=d)
            break;
    }
    if(pos<d)
        cout<<"impossible"<<endl;
    else
    {
        cout<<ans.size()<<endl;
        for(auto e:ans)
        {
            cout<<e<<", YOU ARE FIRED!"<<endl;
        }
    }


}
