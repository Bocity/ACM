    #include <iostream>
    #include <cstring>
    #include <string>
    #include <cstdio>
    #include<algorithm>
    using namespace std;
    bool vis[101][101]={0},tr=false;
    int n,m,sum=0,y,T;
    bool a[1000]={0};
    bool b[1000]={0};
    int c[1000];
    
    
    void dfs(int x,int t)
    {
        if (t==n)
        {
            for (int i=1;i<=n;i++)
            {
            if (!b[i])
            {
            b[i]=true;
            c[t]=i;
            if (!a[c[t]+c[t-1]]&&!a[c[1]+c[n]])
            {
            for (int j=1;j<n;j++)
            cout<<c[j]<<" ";
            cout<<c[n];
            cout<<"\n";
            }
            b[i]=false;
            break;
            }
            }
            return ;
        }
    for (int i=1;i<=n;i++)
    {
        if (!b[i])
        {
            b[i]=true;
            c[t]=i;
            if (!a[c[t]+c[t-1]])
            dfs(n,t+1);
            b[i]=false;
        }
    }
        return;
    }
    
    int main()
    {
        a[1]=true;
        for (int i=2;i<=200;i++)
            for (int j=2;j<=i-1;j++)
                if (i%j==0) a[i]=true;
                        int zz=1;
        cin>>n  ;
            memset(b,false,sizeof(b));
            cout<<"Case "<<zz++<<":\n";
                b[1]=true;
                c[1]=1;
                dfs(n,2);
                b[1]=false;
                while(cin>>n)
                {
                        cout<<"\n";
                            memset(b,false,sizeof(b));
            cout<<"Case "<<zz++<<":\n";
                b[1]=true;
                c[1]=1;
                dfs(n,2);
                b[1]=false;
                }
    
    
    return 0;
    }