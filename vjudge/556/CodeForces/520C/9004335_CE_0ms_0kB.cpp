#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef double ll;
int m = 20;
ll D[10000] = {0,    3.3,  3.7,  4.2,  5.0,  5.6,  6.1,  7.2,  8.3,  9.5, 10.2,
               11.6, 13.2, 14.0, 14.3, 15.4, 16.3, 17.4, 18.1, 18.8, 19.3
              }; //坐标数组
ll T[105][400][400] = {0};                                                  //时间数组
ll G[1000] = {0};                                                           //下车数组
ll P[1000] = {0};                                                           //上车数组
ll dTr[1000] = {0, 9, 6, 3.5, 5, 3.5, 6};                                   // dtr数组
int o[100] = {0, 30, 60, 120, 480, 120, 255};                               //时段时长数组
ll V[1000] = {0}, Z;                                                        //速度数组和载客量
ll s[1000] = {0}, s1[1000] = {0};                                           //站台人数数组和储存数组
ll v[1000] = {0};                                                           //判定数组
ll ans = 0;
int Q[10] = {0, 4, 9, 35, 96, 34, 43}; // k时段总车辆数数组
ll lan[100]
[100] = {{0.2, 0.1, 0.1, 0.2, 0.3, 0.3, 0.3, 0.4, 0.3, 0.3, 0.4, 0.3, 0.3, 0.4, 0.2, 0.1, 0.2, 0.2, 0.1, 0.1, 0}, {0.2, 0.1, 0.1, 0.4, 0.5, 0.5, 0.3, 0.4, 0.5, 0.7, 0.5, 0.5, 0.4, 0.3, 0.4, 0.4, 0.4, 0.3, 0.3, 0.1, 0}, {2, 0.8, 1.2, 1.3, 2.1, 1.7, 2.1, 2.0, 2.3, 2.3, 1.9, 2.2, 2.4, 2.5, 2, 1.6, 1.7, 1.4, 1.0, 0.7, 0}, {1.2, 1.0, 1.0, 1.2, 1.4, 1.6, 1.7, 1.8, 1.6, 2.0, 1.9, 1.6, 1.9, 1.3, 1.8, 1.3, 1.6, 1.2, 0.9, 0.6, 0}, {1.7, 1.1, 1.6, 1.6, 1.7, 2.4, 2.1, 1.9, 2.4, 2.0, 2.3, 2.1, 2.0, 1.9, 2.1, 2.1, 1.7, 1.1, 1.1, 0.8, 0}, {1.3, 0.6, 0.8, 1.0, 1.1, 1.2, 1.4, 1.5, 2.0, 2.0, 1.9, 2.0, 1.8, 1.7, 1.4, 1.8, 1.2, 1.1, 1.1, 0.7, 0}};
ll beta[500] = {0};
bool vis[10000] = {0};
struct bus1
{
    double start, end;
} bus[500];
struct bus2
{
    double start, end, time;
    bool z, w;
    int num;
    bus1 bus[500];
};
bool cmp(bus1 x, bus1 y)
{
    return (x.start == y.start) ? x.end < y.end : x.start < y.start;
}
const double e = exp(1);
long long f(long long x)
{
    return x ? x * f(x - 1) : 1;
}
void B()
{
    long double sum[21] = {0};
    long double P1[21][21] = {0};
    for (int i = 0; i < 20; i++)
        for (int j = i + 1; j <= 20; j++)
            P1[i][j] = pow(e, -(20 - i) * 1.0 / 2) * pow((20 - i) * 1.0 / 2, j - i) / f(j - i);
    for (int i = 0; i <= 20; i++)
    {
        long double G1 = 0, Q1 = 0;
        for (int j = 0; j < i; j++) G1 += P1[j][i];
        for (int j = 0; j < i; j++)
            for (int k = i; k <= 20; k++) Q1 += P1[j][k];
        beta[i] = G1 / Q1;
    }
    beta[0] = 0;
    V[3] = V[4] = V[5] = D[20] / 75;
    V[1] = V[2] = V[6] = D[20] / 70;
    T[0][0][0] = 0;
    return;
}
long long fa[10000] = {0};
long long cha(long long x)
{
    return (x == fa[x]) ? x : fa[x] = cha(fa[x]);
}
void Union(long long x, long long y)
{
    long long father1 = cha(x);
    long long father2 = cha(y);
    if (father1 == father2)
        return;
    else
        fa[father1] = father2;
}
void init()
{
    for (int i = 1; i <= 10000; i++) fa[i] = i;
}
void out(double x)
{
    x = x + 270;
    printf("%02d:%02d:", (int) floor(x) / 60, (int) floor(x) % 60);
    if (x - floor(x) == 0.5)
    {
        cout << "30";
    }
    else
    {
        cout << "00";
    }
    cout << "    ";
    return;
}
bus2 buss[500];  //双班车
bus2 buss2[500]; //单班车
int main()
{
    B();
    Z=80;
    long long num = 0;

    for (int k = 1; k <= 7; k++)
    {
        T[k][1][0] = T[k - 1][Q[k - 1]][0] + dTr[k - 1];

        for (int i = 1; i <= m; i++) T[k][0][i] = T[k - 1][Q[k - 1]][0];

        memset(v, 0, sizeof(v));

        for (int r = 2; r <= 300; r++) T[k][r][0] = T[k][r - 1][0] + dTr[k];
        for (int r = 1; r <= 300; r++)
        {
            for (int i = 1; i <= m; i++)
            {
                T[k][r][i] = T[k][r][i - 1] + (D[i] - D[i - 1]) / V[k];
            }
        }
        if (k == 7)
            for (int k1 = 1; k1 <= 6; k1++)
            {
                for (int r1 = 1; r1 <= Q[k1]; r1++)
                {
                    num++;
                    bus[num].start = T[k1][r1][0];
                    bus[num].end = T[k1][r1][m];
                    //                   out(T[k1][r1][0]);
                    //                   out(T[k1][r1][m]);

                    // cout << "\n";
                }
                //    cout << "\n";
            }
    }
    bool vis1[10000] = {0};
    long double T = 0;

    long long ans = 0;  //双班车数量
    long long ans2 = 0; //单班车数量
    bool flag;
    while (T <= 1065)
    {
        for (int i = 1; i <= num; i++)           //枚举所有班次
        {
            if (bus[i].start <= T && !vis1[i])   //可发车
            {
                vis1[i] = true;
                flag = false; //双班车中是否有可发车的
                if(360-270<=T&&T<=480-270)
                {

                        bool flag2 = false;
                        for (int k = 1; k <= ans2; k++)
                        {
                            if (buss2[k].start <= bus[i].start && buss2[k].num < 5)
                            {
                                flag2 = true;
                                buss2[k].num++;
                                buss2[k].bus[buss2[k].num].start = bus[i].start;
                                buss2[k].bus[buss2[k].num].end = bus[i].end;
                                buss2[k].start = bus[i].end + 10;
                                break;
                            }
                        }
                        if (!flag2&&ans2<7)
                        {
                            ans2++;
                            buss2[ans2].num++;
                            buss2[ans2].bus[buss2[ans2].num].start = bus[i].start;
                            buss2[ans2].bus[buss2[ans2].num].end = bus[i].end;
                            buss2[ans2].start = bus[i].end + 10;
                            flag2=true;

                        }
                        if (flag2)
                        continue;

                }

