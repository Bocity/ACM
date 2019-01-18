#include<bits/stdc++.h>
using namespace std;
int main()
{
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

    for(int i=0;i<xx;i++)
    {
        for(int j=1;j<=x;j++)
        {
            int pos;
            cin>>pos;
            for(int k=0;k<n;k++)
            {
                a[k][j]=min(a[k][j],y-pos);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=x;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
