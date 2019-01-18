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
        if(n>=m)
        {
            if(n%2==0)
            {
                int jc=0;
                for(int i=0;i<n;i++)
                {
                    if(jc==0)
                        a[i][0]='(';
                    else
                        a[i][0]=')';
                    for(int j=1;j<m;j++)
                        if(a[i][j-1]=='(')
                           a[i][j]=')';
                           else
                            a[i][j]='(';
                    jc=!jc;
                }
            }else
            if(m%2==0)
            {
                int jc=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                     {

                        if(jc)
                           a[i][j]=')';
                           else
                            a[i][j]='(';
                    jc=!jc;
                     }
                }
            }else
            {
                int jc=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                     {

                        if(jc)
                           a[i][j]=')';
                           else
                            a[i][j]='(';
                    jc=!jc;
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
        }else
        {
            swap(n,m);
            if(n%2==0)
            {
                int jc=0;
                for(int i=0;i<n;i++)
                {
                    if(jc==0)
                        a[i][0]='(';
                    else
                        a[i][0]=')';
                    for(int j=1;j<m;j++)
                        if(a[i][j-1]=='(')
                           a[i][j]=')';
                           else
                            a[i][j]='(';
                    jc=!jc;
                }
            }else
            if(m%2==0)
            {
                int jc=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                     {

                        if(jc)
                           a[i][j]=')';
                           else
                            a[i][j]='(';
                    jc=!jc;
                     }
                }
            }else
            {
                int jc=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                     {

                        if(jc)
                           a[i][j]='(';
                           else
                            a[i][j]=')';
                    jc=!jc;
                     }
                }
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<a[j][i];
                }
                cout<<endl;
            }
        }

    }
}
