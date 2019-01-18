#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int T,n,ans;
string s[1000];
int  dfs()
{
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (s[i][j]!='.' && s[i][j]!='B')
            {
            int x=0;
            while(i+x!=n && j+x!=n && s[i+x][j+x]!='.' && s[i+x][j+x]!='B')
            {
                
                if (s[i+x][j+x]=='G')s[i+x][j+x]='B';
                else s[i+x][j+x]='.';
                x++;
            }
            ans++;
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (s[i][j]!='.')
            {
            int x=0;
            while(i+x!=n && j-x!=-1 && s[i+x][j-x]!='.')
            {
               
                s[i+x][j-x]='.';
                 x++;
            }
            ans++;
            }
        }
    }
    return ans;
}
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>s[i];
        ans=0;
        cout<<dfs()<<"\n";

    }
    return 0;
}