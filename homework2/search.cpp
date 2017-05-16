#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int sum = 0, sum2 = 0;
struct ips {
    string ip;
    vector<string> time;
    vector<string> action;
    vector<string> what;
} stu[1000];
struct num {
    string num;
    vector<string> ip;
    vector<string> time;
    vector<string> action;
    vector<string> what;
} stt[1000];
string searchs(string x) {
    int y;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '/') {
            bool flag = false;
            for (int k = i + 1; k < i + 11; k++) {
                if ((k) >= x.size()) {
                    flag = true;
                    break;
                }
                if (x[k] < '0' || x[k] > '9') {
                    flag = true;
                    break;
                }
            }
            if (!flag) return x.substr(i + 1, 10);
        } else if (x[i] == '1') {
            bool flag = false;
            for (int k = i; k < i + 10; k++) {
                if ((k) >= x.size()) {
                    flag = true;
                    break;
                }
                if (x[k] < '0' || x[k] > '9') {
                    flag = true;
                    break;
                }
            }
            if (!flag) return x.substr(i, 10);
        }
    }
    return "non";
}
string s, time1, ip, action, what, other1, other2;
map<string, int> cha;
map<string, int> cha2;
int main() {
    // ios::sync_with_stdio(false);
    freopen("ex160302.log", "r", stdin);
    freopen("ipresult.out", "w", stdout);

    int k, k2;
    while (getline(cin, s))
        if (s[0] >= '0' && s[0] <= '9') {
            stringstream mystream(s);
            mystream >> time1 >> ip >> action >> what >> other1 >> other2;
            string numm = searchs(what);
            if (what.find(".") != string::npos || numm != "non") {
                k = cha[ip];
                k2 = cha2[numm];
                if (k == 0) {
                    sum++;
                    k = sum;
                }
                if (k2 == 0) {
                    sum2++;
                    k2 = sum2;
                }
                cha[ip] = k;
                stu[k].ip = ip;
                stu[k].time.push_back(time1);
                stu[k].action.push_back(action);
                stu[k].what.push_back(what);
                cha2[numm] = k2;
                stt[k2].num = numm;
                vector<string>::iterator result = find(stt[k2].ip.begin(), stt[k2].ip.end(), ip);
                if (result == stt[k2].ip.end()) {
                    stt[k2].ip.push_back(ip);
                }
                stt[k2].time.push_back(time1);
                stt[k2].action.push_back(action);
                stt[k2].what.push_back(what);
            }
        }
    for (int i = 1; i <= sum; i++) {
        cout << stu[i].ip << endl;
        int count = stu[i].time.size();
        for (int j = 0; j < count; j++) {
            cout << stu[i].time[j] << " ";
            int ppos = stu[i].action[j].find("]");
            for (int k = ppos + 1; k < stu[i].action[j].size(); k++) cout << stu[i].action[j][k];
            cout << " " << stu[i].what[j] << endl;
        }
        cout << "\n";
    }
    freopen("numresult.out", "w", stdout);
    for (int i = 1; i <= sum2; i++) {
        if (stt[i].num == "non") cout << "未检测到学号信息" << endl;
        cout << stt[i].num << endl;
        cout << "ip:";
        int count = stt[i].ip.size();
        for (int j = 0; j < count; j++) {
            cout << stt[i].ip[j] << "    ";
        }
        cout << endl;
        count = stt[i].time.size();
        for (int j = 0; j < count; j++) {
            cout << stt[i].time[j] << " ";
            int ppos = stt[i].action[j].find("]");
            for (int k = ppos + 1; k < stt[i].action[j].size(); k++) cout << stt[i].action[j][k];
            cout << " " << stt[i].what[j] << endl;
        }
        cout << "\n";
    }
    return 0;
}