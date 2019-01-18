#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int cntt=0;
    while(t--)
    {
        cntt++;
        int n;
        cin>>n;
        string c;
        cin>>c;
        char pos='0';
        for(int i=0;i<c.size();i++)
            if(c[i]>pos)
            pos=c[i];
        string posv;
        for(int i=0;i<20;i++)
            posv+='0';
        int ans;
        for(int i=0;i<n;i++)
        {
            if(c[i]==pos)
            {
                int poscnt=i;
                string cas;
                for(int j=0;j<20;j++)
                {
                    cas+=c[poscnt];
                    poscnt=(poscnt*poscnt+1)%n;
                }
                if(cas>posv)
                {
                    ans=i;
                }
            }
        }
        cout<<"Case #"<<cntt<<": ";
        for(int i=0;i<n;i++)
        {
            cout<<c[ans];
            ans=(ans*ans+1)%n;
        }
        cout<<endl;


    }
}
