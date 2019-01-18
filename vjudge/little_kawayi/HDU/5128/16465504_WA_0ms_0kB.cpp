#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    node(){};
    node (int a,int b)
    {
            x=a,y=b;
    }
    bool operator < (const node & a )const
    {
        if(x==a.x)
            return y<a.y;
        else
            return x<a.x;
    }
};
vector<node>point;
struct node1{
    node p[4];
};
vector<node1> jz;
bool cmp(node a,node b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }else
        return a.x<b.x;
}
bool check(int a,int b)
{
    if(jz[a].p[0].x>jz[b].p[0].x)
        swap(a,b);
    if(jz[a].p[3].x>jz[b].p[0].x&&jz[a].p[3].x>jz[b].p[3].x&&
       jz[a].p[3].y>jz[b].p[0].y&&jz[a].p[3].y>jz[b].p[3].y&&
       jz[a].p[0].x<jz[b].p[0].x&&jz[a].p[0].x<jz[b].p[3].x&&
       jz[a].p[0].y<jz[b].p[0].y&&jz[a].p[0].y<jz[b].p[3].y
       )
        return 1;
    if(jz[a].p[3].x>=jz[b].p[0].x&&jz[a].p[3].y>=jz[b].p[0].y)
    {
        return 0;
    }else
    if(jz[a].p[3].x>=jz[b].p[0].x&&jz[a].p[3].y==jz[b].p[0].y)
    {
        return 0;
    }else
    if(jz[a].p[3].y>=jz[b].p[0].y&&jz[a].p[3].x==jz[b].p[0].x)
    {
        return 0;
    }
    return 1;
}
long long getans(int a,int b)
{
    long long ans1=0;
    ans1+=abs(jz[a].p[0].x-jz[a].p[3].x)*abs(jz[a].p[0].y-jz[a].p[3].y);
    ans1+=abs(jz[b].p[0].x-jz[b].p[3].x)*abs(jz[b].p[0].y-jz[b].p[3].y);
    return ans1;
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        point.clear();
        jz.clear();
        map<node,bool> use;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            point.push_back(node{x,y});
            use[node{x,y}]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    bool flag=0;
                    node pos[4];
                    pos[0].x=point[i].x,pos[0].y=point[i].y;
                    pos[2].x=point[j].x,pos[2].y=point[j].y;
                    pos[1].x=point[j].x,pos[3].y=point[j].y;
                    pos[3].x=point[i].x,pos[1].y=point[i].y;
                    for(int k=0;k<4;k++)
                    {
                        if(use[pos[k]]==0)
                            flag=1;
                    }
                    for(int k=0;k<4;k++)
                    {
                        for(int l=0;l<4;l++)
                        {
                            if(k!=l&&pos[k].x==pos[l].x&&pos[k].y==pos[l].y)
                            {
                                flag=1;
                            }
                        }
                    }
                    if(flag==0)
                    {
                        node1 pos1;
                        for(int k=0;k<4;k++)
                            pos1.p[k].x=pos[k].x,pos1.p[k].y=pos[k].y;
                        sort(pos1.p,pos1.p+4,cmp);
                        jz.push_back(pos1);
                    }
                }
            }
        }

//        for(auto e:use)
//            cout<<e.first.x<<" "<<e.first.y<<" "<<e.second<<endl;
        long long ans=-1;
//        for(int i=0;i<jz.size();i++)
//        {
//            cout<<i<<" ";
//            for(int j=0;j<4;j++)
//                cout<<jz[i].p[j].x<<" "<<jz[i].p[j].y<<" ";
//            cout<<endl;
//        }
        for(int i=0;i<jz.size();i++)
        {
            for(int j=0;j<jz.size();j++)
            {
                if(i!=j&&check(i,j))
                {
                    ans=max(ans,getans(i,j));
//                    cout<<i<<" "<<j<<" "<<getans(i,j)<<endl;
                }

            }
        }
        if(ans==-1)
            cout<<"imp"<<endl;
        else
        cout<<ans<<endl;
    }

}
