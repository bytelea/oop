#include <iostream>
#include <iomanip>

using namespace std;

class Exams
{

public:
    string get_O_grade(float mark);
private:
    string dm_grade;
    float dm_mark;

};

string Exams::get_O_grade(float mark)
{
  dm_mark = mark;
  if (dm_mark >= 90 && dm_mark <= 100)
  { dm_grade = "O1"; }
  if (dm_mark >= 80 && dm_mark < 90)
  { dm_grade = "O2"; }
  if (dm_mark >= 70 && dm_mark < 80)
  { dm_grade = "O3"; }
  if (dm_mark >= 60 && dm_mark < 70)
  { dm_grade = "O4"; }
  if (dm_mark >= 50 && dm_mark < 60)
  { dm_grade = "O5"; }
  if (dm_mark >= 40 && dm_mark < 50)
  { dm_grade = "O6"; }
  if (dm_mark >= 30 && dm_mark < 40)
  { dm_grade = "O7"; }
  if (dm_mark >= 20 && dm_mark < 30)
  { dm_grade = "O8"; }
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

if (level == "O")
{   grade = student1.get_H_grade(mark);
cout << set1(10) << "Grade" << setw(10) << grade << endl;
 };
    return 0;
}

