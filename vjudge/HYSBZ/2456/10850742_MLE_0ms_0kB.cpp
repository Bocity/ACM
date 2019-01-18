#include <bits/stdc++.h>
using namespace std;
long a, b;
int x = 0;
int n;
int main() {
    scanf("%d", &n);
    scanf("%ld", &a);
    b = a;
    x = 1;
    n--;
    while (n--) {
        scanf("%ld", &a);
        if (a != b) {
            x--;
            if (x == 0) {
                scanf("%ld", &b);
                x++;
                n--;
            } else {
                x--;
            }
        } else {
            x++;
        }
    }
    printf("%ld\n", b);
    return 0;
}