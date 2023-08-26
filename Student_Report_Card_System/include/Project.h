#ifndef PROJECT_H
#define PROJECT_H
#include <bits/stdc++.h>
using namespace std;
struct DETAIL
{
    int flag;
    int student_id;
    string name;
    int Grades[6];//  0:IT ; 1:ITlab ; 2:DM ; 3:DLD ; 4:CT ; 5:HM
    double SPI;
    double Grade_points_earn;

};
class Project
{
public:
    Project(int);
    void enter();
    void Enter_plus(int);
    void edit();
    void display();
    void SPI_count(int);
    double CreditEarn_count(int);
    void Delete_Detail();
    void sort_by_detail();
    void result();
    void edit_delete();
    void write_file();
    void read_file();

protected:

private:
    int Maximum;
    DETAIL* arr[1000];
};

#endif // PROJECT_H
