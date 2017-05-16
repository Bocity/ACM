#include "head.h"
using namespace std;
void clear() {
    system("cls");
    return;
}
bool cmp1(Student x, Student y) {
    return x.getId() < y.getId();
}
bool cmp2(Student x, Student y) {
    return x.getName() < y.getName();
}
bool cmp3(Student x, Student y) {
    return x.getRegularGrade() > y.getRegularGrade();
}
bool cmp4(Student x, Student y) {
    return x.getFinalExam() > y.getFinalExam();
}
bool cmp5(Student x, Student y) {
    return x.CalTotalMark() > y.CalTotalMark();
}
void out() {
    cout << "======================================\n";
    cout << "=       ��ӭʹ��ѧ���ɼ�����ϵͳ     =\n";
    cout << "=     1.¼��ѧ��       2.��ʾ��Ϣ    =\n";
    cout << "=     3.��������       4.����ѧ��    =\n";
    cout << "=     5.����ѧ��       6.ɾ��ѧ��    =\n";
    cout << "=     7.ͳ������       0.�˳�       =\n";
    cout << "======================================\n";
    return;
}
void cases(int x) {
    clear();
    cout << "======================================\n";
    cout << "        ������" << ss[x] << "ģʽ      \n";
    cout << "======================================\n";
}
int cha(string s) {
    string t[100] = {"1", "2", "3", "4", "5", "6", "7", "0"};
    for (int i = 0; i < 8; i++) {
        if (s == t[i]) return s[0] - '0';
    }
    return 8;
}

double Student::CalTotalMark() {
    return (this->regularGrade + this->finalExam) / 2;
}
void Student::output() const {
    cout <<left<< setw(10) << this->id <<setw(14) << this->name  << setw(10) << this->regularGrade << setw(10) << this->finalExam << endl;
}
void Student::heading() {
    cout  <<left<< setw(10) << "Id"  << setw(14) << "Name" << setw(10) << "Regular"  << setw(10) << "Final" << endl;
}
void Student::inputId() {
    while (1){
    cout << "������ѧ��:";
    ll x;
    cin>>x;
    bool fll=false;
    for(int i=1;i<=sum;i++)
    if (x==student[i].getId()){ cout<<"ѧ���ظ�����\n";fll=true;}
        if (!fll){
        this->id=x;
        break;
        }
    }
}
void Student::inputName() {
    cout << "����������:";
    cin >> this->name;
}
void Student::inputRegularGrade() {
    while (1) {
        cout << "������ƽʱ�ɼ�:";
        double x;
        cin >> x;
        if (x >= 0 && x <= 100) {
            this->regularGrade = x;
            break;
        } else {
            cout << "��������,���顣\n";
        }
    }
}

void Student::inputFinalExam() {
    while (1) {
        cout << "��������ĩ�ɼ�:";
        double x;
        cin >> x;
        if (x >= 0 && x <= 100) {
            this->finalExam = x;
            break;
        } else {
            cout << "��������,���顣\n";
        }
    }
}
void save() {
    freopen("data.dat", "w", stdout);
    cout << sum << "\n";
    for (int i = 1; i <= sum; i++) {
        cout << student[i].getId() << " " << student[i].getName() << " " << student[i].getRegularGrade() << " "
             << student[i].getFinalExam() << "\n";
    }
    fclose(stdout);
}
void read() {
    ifstream in( "data.dat",ios::in); 
    ll x;
    string y;
    double m, n;
    in >> sum;
    for (int i = 1; i <= sum; i++) {
        in >> x >> y >> m >> n;
        student[i].reId(x);
        student[i].reName(y);
        student[i].reRegularGrade(m);
        student[i].reFinalExam(n);
    }
    in.close();
}

void case1() {
    cases(1);
    bool fl = true;
    string yy;
    while (fl) {
        sum++;
        student[sum].inputId();
        student[sum].inputName();
        student[sum].inputRegularGrade();
        student[sum].inputFinalExam();
        cout << "\n����1����,��������������:";
        cin >> yy;
        if (yy != "1") fl = false;
    }
    return;
}
void case2() {
    cases(2);
    string yy;
    student[0].heading();
    for (int i = 1; i <= sum; i++) {
        student[i].output();
    }
    cout << "\n�����������������:";
    cin >> yy;
    return;
}
void case3() {
    while (1) {
        string kk;
        cases(3);
        string yy;
        cout << "======================================\n";
        cout << "     1.��ѧ��   2.������   3.��ƽʱ        \n ";
        cout << "     4.����ĩ   5.������   ����.����       \n";
        cout << "======================================\n";
        cin >> yy;
        if (yy == "1") {
            sort(student + 1, student + 1 + sum, cmp1);
        }
        else if (yy == "2") {
            sort(student + 1, student + 1 + sum, cmp2);
        }
        else if (yy == "3") {
            sort(student + 1, student + 1 + sum, cmp3);
        }
        else if (yy == "4") {
            sort(student + 1, student + 1 + sum, cmp4);
        }
        else if (yy == "5") {
            sort(student + 1, student + 1 + sum, cmp5);
        }
        else break;
        student[0].heading();
        for (int i = 1; i <= sum; i++) {
            student[i].output();
        }
        cout << "����1���������򷵻�\n";
        cin >> kk;
        if (kk != "1") break;
    }
}
void case4() {
    while (1) {
        cases(4);
        string yy;
        string kk;
        cout << "======================================\n";
        cout << "        1.��ѧ��  2.������  ��������       \n ";
        cout << "======================================\n";
        cin >> yy;
        bool fl = false;
        if (yy == "1") {
            ll xx;
            cout << "����ѧ��:";
            cin >> xx;
            for (int i = 1; i <= sum; i++) {
                if (student[i].getId() == xx) {
                    student[i].output();
                    fl = true;
                }
            }
            if (!fl) cout << "δ�ҵ������Ϣ��\n";
        }else
        if (yy == "2") {
            string xx;
            cout << "��������:";
            cin >> xx;
            for (int i = 1; i <= sum; i++) {
                if (student[i].getName() == xx) {
                    student[i].output();
                    fl=true;
                 }
            }
             if (!fl) cout << "δ�ҵ������Ϣ��\n";
        }
        else break;
        cout << "����1���������򷵻�\n";
        cin >> kk;
        if (kk != "1") break;
    }
}
void case5() {
    cases(5);
    bool fl = true;
    string yy;
    while (fl) {
        sum++;
        student[sum].inputId();
        student[sum].inputName();
        student[sum].inputRegularGrade();
        student[sum].inputFinalExam();
        cout << "\n����1����,��������������:";
        cin >> yy;
        if (yy != "1") fl = false;
    }
    return;
}

void del1(ll x) {
    int k = 0;
    bool fl=false;
    for (int i = 1; i <= sum; i++) {
        if (student[i].getId() == x) {
            fl=true;
            k++;
            continue;
        } else {
            student[i - k] = (student[i]);
        }
    }
    if (!fl) cout<<"δ�ҵ������Ϣ\n";
        else cout<<"ɾ���ɹ�\n";
    sum = sum - k;
}
void del2(string x) {
    int k = 0;
    bool fl=false;
    for (int i = 1; i <= sum; i++) {
        if (student[i].getName() == x) {
            fl=true;
            k++;
            continue;
        } else {
            student[i - k] = student[i];
        }
    }
    if (!fl) cout<<"δ�ҵ������Ϣ\n";
    else cout<<"ɾ���ɹ�\n";
    sum = sum - k;
}
void case6() {
    while (1) {
        cases(6);
        string yy;
        string kk;
        cout << "======================================\n";
        cout << "      1.��ѧ��    2.������   ��������      \n ";
        cout << "======================================\n";
        cin >> yy;
        if (yy == "1") {
            ll xx;
            cout << "����ѧ��:";
            cin >> xx;
            del1(xx);
        }else
        if (yy == "2") {
            string xx;
            cout << "��������:";
            cin >> xx;
            del2(xx);
        }
        else{
            break;
        }
        cout << "����1���������򷵻�\n";
        cin >> kk;
        if (kk != "1") break;
    }
}
void case7in(double &m,double &n){
    while (1){
    cout<<"����ɼ���Χ:";
    cin>>m;
    cin>>n;
    if (m<0||n<0||m>100||n>100) cout<<"����������!\n";
    else{
    if (m>n) swap(m,n);
    break;
    }
    }
}
void case7() {
    while (1){
    cases(7);
    string yy;
    cout << "��������" << sum<<"\n";
    cout << "======================================\n";
    cout << "   1.��ƽʱ 2.����ĩ 3.������  ��������    \n ";
    cout << "======================================\n";
    cin>>yy;
    if (yy=="1")
    {
        double x,y;
        ll ans=0;
        case7in(x,y);
        bool fl=false;
        for(int i=1;i<=sum;i++)
        {
            if (student[i].getRegularGrade()>=x&&student[i].getRegularGrade()<=y)
            {
                if (!fl){
                student[i].heading();
                fl=true;
                }
                student[i].output();
                ans++;
            }
        }
        cout<<"������:"<<ans<<endl;
        string xxx;
        cout<<"����1�������������ء�";
        cin>>xxx;
        if (xxx!="1") break;

    }else if (yy=="2"){
    double x,y;
        ll ans=0;
        case7in(x,y);
        bool fl=false;
        for(int i=1;i<=sum;i++)
        {
            if (student[i].getFinalExam()>=x&&student[i].getFinalExam()<=y)
            {
                if (!fl){
                student[i].heading();
                fl=true;
                }
                student[i].output();
                ans++;
            }
        }
                cout<<"������:"<<ans<<endl;
                   string xxx;
        cout<<"����1�������������ء�";
        cin>>xxx;
        if (xxx!="1") break;
    }
    else if (yy=="3")
    {
     double x,y;
        ll ans=0;
        case7in(x,y);
        bool fl=false;
        for(int i=1;i<=sum;i++)
        {
            if (student[i].CalTotalMark()>=x&&student[i].CalTotalMark()<=y)
            {
                if (!fl){
                student[i].heading();
                fl=true;
                }
                student[i].output();
                ans++;
            }
        }
                cout<<"������:"<<ans<<endl;
                   string xxx;
        cout<<"����1�������������ء�";
        cin>>xxx;
        if (xxx!="1") break;
    }
    else break;
    }
    return ;
}
