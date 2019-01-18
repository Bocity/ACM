#include<bits/stdc++.h>
using namespace std;
int sz[26];
int main()
{
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
        string c;
        cin>>c;
        int ans=999999;
        memset(sz,0,sizeof sz);
        for(int i=0;i<c.size();i++)
        {
            int id=c[i]-'a';
            if(sz[id]==0)
            {
                sz[id]=i+1;
            }else
            {
                ans=min(i+1-sz[id],ans);
                sz[id]=i+1;
            }
        }
        if(ans==999999)
            cout<<"Case #"<<cas++<<": "<<-1<<endl;
        else

        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
}
