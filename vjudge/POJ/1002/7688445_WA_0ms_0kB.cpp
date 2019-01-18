    #include <iostream>
    #include<algorithm>
    #include<string>
    #include<cstring>
    using namespace std;
    long long n;
    struct sp{
        string a;
        int b;
    };
    sp ss[100001];
    int sum;

    bool cmp(sp x,sp y)
    {
        return x.a<y.a;
    }
    int main()
    {
        bool zz=false;
        cin>>n;
        sum=1;
        for(int j=1;j<=n;j++)
        {

            bool t=false;
            string s;
            cin>>s;
            char x;
            string p;
            for (int i=0;i<=s.length()-1;i++)
            {
                if (s[i]<'0'||s[i]>'9')
                {
                    if (s[i]>='A'&&s[i]<'Q')
                    {
                        x=('0'+(s[i]-'A')/3+2);
                        p+=x;
                        continue;
                    }
                    if (s[i]=='R'||s[i]=='S')
                    {
                        p+='7';
                        continue;
                    }
                    if (s[i]>'S'&&s[i]<='Y')
                    {
                        x=('0'+(s[i]-'T')/3+8);
                        p+=x;
                        continue;
                    }
                    else continue;
                }
                else
                {
                 p+=s[i];
                }

            }
                for (int ii=1;ii<=n;ii++)
                {
                    if (ss[ii].a==p) {ss[ii].b++;t=true;if (ss[ii].b>=2)zz=true;break; }

                }
                if (!t) {ss[sum].a=p;t=false;ss[sum].b=1;sum++; }

        }
        if (zz)
        {
        sort(ss,ss+n,cmp);
        for (int i=1;i<=n;i++)

            {
                if (ss[i].b>=2)
                {
                    for (int pp=0;pp<=ss[i].a.length();pp++)
                    {
                        if (pp==2) {cout<<ss[i].a[2]<<"-";continue;}
                        cout<<ss[i].a[pp];
                    }
                    cout<<" "<<ss[i].b<<"\n";
                }
               // cout<<a[i]<<" "<<aa[i]<<"\n";
            }
        }
        else
        {
            cout<<"no duplicates.";
        }
        return 0;
    }
