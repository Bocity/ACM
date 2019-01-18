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
            if(min(n,m)>4)
            {

                for(int i=0; i<m; i++)
                    a[0][i]='(';
                for(int i=0; i<m; i++)
                    a[n-1][i]='(';
                for(int i=1; i<n-1; i++)
                {
                    if(i&1)
                    {
                        for(int j=0; j<m; j++)
                        {
                            if(j&1)
                                a[i][j]=')';
                            else
                                a[i][j]='(';
                        }
                    }
                    else
                    {
                        a[i][0]=a[i][1]='(';
                        a[i][m-1]=a[i][m-2]=')';
                        for(int j=2; j<m-2; j++)
                            if(a[i][j-1]=='(')
                                a[i][j]=')';
                            else
                                a[i][j]='(';
                    }
                }

            }
            else
            {
                if(n<m)
                {
                    if(n==2)
                    {
                        for(int i=0; i<2; i++)
                        {
                            for(int j=0; j<m; j++)
                                if(j&1)
                                    a[i][j]=')';
                                else
                                    a[i][j]='(';
                        }
                    }
                    else if(n==4)
                    {
                        for(int i=0;i<m;i++)
                            a[0][i]='(';
                        for(int i=0;i<m;i++)
                            a[n-1][i]=')';
                        for(int i=0;i<m;i++)
                            if(i&1)
                            a[1][i]=')';
                        else
                            a[1][i]='(';
                          for(int i=0;i<m;i++)
                            if(!(i&1))
                            a[2][i]=')';
                        else
                            a[2][i]='(';
                    }
                }
                else
                {
                    if(m==2)
                    {
                        for(int j=0; j<2; j++)
                        {
                            for(int i=0; i<n; i++)
                            {
                                if(i&1)
                                    a[i][j]=')';
                                else
                                    a[i][j]='(';
                            }
                        }
                    }
                    else if(m==4)
                    {
                        for(int i=0;i<n;i++)
                            a[i][0]='(';
                        for(int i=0;i<n;i++)
                            a[i][m-1]=')';
                        for(int i=0;i<n;i++)
                            if(i&1)
                            a[i][1]=')';
                        else
                            a[i][1]='(';
                          for(int i=0;i<n;i++)
                            if(!(i&1))
                            a[i][2]=')';
                        else
                            a[i][2]='(';
                    }
                }
            }
        }
        else if(n%2==0)
        {
            int jc=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(!jc)
                        a[i][j]='(';
                    else
                        a[i][j]=')';
                }
                jc=!jc;
            }

        }
        else if(m%2==0)
        {
            int jc=0;
            for(int j=0; j<m; j++)
            {
                for(int i=0; i<n; i++)
                {
                    if(!jc)
                        a[i][j]='(';
                    else
                        a[i][j]=')';
                }
                jc=!jc;
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    a[i][j]=')';
                }

            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}
