#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    char mp[3][3];
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 3; i++) scanf("%s", mp[i]);
        char c;
        for(int i = 0; i < 3; i++) {
            if(mp[i][0] == mp[i][1] && mp[i][1] == mp[i][2]) c = mp[i][0];
        }
        for(int i = 0; i < 3; i++) {
            if(mp[0][i] == mp[1][i] && mp[1][i] == mp[2][i]) c = mp[0][i];
        }
        if(mp[0][0] == mp[1][1] && mp[1][1] == mp[2][2]) c = mp[0][0];
        if(mp[0][2] == mp[1][1] && mp[1][1] == mp[2][0]) c = mp[1][1];
        if(c == '.') printf("ongoing\n");
        else printf("%c\n", c);
    }
}