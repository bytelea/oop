#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

// this class validates the user input
class validation
{
public:
    // checks if the mark that was input by the user is valid
    bool valid_mark(float mark);
private:
    float dm_V_mark;
};

// function that validates the mark input from the user
bool validation::valid_mark(float mark)
{
    dm_V_mark = mark;
    // this checks if the input is within the valid mark range
    // (between 0-100)
    if (dm_V_mark < 0 || dm_V_mark > 100)
    {
         // the following lines output the message to let the
         // user know if their input mark was valid or not
        cout << dm_V_mark << " is not a valid mark." << endl;
        return false;
    }
    else
    {

        cout << dm_V_mark << " is a valid mark." << endl;
        return true;
    }
}

// this is the class for all exam and reports data
class exams
{
public:
    // function to find grades from marks
    string get_grade(float mark);
    // function to find CAO points from grade
    float get_CAO_points(string grade);
    // function to print report 1 headings
    void print_report1_headings();
    // function to print report 2 headings
    void print_report2_headings();
    // function to print report 3 headings
    void print_report3_headings();

private:
    // this line is the output for the subject names
    string dm_sub_name[6]= {"OOP","PPD","MATHS","NETWORKS","GAMES","MOBTECH"};
    float dm_mark, dm_CAO_points;
    string dm_grade= "#";
};

// function with an if statement for CAO points from grades
float exams::get_CAO_points(string grade)
{
    dm_grade = grade;
    if(dm_grade == "U")
    {dm_CAO_points = 0;}
    if(dm_grade == "P")
    {dm_CAO_points = 16.67;}
    if(dm_grade == "M")
    {dm_CAO_points = 33;}
    if(dm_grade == "D")
    {dm_CAO_points = 50;}
    return dm_CAO_points;
}

// function to print report 1 headings
void exams::print_report1_headings()
{
    cout << setw(30) << "Rathmines College" << endl;
    cout << setw(30) << "QQI Level 5 Marks% CCP1  May 2024" << endl;

    cout << setw(15) << "Student Name ";
    for (int c=0;c<6;c++)
    {
        cout << left << setw(10) << dm_sub_name[c];
    }
    cout << setw(10) << "Average";
    cout << endl;
}

// function to print report 2 headings
void exams::print_report2_headings()
{
    cout << setw(30) << "Rathmines College" << endl;
    cout << setw(30) << "QQI Level CAO Points CCP1  May 2024" << endl;

    cout << setw(15) << "Modules ";
    for (int c=0;c<6;c++)
    {
        cout << left << setw(10) << dm_sub_name[c];
    }
    cout << setw(10) << " CAO";
    cout << endl;
    ///cout << endl;
}

// function to print report 3 headings
void exams::print_report3_headings()
{
    cout << setw(30) << "Rathmines College" << endl;
    cout << setw(30) << "QQI Level 5 Grades & CAO Points CCP1  May 2024" << endl;
// spacing size between each heading declared in brackets
    cout << setw(15) << "Modules ";
    for (int c=0;c<6;c++)
    {
        cout << left << setw(10) << dm_sub_name[c];
    }
    cout << setw(10) << " CAO";
    cout << endl;
}

// function determining grades based on the marks and
//the corresponding output for each
string exams::get_grade(float mark)
{bool valid_mark(float);
    dm_mark = mark;
    if (dm_mark == 50)
    {
        dm_grade = "U";
    }
    if (dm_mark >= 80)
    {
        dm_grade = "D";
    }
    if (dm_mark >= 50 && dm_mark <65)
    {
        dm_grade = "P";
    }
    if (dm_mark >= 65 && dm_mark <80)
    {
        dm_grade = "M";
    }
    return dm_grade;
}

// array of student marks
int data[6][6] =   {50,50,50,50,50,50,
                    60,80,75,50,60,75,
                    80,55,65,59,70,70,
                    60,68,75,50,60,55,
                    60,70,70,67,70,70,
                    90,90,90,90,90,90};

//array of student names
string student_name[6] = {"Evan Ferguson","Chiede Ogbene","Adam Idah","Megan Connolly","Katie McCabe","Robbie O'Grady"};
// 2D array storing the student grades
string grade[6][6];
// 2D array storing students CAO points
float CAO_student[6][6];
float column_total, column_average, row_total, row_average;
string best_student;
// string stream to format the programs output
stringstream ss;
// an array storing students highest average mark
float column_totals[6];
float best_mark = 0;

// main function
int main()
{
    // this line changes the console colour
    system("COLOR F4");

class validation user1;
float mark;

// loop validating the mark the user input
start: cout << "__________________________" << endl;
    cout << "|   Test mark validity   |" << endl;
    cout << "|" << setw(25) << "|" << endl;

    cout << "|     Key in a mark?     |";
cin >> mark;

    if (user1.valid_mark(mark)== false)
    {
        // an if statement to repeat the input option if
        //the mark the user initially input was invalid
        goto start;
    }
    else
    {
        cout << "|       Valid mark       |" << endl << endl;
    };

class exams student[6];
for (int a=0;a<=60;a++)
    {
    cout << "_";
    }
cout << endl;

// this line prints report 1
class exams report;
report.print_report1_headings();
for (int i=0;i<6;i++)
    {
    row_total = 0;
    row_average = 0;

cout << setw(15) << student_name[i];
    for (int j = 0;j<6;j++)
    {
        // this line prints each student name
        cout << setw(10) << data[i][j];
        // this line calculates the row total
        row_total = row_total + data[i][j];
        column_totals[j]=column_totals[j] + data[i][j];
    }
    // calculation for row average
    row_average = row_total/6;
    cout << fixed << setprecision(1)<< setw(10) << row_average << endl;
    if(row_average > best_mark)
    {
        best_mark = row_average;
        best_student = student_name[i];
    }
    }

    //these lines output the best student and best best mark data
ss << "Best student: ";
ss << best_student;
ss << "    Best average mark: ";
ss << best_mark;
cout << left << setw(49) << ss.str() << endl;
cout <<"End of Report 1" << endl;

system("PAUSE");

for(int a=0;a<80;a++)
    {
        cout << "_";
    }
cout << endl;

// this line prints report 2
report.print_report2_headings();
for (int i=0;i<6;i++)
    {
    row_total = 0;
    row_average = 0;

cout << setw(15) << student_name[i];
    for (int j = 0;j<6;j++)
    {
        grade[i][j] = student[i].get_grade(data[i][j]);
        CAO_student[i][j] = student[i].get_CAO_points(grade[i][j]);
        cout << setw(10) << CAO_student[i][j];

        //this line calculates the row total
        row_total = row_total + CAO_student[i][j];
    }
cout << setw(10)<< row_total << endl;
    }

cout <<"End of Report 2" << endl;

system("PAUSE");

for(int a=0;a<80;a++)
    {
        cout << "_";
    }
cout << endl;

// this line prints report 3
report.print_report3_headings();
for (int i=0;i<6;i++)
    {
    row_total = 0;
    row_average = 0;

cout << setw(15) << student_name[i];
    for (int j = 0;j<6;j++)
    {
        grade[i][j] = student[i].get_grade(data[i][j]);
        CAO_student[i][j] = student[i].get_CAO_points(grade[i][j]);
      cout << setw(10) << grade[i][j];

        row_total = row_total + CAO_student[i][j];
    }
    row_average = row_total/6;
    cout << fixed << setprecision(1)<< setw(10) << row_total << endl;
    }
cout <<"End of Report 3" << endl;

system("PAUSE");

// this line outputs the line separator
for(int a=0;a<80;a++)
    {
        cout << "_";
    }
cout << endl;


}

