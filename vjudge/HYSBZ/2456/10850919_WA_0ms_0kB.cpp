#include <cstdio>
using namespace std;
long long a, b;
int x = 0;
int n;
int main() {
    scanf("%d", &n);
    scanf("%lld", &a);
    b = a;
    x = 1;
    --n;
    while (n != 0) {
        scanf("%lld", &a);
        if (a != b) {
            --x;
            if (x == 0) {
                scanf("%lld", &b);
                ++x;
                --n;
            } else {
                --x;
            }
        } else {
            ++x;
        }
        --n;
    }
    printf("%lld\n", b);
    return 0;
}