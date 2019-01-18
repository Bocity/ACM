#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;  
struct node  
{  
    int l,r;  
    bool operator<(const node &a)const  
    {  
        return l<a.l;  
    }  
}s[maxn];  
multiset<int>st;  
int main()  
{  
    ios::sync_with_stdio(false);  
    int T;  
    cin>>T;  
    while(T--)  
    {  
        st.clear();  
        int n;  
        cin>>n;  
        for(int i=0;i<n;i++)  
            cin>>s[i].l>>s[i].r;  
        int ans=0;  
        ll res=0;  
        sort(s,s+n);  
        for(int i=0;i<n;i++)  
        {  
            auto it=st.upper_bound(s[i].l);//寻找>=s[i].l的r  
            if(it==st.begin())//再开一个机器  
            {  
                ans++;  
                res+=s[i].r-s[i].l;  
                st.insert(s[i].r);  
                continue;  
            }  
            it--;//这里是离该i区间的起始点最近的结束点  
            res+=s[i].r-*it;//把这个区间的结束点接上上个结束点，不需要注意起点在哪  
            st.erase(it);//删掉当前区间结束点  
            st.insert(s[i].r);//重新更新  
        }  
        cout<<ans<<' '<<res<<endl;  
    }  
    return 0;  
}  