#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
string c;
int main()
{
    while(cin>>c)
    {
        c='2'+c;
        c=c+'2';
        int n=c.size()/3;
        int cnt=0;
        for(int i=0;i<3*n;i++)
        {
            if(c[i]!=c[i+1])
                cnt++;
        }
        if(cnt>=2*n)
        {
            cout<<0<<endl;
            continue;
        }
        vector<int>ans;
        for(int i=2;i<3*n-1;i++)
        {
            if(c[i]==c[i-1]&&c[i]==c[i+1]&&c[i]==c[i+2])
            {
                ans.push_back(i);
                for(int j=0;j<2;j++)
                {
                    if(c[i+j]=='0')
                        c[i+j]='1';
                    else
                        c[i+j]='0';
                }
            }
            if(ans.size()==n)
                break;
        }
        for(int i=2;i<3*n-1;i++)
        {
            if(ans.size()==n)
                break;
            if(c[i]==c[i-1]&&c[i+1]==c[i+2])
            {
                swap(c[i],c[i+1]);
                ans.push_back(i);
            }
            if(ans.size()==n)
                break;
        }
        for(int i=1;i<3*n;i++)
        {
            if(ans.size()==n)
                break;
            int pos1=0,pos2=0;
            for(int j=i-1;j<i+2;j++)
                if(c[j]!=c[j+1])
                pos1++;
            char pos[4];
            for(int j=0;j<2;j++)
            {
                if(c[i+j]=='0')
                    pos[j+1]='1';
                else
                    pos[j+1]='0';
            }
            pos[0]=c[i-1];
            pos[3]=c[i+2];
            for(int j=0;j<3;j++)
                if(pos[j]!=pos[j+1])
                pos2++;
            if(pos2>pos1)
            {
                for(int j=0;j<2;j++)
                {
                    if(c[i+j]=='0')
                        c[i+j]='1';
                    else
                        c[i+j]='0';
                }
                ans.push_back(i);
            }
            if(ans.size()==n)
                break;
        }
        cnt=0;
        for(int i=0;i<3*n;i++)
        {
            if(c[i]!=c[i+1])
                cnt++;
        }
        if(cnt<2*n)
            while(1);
        cout<<ans.size()<<endl;
        for(auto e:ans)
            cout<<e<<" ";
        cout<<endl;
    }
}
/*
000000000
111001000111
010101
*/
