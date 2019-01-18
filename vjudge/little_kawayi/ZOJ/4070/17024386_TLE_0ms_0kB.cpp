#include<bits/stdc++.h>
using namespace std;
int hash1[10]={1,0,0,0,1,0,1,0,2,1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int x,k;
    int pos,pos1;
    while(t--)
    {
        cin>>x>>k;
        while(k!=0&&x!=0)
        {
            k--;
            pos=x;
            x=0;
            while(pos!=0)
            {
                x+=hash1[pos%10];
                pos/=10;
            }
        }
        if(x!=0)
            cout<<x<<endl;
        else
            cout<<(k&1)<<endl;
    }
}
