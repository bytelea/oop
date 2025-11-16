#include <iostream>
#include <iomanip>

using namespace std;

class Exams
{

public:
    string get_H_grade(float mark);
private:
    string dm_grade;
    float dm_mark;

};

string Exams::get_H_grade(float mark)
{
  dm_mark = mark;
  if (dm_mark >= 90 && dm_mark <= 100)
  { dm_grade = "H1"; }
  if (dm_mark >= 80 && dm_mark < 90)
  { dm_grade = "H2"; }
  if (dm_mark >= 70 && dm_mark < 80)
  { dm_grade = "H3"; }
  if (dm_mark >= 60 && dm_mark < 70)
  { dm_grade = "H4"; }
  if (dm_mark >= 50 && dm_mark < 60)
  { dm_grade = "H5"; }
  if (dm_mark >= 40 && dm_mark < 50)
  { dm_grade = "H6"; }
  if (dm_mark >= 30 && dm_mark < 40)
  { dm_grade = "H7"; }
  if (dm_mark >= 20 && dm_mark < 30)
  { dm_grade = "H8"; }
}

float mark;
string grade, level;

int main()
{
    class Exams student1;
cout << "Enter level, H for Higher or O for Ordinary" << endl;
    cin >> level;
cout << "Enter a mark between 60 and 100" << endl;
    cin << mark;

if (level == "H")
{   grade = student1.get_H_grade(mark);
cout << set1(10) << "Grade" << setw(10) << grade << endl;
 }
    cout << "Hello world!" << endl;
    return 0;
}
