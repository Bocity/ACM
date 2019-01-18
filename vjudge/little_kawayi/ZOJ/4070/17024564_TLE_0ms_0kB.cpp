#include<bits/stdc++.h>
using namespace std;
int hash1[10]={1,0,0,0,1,0,1,0,2,1};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,k;
        cin>>x>>k;
        while(k!=0)
        {
            k--;
            int pos=x,pos1=0;
            while(pos!=0)
            {
                pos1+=hash1[pos%10];
                pos/=10;
            }
            x=pos1;
            if(x==0)
                break;
        }
        if(k&1) x ^= 1;
        cout<<x<<endl;
    }
}
