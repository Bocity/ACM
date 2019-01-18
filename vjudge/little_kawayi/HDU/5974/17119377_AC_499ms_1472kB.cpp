#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool check(long long a,long long b,int lcm)
{
    int det=a*a-4*b;
    if(det<0)
    {
        return 0;
    }else
    {
        if((int)sqrt(det)*(int)sqrt(det)!=det)
            return 0;
        else
        if((a-(int)sqrt(det))%2!=0)
        {
            return 0;
        }else
        {
            int x=(a-(int)sqrt(det))/2;
            int y=a-x;
            if(y>=0&&__gcd(x,y)*lcm==b)
                cout<<x<<" "<<y<<endl;
            else
                return 0;

        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    long long a,b;
    while(cin>>a>>b)
    {
        vector<long long > pos;
        for(long long  i=1;i<=sqrt(a);i++)
        {
            if(a%i==0)
            {
                if(a==i*i)
                    pos.push_back(i);
                else
                {
                    pos.push_back(i);
                    pos.push_back(a/i);
                }
            }
        }
        bool jc=0;
        for(auto e:pos)
        {
            if(check(a,e*b,b))
            {
                jc=1;
                break;
            }
        }
        if(!jc)
            cout<<"No Solution"<<endl;

    }
}
