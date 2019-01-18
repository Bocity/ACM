#include<bits/stdc++.h>
using namespace std;
int hash1[10]={1,0,0,0,1,0,1,0,2,1};
int main()
{

    int t;
    scanf("%d",&t);
    int x,k;
    int pos,pos1;
    while(t--)
    {
        scanf("%d%d",&x,&k);
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
            cout<<k%2<<endl;
    }
}
