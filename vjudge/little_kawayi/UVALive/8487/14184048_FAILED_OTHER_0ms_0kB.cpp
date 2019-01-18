#include<bits/stdc++.h>
using namespace std;
int fx[4][2]= {0,1,1,0,0,-1,-1,0};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n][n];
        memset(a,0,sizeof a);
        a[0][0]=1;
        int x=0,y=0;
        int fxx=0;
        int jc=3;
        while(jc!=0)
        {


            int nowx=x+fx[fxx][0];
            int nowy=y+fx[fxx][1];
            int nextx=x+2*fx[fxx][0];
            int nexty=y+2*fx[fxx][1];

            int nextx1=nowx+fx[(fxx+1)%4][0];
            int nexty1=nowy+fx[(fxx+1)%4][1];
            int nextx2=nowx+fx[(fxx+3)%4][0];
            int nexty2=nowy+fx[(fxx+3)%4][1];
            if(nowx>=0&&nowx<n&&nowy>=0&&nowy<n&&
               (nextx<0||nextx>=n||nexty<0||nexty>=n||(nextx>=0&&nextx<n&&nexty>=0&&nexty<n&&a[nextx][nexty]==0))&&
                              (nextx1<0||nextx1>=n||nexty1<0||nexty1>=n||(nextx1>=0&&nextx1<n&&nexty1>=0&&nexty1<n&&a[nextx1][nexty1]==0))&&

                                             (nextx2<0||nextx2>=n||nexty2<0||nexty2>=n||(nextx2>=0&&nextx2<n&&nexty2>=0&&nexty2<n&&a[nextx2][nexty2]==0))


               )
            {
                //cout<<nowx<<" "<<nowy<<" "<<a[nowx][nowy]<<endl;
                x=nowx;
                y=nowy;
                jc=3;
            }
            else
            {
                fxx++;
                fxx%=4;
                jc--;
            }
            a[x][y]=1;
        }
        for(int i=0; i<n; i++)
        {

            for(int j=0; j<n; j++)
            {
                if(a[i][j]==1)
                    cout<<"#";
                else
                    cout<<" ";
            }
            cout<<endl;
        }

    }
}
