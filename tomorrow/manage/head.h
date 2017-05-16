
#define HEAD ;
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <fstream>  
#include <vector>
using namespace std;
typedef long long ll;
string ss[100] = {
    "0.�˳�", "1.¼��ѧ��", "2.��ʾ��Ϣ", "3.��������", "4.����ѧ��", "5.����ѧ��", "6.ɾ��ѧ��", "7.ͳ������"};
string s;
ll sum = 0;
class Student {
  public:
    Student(){};
    Student(ll id1, string name1, double grade, double exam) {
        id = id1;
        name = name1;
        regularGrade = grade;
        finalExam = exam;
    }
    void inputId();
    void inputName();
    void inputRegularGrade();
    void inputFinalExam();
    void reId(ll x) {
        id = x;
    };
    void reName(string x) {
        name = x;
    }
    void reRegularGrade(double x) {
        regularGrade = x;
    }
    void reFinalExam(double x) {
        finalExam = x;
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    double getRegularGrade() {
        return regularGrade;
    }
    double getFinalExam() {
        return finalExam;
    }
    static void heading();
    void output() const;
    double CalTotalMark();

  private:
    ll id;
    string name;
    double regularGrade;
    double finalExam;
    int die;
};
Student student[100];