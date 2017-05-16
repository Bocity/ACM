#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<time.h>
#include<conio.h >
#define MAX 2000
using namespace std;
void printR(int r[],int n,int t);//输出一维数组中的元素，每行10个
void moveR(int r[],int n);//数组复制
void Search(int r[],int n);//折半查找
void StraightInsertSort(int r[],int n);//直接插入排序
void ShellSort(int r[],int n);//希尔排序
void BubbleSort(int r[],int n);//起泡（冒泡）排序
void ModifiedBubbleSort( int r[], int n);//改进起泡排序算法
void QuickSort( int l,int r);//快速排序
void ModifiedQuickSort(int l,int r);//改进快速排序
void PerformanceAnalysis(int r[],int b[],int n);//性能分析
int PA[10][2];//记录比较次数和移动次数
int a[MAX],b[MAX],n;
char pp,ts;
void moveR(int r[],int n)
{
    for (int i=1;i<=n;i++)
    b[i]=r[i];

}
void printR(int r[],int n,int p)
{
        for(int i=1; i<=n; i++)
        if (i%10==0)printf("%5d\n",r[i]);
        else printf("%5d",r[i]);
        cout<<"比较次数:"<<PA[p][0]<<"---交换次数:"<<PA[p][1]<<"\n";
        return ;
}


void StraightInsertSort(int r[],int n)  //1
{
    int j;
    for (int i=2;i<=n;i++){
        PA[1][0]++;
        if(r[i]<r[i-1])
        {

            int temp=r[i];
            PA[1][0]++;
            for(j=i-1;j>0 && r[j]>temp;j--)
            {
                PA[1][0]++;
                r[j+1]=r[j];
                PA[1][1]++;
            }
            r[j+1]=temp;
            PA[1][1]++;
        }
    }
    printR(r,100,1);
    return ;
}
void ShellSort(int r[],int n) //2
{
    int l=n/2,j,i;
    while (l>=1)
    {
        for(i=1; i<=n; i++)
        {
            for(j=i+l; j<=n; j+=l)
            {
                // if (a[i]>a[j]) swap(a[i],a[j]);
                r[0]=r[j];
                PA[2][1]++;
                int x;

                PA[2][0]++;
                for(x=j-l; x>0&&r[x]>r[0]; x=x-l) {r[x+l]=r[x];PA[2][1]++;PA[2][0]++;}
                if (x<=0)PA[2][0]--;
                r[x+l]=r[0];
                PA[2][1]++;
            }
        }
        l=l/2;
    }
    printR(r,100,2);
    return ;
}

void BubbleSort(int r[],int n)  //3
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            PA[3][0]++;
            if (r[j]>r[j+1]) {swap(r[j+1],r[j]);PA[3][1]++;}

        }
    }
        printR(r,100,3);
    return ;
}

void ModifiedBubbleSort(int r[],int n) //4
{
    bool t=true;
    int pos=1;
    for(int i=1; i<=n&&t; i=pos)
    {
        t=false;
        for(int j=1; j<=n-i; j++)
        {
            PA[4][0]++;
            if (r[j]>r[j+1])
            {
                pos=t?pos:(j);
                swap(r[j+1],r[j]);
                PA[4][1]++;
                t=true;
            }
        }
    }
    printR(r,100,4);
    return ;
}

void QuickSort(int l,int r) //5
{
           int i=l,j=r,x=b[l];
        while(i<=j)
        {
            PA[5][0]++;
            while(b[i]<x) {i++;PA[5][0]++;}
            PA[5][0]++;
            while (x<b[j]){ j--;PA[5][0]++;}
            if (i<=j) {
                swap(b[i],b[j]);
                PA[5][1]++;
                i++;
                j--;
            }
        }
        if (l<j)
        QuickSort(l,j);
        if (i<r)
        QuickSort(i,r);
    return ;
}

void ModifiedQuickSort(int l,int r) //6
{
        int i=l,j=r,x=b[l+rand()%(r-l+1)];
        while(i<=j)
        {
            PA[6][0]++;
            while(b[i]<x) {i++;PA[6][0]++;}
            PA[6][0]++;
            while (x<b[j]){ j--;PA[6][0]++;}
            if (i<=j) {
                swap(b[i],b[j]);
                PA[6][1]++;
                i++;
                j--;
            }
        }
        if (l<j)
        ModifiedQuickSort(l,j);
        if (i<r)
        ModifiedQuickSort(i,r);


    return ;
}
void prints(char p)
{
    cout<<"排序前\n";
    for(int i=1; i<=100; i++)
        if (i%10==0)printf("%5d\n",a[i]);
        else printf("%5d",a[i]);
    cout<<"---------------常用排序算法----------------\n";
    cout<<"1.直接插入排序\n";
    cout<<"2.希尔排序\n";
    cout<<"3.起泡排序\n";
    cout<<"4.改进起泡排序\n";
    cout<<"5.快速排序\n";
    cout<<"6.改进快速排序\n";
    cout<<"7.退出\n";
    cout<<"--------------------------------------------\n";
    cout<<"请输入:\n";
}
int main()

{
    srand(time(NULL));
    for(int i=1; i<=100; i++) a[i]=rand()%1000;
    prints('\0');

    while (1)
    {
        if( kbhit() )
        {

            pp=ts;
            system("cls");
            prints(ts);
            ts=getche();
            if (ts=='\r')
            {
                memset(PA,0,sizeof(PA));
                n=pp-'0';
                switch(n)
                {
                case 1:
                     moveR(a,100);StraightInsertSort(b,100);break;
                case 2:
                     moveR(a,100);ShellSort(b,100);break;
                case 3:
                     moveR(a,100);BubbleSort(b,100);break;
                case 4:
                     moveR(a,100);ModifiedBubbleSort(b,100);break;
                case 5:
                     moveR(a,100);QuickSort(1,100);printR(b,100,5);break;
                case 6:
                     moveR(a,100);ModifiedQuickSort(1,100);printR(b,100,6);break;
                case 7:
                     return 0;
                default:
                     moveR(a,100);break;
                };

            }

        }

    }
    return 0;
}
