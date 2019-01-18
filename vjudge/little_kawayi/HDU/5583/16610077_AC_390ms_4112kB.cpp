#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  t;
    int cas=1;
    cin>>t;
    while(t--)
    {
        string c;
        cin>>c;
        vector<long long >ans;
        long long  pos=0;
        for(int i=0;i<c.size();i++)
        {
            if(i==0)
                pos++;
            else
            {
                if(c[i]==c[i-1])
                    pos++;
                else
                {
                    ans.push_back(pos);
                    pos=1;
                }
            }
        }
        ans.push_back(pos);
//        for(int i=0;i<ans.size();i++)
//            cout<<ans[i]<<" ";
//        cout<<endl;
        if(ans.size()==1)
        {
            cout<<"Case #"<<cas++<<": "<<(ans[0]*ans[0])<<endl;
        }else
        {
            int maxx=0;
            vector<long long >ans1;
            maxx=ans[0];
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]>maxx)
                {
                    maxx=ans[i];
                    ans1.clear();
                }else
                if(ans[i]==maxx)
                {
                    ans1.push_back(i);
                }
            }
            long long anss=0,anss1=0;
            for(int i=0;i<ans.size();i++)
                anss+=ans[i]*ans[i];
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]==1)
                {
                    if(i==0)
                    {
                        anss1=max(anss1,anss+2*ans[1]);
                    }else
                    if(i==ans.size()-1)
                    {
                        anss1=max(anss1,anss+2*ans[i-1]);
                    }else
                    {
                        anss1=max(anss1,anss-1-ans[i-1]*ans[i-1]-ans[i+1]*ans[i+1]+(ans[i-1]+1+ans[i+1])*(ans[i-1]+1+ans[i+1]));
                    }
                }
            }
//            for(auto e:ans1)
//                cout<<e<<" ";
//            cout<<endl;
            long long  minxx=9999999;
            for(int i=0;i<ans1.size();i++)
            {
                if(ans1[i]-1>=0)
                    minxx=min(minxx,ans[ans1[i]-1]);
                if(ans1[i]+1<ans.size())
                    minxx=min(minxx,ans[ans1[i]+1]);
            }
            anss=max(anss,anss-minxx*minxx-maxx*maxx+(1+maxx)*(1+maxx)+(minxx-1)*(minxx-1));
            cout<<"Case #"<<cas++<<": "<<max(anss1,anss)<<endl;
        }
    }
}
