#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    while(cin>>n>>q)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        int and1[n+5]={1},and2[n+5]={1};
          and1[1]=a[0],and1[n]=a[n-1];
        and1[1]=a[0],and2[n]=a[n-1];

        int or1[n+5]={0},or2[n+5]={0};
          or1[1]=a[0],or1[n]=a[n-1];
        or2[1]=a[0],or2[n]=a[n-1];
        int xor1[n+5]={0},xor2[n+5]={0};
        xor1[1]=a[0],xor1[n]=a[n-1];
        xor2[1]=a[0],xor2[n]=a[n-1];
        for(int i=2;i<=n;i++)
        {
            and1[i]=and1[i-1]&a[i-1];
            //cout<<and1[i]<<" "<<and1[i-1]<<" "<<a[i-1]<<endl;
            or1[i]=or1[i-1]|a[i-1];
            xor1[i]=xor1[i-1]^a[i-1];
        }
        for(int i=n-1;i>=1;i--)
        {
            and2[i]=and2[i+1]&a[i-1];
            or2[i]=or2[i+1]|a[i-1];
            xor2[i]=xor2[i+1]^a[i-1];
            //cout<<or2[i+1]<<endl;
        }


        for(int i=0;i<q;i++)
        {
            int x;
            cin>>x;
            if(x==1)
                cout<<and2[2]<<" "<<or2[2]<<" "<<xor2[2]<<endl;
            else
            if(x==n)
                                cout<<and1[n-1]<<" "<<or1[n-1]<<" "<<xor1[n-1]<<endl;
            else

            cout<<(and1[x-1]&and2[x+1])<<" "<<(or1[x-1]|or2[x+1])<<" "<<(xor1[x-1]^xor2[x+1])<<endl;
        }

    }
}
