#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y||x==0||y==0)
        {
            a++;
        }else
        {
            if((x%2==0&&y==(x-1))||(x%2==1&&y==(x+1)))
            {
                b++;
            }else
                c++;
        }
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(a!=0)
        cout<<"Y"<<endl;
    else
    {
        if(c==0||c%2==1)
            cout<<"N"<<endl;
        else
            cout<<"Y"<<endl;
    }

}
