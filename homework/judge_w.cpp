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
void find_next_nonspace(int &c1, int &c2, FILE *&f1, FILE *&f2, string &ret) {
    // Find the next non-space character or \n.
    while ((isspace(c1)) || (isspace(c2))) {
        if (c1 != c2) {
            if (c2 == EOF) {
                do {
                    c1 = fgetc(f1);
                } while (isspace(c1));
                continue;
            } else if (c1 == EOF) {
                do {
                    c2 = fgetc(f2);
                } while (isspace(c2));
                continue;
            } else if ((c1 == '\r' && c2 == '\n')) { //解决 换行问题
                c1 = fgetc(f1);
            } else if ((c2 == '\r' && c1 == '\n')) {
                c2 = fgetc(f2);
            } else { //换行和格式不一样
                ret = "PE";
            }
        }
        if (isspace(c1)) { //对齐
            c1 = fgetc(f1);
        }
        if (isspace(c2)) {
            c2 = fgetc(f2);
        }
    }
}
string compare_zoj(const char *file1, const char *file2) {
    string ret = "AC";
    int c1, c2;
    FILE *f1, *f2;
    f1 = fopen(file1, "r");
    f2 = fopen(file2, "r");
    if (!f1 || !f2) {
        ret = "RE";
    } else
        for (;;) {
            // Find the first non-space character at the beginning of line.
            // Blank lines are skipped.
            c1 = fgetc(f1);
            c2 = fgetc(f2);
            find_next_nonspace(c1, c2, f1, f2, ret);
            // Compare the current line.
            for (;;) {
                // Read until 2 files return a space or 0 together.
                while ((!isspace(c1) && c1) || (!isspace(c2) && c2)) {
                    if (c1 == EOF && c2 == EOF) {
                        goto end;
                    }
                    if (c1 == EOF || c2 == EOF) {
                        break;
                    }
                    if (c1 != c2) {
                        // Consecutive non-space characters should be all exactly the same
                        ret = "WA";
                        goto end;
                    }
                    c1 = fgetc(f1);
                    c2 = fgetc(f2);
                }
                find_next_nonspace(c1, c2, f1, f2, ret);
                if (c1 == EOF && c2 == EOF) {
                    goto end;
                }
                if (c1 == EOF || c2 == EOF) {
                    ret = "WA";
                    goto end;
                }

                if ((c1 == '\n' || !c1) && (c2 == '\n' || !c2)) {
                    break;
                }
            }
        }
end:
    if (f1) fclose(f1);
    if (f2) fclose(f2);
    return ret;
}
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
    char s3[100] = {"more test0.in | a.exe > dif.out "};
    if (y == "1") {
        cout << "输入带评测程序源文件名：";
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            s2[4 + i] = s[i];
        }
        system(s2);
        sleep(2);
        string f = "test0.out";
        string ans[11] = {};
        for (int i = 0; i <= 9; i++) {
            f[4] = '0' + i;
            char p[100];
            string ss;
            s3[9] = '0' + i;
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
        string a = "test0.in";
        string f = "test0.out";
        string b = "more ";
        string c = " | ";
        string d;
        string e = " > dif.out";
        cout << "输入可执行文件名：";
        cin >> d;
        string ans[11] = {};
        for (int i = 0; i <= 9; i++) {
            char p[100];
            string ss;
            a[4] = '0' + i;
            f[4] = '0' + i;

            ss = b + a + c + d + e;
            for (int ii = 0; ii < ss.size(); ii++) p[ii] = ss[ii];
            system(p);
            string fi = "dif.out";
            ans[i] = compare_diff(fi.c_str(), f.c_str());
            // cout << "Test" << i << ":" << compare_diff(fi.c_str(), f.c_str()) << "\n";
        }
        system("cls");
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
