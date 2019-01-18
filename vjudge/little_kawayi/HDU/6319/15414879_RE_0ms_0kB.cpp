#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000 + 5;
long long n, m,k,p,xx,r,mod;
long long a[MAXN];
long long indexque[MAXN];    //单调队列，事实上保存的是元素下标
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k >> p >> xx >> r >> mod;
        // n = read(), m = read(),k=read(),p=read(),xx=read(),r=read(),mod=read();
        for(int i=n; i>(n-k); i--) cin >> a[i];
        for(int i=(n-k); i>=1; i--)
        {
            a[i]=((p*a[i+1])+xx*(n-i+1)+r)%mod;
        }
        long long ans=0,count=0;
        int rear=-1, front=0;    //初始化队列为空。当rear+1 == front，队列为空；若rear==front，队列中只有一个元素。

        for (int i=1; i<=n; ++i)    //遍历输入队列，i为当前下标
        {
            if (rear+1 == front) indexque[++rear] = i;    //若队列为空，直接入队
            else
            {
                while (a[i] >= a[indexque[rear]] && rear>=front) --rear;    //若队尾元素<=当前元素且队列不为空，队尾元素出队直到...
                indexque[++rear] = i;    //当前元素入队

                if (i - indexque[front] == m) ++front;    //若队首元素已不在窗内，即当前元素的下标与队首元素的下标之差超过m，队首元素出队
            }
            if(i>=m)
            {
                count+=(rear-front+1)^((n-i+1));
                //cout<<(rear-front+1)<<" "<<(n-i+1)<<endl;
                ans+=a[indexque[front]]^(n-i+1);
            }
        }
        cout<<ans<<" "<<count<<endl;
    }

}
/*
10
10 6 1 3 4 5 10000
3
*/