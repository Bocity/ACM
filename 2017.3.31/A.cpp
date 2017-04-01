#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
// int a[] = {4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086, 1111, 1165};
int a[10000] = {0};
int main()
{
    int b, x;
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= a[i]; j++)
            if (a[i])
                cout << i << " ";
    return 0;
}