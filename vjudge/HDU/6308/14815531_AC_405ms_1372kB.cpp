#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    int h, m;
    char str[20];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%s", &h, &m, str);
        // int T8 = h * 60 + m;
        int len = strlen(str);
        int pos = -1, pos2 = -1;
        bool flag = 1;
        for (int i = 0; i < len; ++i) {
            if (str[i] == '+') {
                flag = 1;
                pos = i;
            }
            if (str[i] == '-') {
                flag = 0;
                pos = i;
            }
            if (str[i] == '.') {
                pos2 = i;
            }
        }
        int x, y;
        if (pos2 != -1) {
            y = str[pos2 + 1] - '0';
            if (pos2 - pos == 2) {
                x = str[pos2 - 1] - '0';
            } else {
                x = (str[pos2 - 1] - '0') + 10 * (str[pos + 1] - '0');
            }
        } else {
            pos2 = len;
            y = 0;
            if (len - 2 == pos) {
                x = str[pos2 - 1] - '0';

            } else {
                x = (str[pos2 - 1] - '0') + 10 * (str[pos2 - 2] - '0');
            }
        }
        // cout << "x==" << x << endl;
        // cout << "y==" << y << endl;

        h -= 8;
        if (flag) {
            h += x;
            m += y * 6;

        } else {
            h -= x;
            m -= y * 6;
        }
        while (m < 0) {
            m += 60;
            h--;
        }
        while (m >= 60) {
            h++;
            m -= 60;
        }
        while (h < 0) {
            h += 24;
        }
        while (h >= 24) {
            h -= 24;
        }
        if (h < 10) {
            printf("0");
        }
        printf("%d:", h);
        if (m < 10) {
            printf("0");
        }
        printf("%d\n", m);

        // printf("%02d:%02d\n", h, m);
    }
}