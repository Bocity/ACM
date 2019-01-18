#include <iostream>
#include <stdio.h>
#include <memory.h>
#define array ahdsfkash
using namespace std;

const int maxnum=27;
bool array[maxnum][maxnum];
int num;

void fuction()
{
    int i,j,k,l;
    for(i=1;i<=num;i++)
        for(j=1;j<=num;j++)
            for(k=1;k<=num;k++)
                for(l=1;l<=num;l++)
                    if(array[i][j]&&array[i][k]&&array[i][l]&&array[j][k]&&array[j][l]&&array[k][l])
                    {
                        printf("N\n");
                        return ;
                    }
    for(i=1;i<=num;i++)
        for(j=1;j<=num;j++)
            for(k=1;k<=num;k++)
                if(array[i][j]&& array[i][k]&&array[j][k])
                {
                    printf("Y\n");
                    return;
                }
    for(i=1;i<=num;i++)
        for(j=1;j<=num;j++)
            if(array[i][j])
            {
                printf("Y\n");
                return;
            }
    printf("Y\n");
}

int main()
{
    int i,p,x,y;
    bool flag;
    char ch,tch;
    int t = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        memset(array,false,sizeof(array));
        flag=false;
        scanf("%d",&p);
        for(int i = 0;i < p; ++i){
            scanf("%d%d",&x,&y);
            x++;
            y++;
            array[x][y] = true;
            array[y][x] = true;
        }
        fuction();
    }
    return 0;
}