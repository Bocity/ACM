#include "function.cpp"
using namespace std;
int main() {
    //ios::sync_with_stdio(false);
    clear();
    read();
    out();
    while (cin >> s) {
        clear();
        out();
        int flag = cha(s);
        if (flag == 8) {
            cout << "����Ƿ�������������\n";
            continue;
        }
        cases(flag);
        switch (flag) {
            case 0: {
                clear();
                cout << "�ټ���";
                save();
                return 0;
                break;
            }
            case 1: {
                case1();
                clear();
                out();
                break;
            }
            case 2: {
                case2();
                clear();
                out();
                break;
            }
            case 3: {
                case3();
                clear();
                out();
                break;
            }
            case 4: {
                case4();
                clear();
                out();
                break;
            }
            case 5: {
                case5();
                clear();
                out();
                break;
            }
            case 6: {
                case6();
                clear();
                out();
                break;
            }
            case 7: {
                case7();
                clear();
                out();
                break;
            }
            default: { break; }
        }
    }
}
