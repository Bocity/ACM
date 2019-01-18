#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int y=(a+b)<<1,x=(b+c)<<1;
        x++,y++;
        char mapp[x+1][y+1];
        for(int i=0; i<=x; i++)
        {
            for(int j=0; j<=y; j++)
                mapp[i][j]='.';
        }
        bool jc1=1;
        for(int i=0; i<(c*2)+1; i++)
        {
            bool jc2=1;
            for(int j=1; j<=(a*2)+1; j++)
            {
                if(jc1)
                {
                    if(jc2)
                        mapp[x-i][0+j]='+';
                    else
                        mapp[x-i][0+j]='-';
                    jc2=!jc2;
                }
                else
                {
                    if(jc2)
                        mapp[x-i][0+j]='|';
                    else
                        mapp[x-i][0+j]='.';
                    jc2=!jc2;
                }
            }
            jc1=!jc1;
        }
        jc1=1;
        for(int i=1; i<=(a*2)+1; i++)
        {
            int posx=b*2+1;
            int posy=i;
            bool jc2=1;
            for(int j=1; j<=2*b; j++)
            {
                if(jc1)
                {
                    if(jc2)
                    {
                        mapp[posx-j][posy+j]='/';
                    }
                    else
                    {
                        mapp[posx-j][posy+j]='+';
                    }
                    jc2=!jc2;

                }
                else
                {
                    if(jc2)
                    {
                        mapp[posx-j][posy+j]='.';
                    }
                    else
                    {
                        mapp[posx-j][posy+j]='-';
                    }
                    jc2=!jc2;
                }

            }


            jc1=!jc1;
        }
        jc1=1;
        for(int i=x; i>(x-2*c); i--)
        {
            int posx=i;
            int posy=(a*2)+1;
            bool jc2=1;
            for(int j=1; j<=2*b; j++)
            {
                if(jc1)
                {
                    if(jc2)
                    {
                        mapp[posx-j][posy+j]='/';
                    }
                    else
                    {
                        mapp[posx-j][posy+j]='+';
                    }
                    jc2=!jc2;

                }
                else
                {
                    if(jc2)
                    {
                        mapp[posx-j][posy+j]='.';
                    }
                    else
                    {
                        mapp[posx-j][posy+j]='|';
                    }
                    jc2=!jc2;
                }

            }


            jc1=!jc1;
        }

        for(int i=1; i<=x; i++)
        {
            for(int j=1; j<=y; j++)
                cout<<mapp[i][j];
            cout<<endl;
        }
    }
}
