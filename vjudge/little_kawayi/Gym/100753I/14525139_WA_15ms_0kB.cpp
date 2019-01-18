#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,xx;
    cin>>n>>xx;
    int x,y;
    cin>>x>>y;
    int a[n][x+1];
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            cin>>a[i][j];
        }
    }
    int pos;
    int pos1[x+1];
    for(int i=1;i<=x;i++)
        pos1[i]=y;
    for(int i=0;i<xx;i++)
    {
        for(int j=1;j<=x;j++)
        {
            cin>>pos;
            pos1[j]=min(pos1[j],pos);

        }
    }
//    for(int i=1;i<=x;i++)
//        cout<<pos1[i]<<" ";
//    cout<<endl;
    for(int k=0;k<n;k++)
    {
        for(int i=1;i<=x;i++)
        {
            a[k][i]=min(a[k][i],y-pos1[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=x;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
