#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string c;
        cin>>c;
        stack<int> s;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='(')
                s.push(i);
            else
            {
                if(s.empty())
                {
                   ans.push_back(i);
                }else
                {
                    s.pop();
                }
            }
        }
        int pos=(s.size()+1)/2+(ans.size()+1)/2;
        cout<<pos<<endl;
    }
}
