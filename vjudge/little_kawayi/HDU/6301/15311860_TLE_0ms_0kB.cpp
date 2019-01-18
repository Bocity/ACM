#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node
{
    int l,r;
    bool operator < (const node & a)
    {
        if(l==a.l)
            return r<a.r;
        else
            return l<a.l;
    }
};
int ans[maxn];
node q[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        stack<int> st;
        for(int i=maxn; i>=1; i--)
            st.push(i);
        for(int i=1; i<=m; i++)
        {
            cin>>q[i].l>>q[i].r;
        }
        sort(q+1,q+m+1);
//        for(int i=1;i<=m;i++)
//            cout<<q[i].l<<" "<<q[i].r<<endl;
        memset(ans,0,sizeof ans);
        vector<int>pos;
        for(int i=1; i<=m; i++)
        {
            if(i!=1)
            {
                pos.clear();
                //cout<<q[i-1].l<<" "<<q[i].l<<endl;
                for(int j=q[i-1].l;j<q[i].l;j++)
                {
                    //cout<<ans[j]<<endl;
                    if(ans[j]!=0)
                    {
                        pos.push_back(ans[j]);

                    }
                }
                if(pos.size()!=0)
                {
                    sort(pos.begin(),pos.end(),greater<int>());
                    for(auto e:pos)
                    {
                        //cout<<e<<endl;
                        st.push(e);
                    }
                }

            }
            for(int j=q[i].l;j<=q[i].r;j++)
            {
                if(ans[j]==0)
                {
                    ans[j]=st.top();
                    st.pop();
                }
            }
//            if(i!=1)
//            {
//                pos.clear();
//                for(int j=q[i-1].l; j<q[i].l; j++)
//                {
//                    if(ans[j]!=0)
//                    {
//                        pos.push_back(ans[j]);
//                        cout<<j<<" "<<q[i-1].l<<" "<<q[i].l<<" "<<i<<endl;
//
//                    }
//                }
//                if(pos.size()==0)
//                    continue;
//                sort(pos.begin(),pos.end());
//                for(int j=pos[pos.size()-1]; j>=0; j--)
//                    st.push(pos[j]);
//            }
//            for(int j=q[i].l; j<=q[i].r; j++)
//            {
//                if(!ans[j])
//                {
//                    cout<<st.top()<<" "<<st.size()<<endl;
//                    ans[j]=st.top();
//                    st.pop();
//
//                }
//            }
//            for(int j=1; j<=n; j++)
//                cout<<ans[j]<<" ";
//            cout<<endl;
        }
        for(int i=1; i<=n; i++)
            if(ans[i]==0)
                ans[i]=1;
        for(int i=1; i<=n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
/*
1000
5 3
1 3
2 4
3 5
*/
