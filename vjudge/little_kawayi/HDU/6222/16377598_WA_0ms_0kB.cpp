//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//
//     for(int i=4;i<=100000000;i+=2)
//     {
//         double t1,t2,t3;
//         t1=i-1,t2=i,t3=i+1;
//         double p=3*t2/2.0;
//         double eps=1e-10;
//         double area=sqrt((p-t1)*(p-t2)*(p-t3)*p);
//         //cout<<fixed<<setprecision(20)<<area<<endl;
//         if(area-int(area)<eps)
//            cout<<i<<" "<<area<<endl;
//     }
//}
#include<bits/stdc++.h>
using namespace std;
int pow1(int x,int n)
{
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans*=x;
    }
    return ans;
}
int main()
{

    int a[100]= {0,4,14,52
                 ,194
                 ,724
                 ,2702
                 ,10084
                 ,37634,-1};
    int t;
    cin>>t;
    while(t--)
    {
        string c;
        cin>>c;
        string now;
        if(c.size()>7)
        {
            int sz=c.size();
            now=c.substr(sz-7,7);
        }else
        {
            now=c;
        }
        int pos=0;
        for(int i=0;i<now.size();i++)
        {
            pos+=(now[i]-'0')*pow1(10,now.size()-i-1);
        }
        for(int i=8;i>=0;i--)
        {
            if(pos>a[i])
            {
                cout<<a[i+1]<<endl;
                break;
            }
        }
    }
    return 0;

}
