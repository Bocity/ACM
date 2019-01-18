#include<bits/stdc++.h>
using namespace std;
char s[10005],p[10005];
int main()
{
    scanf("%s",s);
    scanf("%s",p);
    int ls=strlen(s),lp=strlen(p),f,ans=0;
    ls-=lp;
    for(int i=0;i<=ls;++i)
    {
        f=1;
        for(int j=0;j<lp;++j)
        {
            if(s[i+j]==p[j])
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}