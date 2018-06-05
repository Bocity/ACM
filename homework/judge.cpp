#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
int n;
string s, y;

char s2[100] = {"g++ "};
string compare_diff(const char *file1, const char *file2) {
    char diff[1024];
    // cout << file1 << " " << file2;
    sprintf(diff, "diff -q -B -b -w --strip-trailing-cr %s %s", file1, file2);
    int d = system(diff);
    if (d) return "WA";
    sprintf(diff, "diff -q -B --strip-trailing-cr %s %s", file1, file2);
    int p = system(diff);
    if (p)
        return "PE";
    else
        return "AC";
}
int main() {
    cout << "输入1选择源文件，输入2选择可执行文件，其他退出程序\n";
    cin >> y;
    char s3[100] = {"cat ./test0.in | ./a.out > dif.out "};
    if (y == "1") {
        cout << "输入带评测程序源文件名：";
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            s2[4 + i] = s[i];
        }
        system(s2);
        sleep(2);
        cout << s2;
        string f = "test0.out";
        string ans[11] = {};
        for (int i = 0; i <= 9; i++) {
            f[4] = '0' + i;
            char p[100];
            string ss;
            s3[10] = '0' + i;
            system(s3);
            string fi = "dif.out";
            ans[i] = compare_diff(fi.c_str(), f.c_str());
            // cout << "Test" << i << ":" << compare_diff(fi.c_str(), f.c_str()) << "\n";
        }
        //    system("clear");
        int sum = 0;
        for (int i = 0; i <= 9; i++) {
            cout << "Test" << i << ":" << ans[i] << "  ";
            if (ans[i] == "AC") {
                cout << "10\n";
                sum += 10;
            }
            if (ans[i] == "PE") {
                cout << "5\n";
                sum += 5;
            }
            if (ans[i] == "WA") {
                cout << "0\n";
                sum += 0;
            }
        }
        cout << "总分：" << sum;
        cin >> sum;

    } else if (y == "2") {
        string a = "./test0.in";
        string f = "test0.out";
        string b = "cat ";
        string c = " | ./";
        string d;
        string e = " > dif.out";
        cout << "输入可执行文件名：";
        cin >> d;
        string ans[11] = {};
        for (int i = 0; i <= 9; i++) {
            char p[100];
            string ss;
            a[6] = '0' + i;
            f[4] = '0' + i;

            ss = b + a + c + d + e;
            for (int ii = 0; ii < ss.size(); ii++) p[ii] = ss[ii];
            system(p);
            string fi = "dif.out";
            ans[i] = compare_diff(fi.c_str(), f.c_str());
            // cout << "Test" << i << ":" << compare_diff(fi.c_str(), f.c_str()) << "\n";
        }
        system("clear");
        int sum = 0;
        for (int i = 0; i <= 9; i++) {
            cout << "Test" << i << ":" << ans[i] << "  ";
            if (ans[i] == "AC") {
                cout << "10\n";
                sum += 10;
            }
            if (ans[i] == "PE") {
                cout << "5\n";
                sum += 5;
            }
            if (ans[i] == "WA") {
                cout << "0\n";
                sum += 0;
            }
        }
        cout << "总分：" << sum;
        cin >> sum;

    } else
        return 0;

    return 0;
}
