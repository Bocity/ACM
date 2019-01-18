#include<bits/stdc++.h>
using namespace std;
char a[205][205];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n%2==0&&m%2==0)
        {
            if(n/2<=m/2)
            {
                for(int i=0;i<m;i++)
                {
                    a[0][i]='(';
                }
                for(int i=1;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(a[i-1][j]=='(')
                            a[i][j]=')';
                        else
                            a[i][j]='(';
                    }
                }
            }else
            {
                for(int i=0;i<n;i++)
                {
                    a[i][0]='(';
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=1;j<m;j++)
                        if(a[i][j-1]=='(')
                            a[i][j]=')';
                        else
                            a[i][j]='(';
                }
            }
        }else
        if(n%2==0)
        {
            int jc=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(!jc)
                        a[i][j]='(';
                    else
                        a[i][j]=')';
                }
                jc=!jc;
            }

        }else
        if(m%2==0)
        {
            int jc=0;
            for(int j=0;j<m;j++)
            {
                for(int i=0;i<n;i++)
                {
                    if(!jc)
                        a[i][j]='(';
                    else
                        a[i][j]=')';
                }
                jc=!jc;
            }
        }else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                        a[i][j]=')';
                }

            }
        }
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<a[i][j];
                }
                cout<<endl;
            }
    }
}
