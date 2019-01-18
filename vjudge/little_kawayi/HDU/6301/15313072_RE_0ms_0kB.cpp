//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//struct node
//{
//    int l,r;
//    bool operator < (const node & a)
//    {
//        if(l==a.l)
//            return r<a.r;
//        else
//            return l<a.l;
//    }
//};
//int ans[maxn];
//node q[maxn];
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int n,m;
//        cin>>n>>m;
//        stack<int> st;
//        for(int i=maxn; i>=1; i--)
//            st.push(i);
//        for(int i=1; i<=m; i++)
//        {
//            cin>>q[i].l>>q[i].r;
//        }
//        q[0].r=0;
//        sort(q+1,q+m+1);
////        for(int i=1;i<=m;i++)
////            cout<<q[i].l<<" "<<q[i].r<<endl;
//        memset(ans,0,sizeof ans);
//        vector<int>pos;
//        int mmmx=1;
//        for(int i=1; i<=m; i++)
//        {
//            if(i!=1)
//            {
//                pos.clear();
//                for(int j=q[i-1].l;j<q[i].l;j++)
//                {
//                    if(ans[j]!=0)
//                    {
//                        pos.push_back(ans[j]);
//
//                    }
//                }
//                if(pos.size()!=0)
//                {
//                    sort(pos.begin(),pos.end(),greater<int>());
//                    for(auto e:pos)
//                    {
//                        st.push(e);
//                    }
//                }
//
//            }
//            for(int j=max(mmmx,q[i].l);j<=q[i].r;j++)
//            {
//                if(ans[j]==0)
//                {
//                    ans[j]=st.top();
//                    st.pop();
//                }
//            }
//            mmmx=q[i].r+1;
//        }
//        for(int i=1; i<=n; i++)
//            if(ans[i]==0)
//                ans[i]=1;
//        for(int i=1; i<=n; i++)
//            cout<<ans[i]<<" ";
//        cout<<endl;
//    }
//}
/*
1000
5 3
1 3
2 4
3 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+20;
struct seg
{
	int l, r;
	friend bool operator<(seg a, seg b)
	{
		return a.l < b.l || a.l == b.l && a.r < b.r;
	}
} s[N];
int stk[N], cnt, ans[N + 1];
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> s[i].l >> s[i].r;
		sort(s, s + m);
		cnt = n;
		for (int i = n - 1, j = 1; i >= 0; i--, j++)
			stk[i] = j;
		for (int i = 1; i <= n; i++)
			ans[i] = 1;
		for (int i = 0; i < m; i++)
		{
			if (i)
			{
				int pre = cnt;
				for (int j = s[i - 1].l, k = min(s[i - 1].r, s[i].l - 1); j <= k; k--)
					stk[cnt++] = ans[k];

                if(pre!=cnt)
				sort(stk + pre, stk + cnt, greater<int>());
			}
			int st = s[i].l;
			if (i)
				st = max(st, s[i - 1].r + 1);
			for (int j = st; j <= s[i].r; j++)
				ans[j] = stk[--cnt];
		}
		cout << ans[1];
		for (int i = 2; i <= n; i++)
			cout << ' ' << ans[i];
		cout << endl;
	}
	return 0;
}
