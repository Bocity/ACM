#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<time.h>
#include<conio.h >
#include<queue>
#define MAX 2000
using namespace std;
int a[200000],b[200000],c[200000],son1[200000],son2[200000],fa[200000],l,n,m,root;
void printR(int r[],int n)
{
        for(int i=1; i<=n; i++)
        if (i%10==0)printf("%5d\n",r[i]);
        else printf("%5d",r[i]);
        return ;
}
void HeapAdjust(int r[],int i,int n)
{
    int l=2*i;
    int rr=2*i+1;
    int maxx=i;
    if(i<=n/2)
    {
        if(l<=n&&r[l]>r[maxx])
        {
            maxx=l;
        }
        if(rr<=n&&r[rr]>r[maxx])
        {
            maxx=rr;
        }
        if(maxx!=i)
        {
            swap(r[i],r[maxx]);
            HeapAdjust(r,maxx,n);
        }
    }
}

void SETHeap(int r[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        HeapAdjust(r,i,n);
    }
}

void HeapSort(int r[],int n)
{
    int i;
    SETHeap(r,n);
    for(i=n;i>=1;i--)
    {
        swap(r[1],r[i]);
        HeapAdjust(r,1,i-1);
    }
    printR(r,n);


}
void Insert(int x,int i)
{
    if (b[i]==0) {b[i]=x;return;}
    if (b[i]>x) Insert(x,i*2);
    if (b[i]<x) Insert(x,i*2+1);
    return;
}


void SelectSort(int r[],int n)
{
    for (int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
        if (r[i]<r[j]) swap(r[i],r[j]);
    printR(r,n);
    return ;
}
void moveR(int r[],int n)
{
    for (int i=1;i<=n;i++)
    b[i]=r[i];
    return ;

}
void DLR(int x)
{
    if (b[x]==0) return;
    cout<<b[x]<<" ";
    DLR(x*2);
    DLR(x*2+1);
    return ;
    }
void LDR(int x)
{
    if (b[x]==0) return;
    LDR(x*2);
    cout<<b[x]<<" ";
    LDR(x*2+1);
    return ;
    }
void LRD(int x)
{
    if (b[x]==0) return;
    LRD(x*2);
    LRD(x*2+1);
    cout<<b[x]<<" ";
    return ;
    }
void bfs(int x)
    {
        int m;
        queue<int> q;
        q.push(x);
        while (!q.empty())
        {
            m=q.front();
            q.pop();
            if (b[m]==0) continue;
            cout<<b[m]<<" ";
            q.push(m*2);
            q.push(m*2+1);

        }
    }
    void bfs2(int x)
    {
        int m;
        queue<int> q;
        q.push(x);
        while (!q.empty())
        {
            m=q.front();;
            q.pop();
            if (c[m]==0) continue;
            cout<<c[m]<<" ";
            q.push(son1[m]);
            q.push(son2[m]);

        }
    }
void tree()
{
    int n,x;
    cin>>n;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        Insert(x,1);
    }
    cout<<"ÏÈÐò";
    DLR(1);
    cout<<"\n"<<"ÖÐÐò";
    LDR(1);
    cout<<"\n"<<"ºóÐò";
    LRD(1);
    cout<<"\n"<<"²ã´Î";
    bfs(1);
    cout<<"\n";

return ;
}
int mini(int x)
{
    int minii=999999;
    int k=1;
    for(int i=1;i<n+x;i++)
    {
        if (minii>c[i]&&fa[i]==0)
        {
            minii=c[i];
            k=i;
        }
    }
    return k;
}
void Huffmantree()
{
    int x,y;
    cin>>n;
    memset(fa,0,sizeof(fa));
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
            x=mini(i);
            fa[x]=n+i;
            son1[n+i]=x;
            y=mini(i);
            fa[y]=n+i;
            son2[n+i]=y;
            c[n+i]=c[x]+c[y];
    }
    for(int i=1;i<=2*n;i++)
    {
        if (fa[i]==0) root=x;
    }
    bfs2(root);

}
void prints(char p)
{
    cout<<"ÅÅÐòÇ°\n";
    for(int i=1; i<=100; i++)
        if (i%10==0)printf("%5d\n",a[i]);
        else printf("%5d",a[i]);
    cout<<"--------------------------------------------\n";
    cout<<"1.Ñ¡ÔñÅÅÐò\n";
    cout<<"2.¶þ²æÅÅÐòÊ÷\n";
    cout<<"3.¹þ·òÂüÊ÷\n";
    cout<<"4.¶ÑÅÅÐò\n";
    cout<<"5.ÍË³ö\n";
    cout<<"--------------------------------------------\n";
    cout<<"ÇëÊäÈë:\n";
}
int main()

{
    srand(time(NULL));
    for(int i=1; i<=100; i++) a[i]=rand()%1000;
    prints('\0');
    char pp,ts;
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
                memset(c,0,sizeof(c));
                n=pp-'0';
                switch(n)
                {
                case 1:
                     moveR(a,100);SelectSort(b,100);return 0;
                case 2:
                     tree();return 0;
                case 3:
                     Huffmantree();return 0;
                case 4:
                     moveR(a,100);HeapSort(b,100);return 0;
                case 5:
                     return 0;
                default:
                     return 0;
                };

            }

        }

    }
    return 0;
}
