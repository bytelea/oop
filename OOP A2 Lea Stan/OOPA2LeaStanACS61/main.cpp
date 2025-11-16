/// Inheritance:
/// The class `Current_Ac` and `Saver_Ac` both inherit from `new_Bank_Ac`.
/// This is an example of inheritance, where child classes reuse and extend the functionality of the parent class.

/// Polymorphism:
/// No virtual function, the method overloading of constructors in the `Bank_Users` and `new_Bank_Ac` classes is an example of compile-time polymorphism.

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class Bank_Users
{
public: /// Constructor overloading (Compile-time Polymorphism)
    Bank_Users(int user_Id, int PAC, string DOB);
    Bank_Users(int user_Id, int PAC);

    Bank_Users(string staff_Grade, int user_No, string pass);

    bool test_PAC (int PAC_1, int input_PAC1);
    bool test_user_Id(int user);
    bool Validate_user();

private:
    int dm_PAC;
    int dm_user_Id;
    int dm_input_PAC;
    string dm_DOB;
    string dm_Grade, dm_pass, dm_passIn;
    int dm_user_No;
    int dm_user_In;

    int c = 0; /// login attempts
};

Bank_Users::Bank_Users(string staff_Grade, int user_No, string pass)
{
    dm_Grade = staff_Grade;
    dm_user_No = user_No;
    dm_pass = pass;
}

/// Staff login validation with 2 attempts
bool Bank_Users::Validate_user()
{

    start:c = c+1;
    if (c>2)
    {
        cout << "Goodbye " << endl;
        return (0);
    }
    cout << "You have two attempts to log in " << endl;
    start2: cout <<"___________________________________" << endl;
    cout << "|           Login Screen          |" << endl;

    cout << "|Key in user no (1234 or 2334) ?  |";
    cin >> dm_user_In;
    cout << "|Key in password (Password.1x     |" << endl;
    cout << "|       or Password.2x            |";
    char c = ' ';
    dm_passIn = "";
    while (c != 13)
    {
        c = getch(); /// Read password char
    if (c != 13)
    {
        dm_passIn = dm_passIn + c;
        cout << "*";
    }
    }
    cout << "|" << setw(37) << "|" << endl;
    cout << "|" << setw(37) << "|" << endl;

    if ((dm_user_In == dm_user_No && dm_passIn == dm_pass) || (dm_user_In == dm_user_No && dm_passIn == dm_pass))
    {
        cout << "Valid user " << endl;
    }
    else
    {
      cout << "|          Invalid User          |" << endl;
    goto start2;
    }
    cout << "|           Valid User           |" << endl;
    cout << "|                                |" << endl;
}

Bank_Users::Bank_Users(int user_Id, int PAC, string DOB)
{
    dm_user_Id = user_Id;
    dm_PAC = PAC;
    dm_DOB = DOB;
}

bool Bank_Users::test_user_Id(int user)
{
    dm_user_Id = user;
    if (dm_user_Id == 12345678)
    {
        return true;
    }
    else
    {
       return false;
    }
}
bool Bank_Users::test_PAC(int PAC_no, int input_PAC)
{
    dm_PAC = PAC_no;
    dm_input_PAC = input_PAC;

if ((dm_PAC == 1 && dm_input_PAC != 9) || (dm_PAC == 2 && dm_input_PAC != 8) || (dm_PAC == 3 && dm_input_PAC !=8) || (dm_PAC == 4 && dm_input_PAC != 8) || (dm_PAC == 5 && dm_input_PAC != 7))
{
    return false;
}
else
{
    return true;
}
}

int pac1, pac2, pac3;
int user_pac1, user_pac2, user_pac3;
int user_Id;

class new_Bank_Ac
{
public: /// Constructor overloading (Compile-time Polymorphism)
    new_Bank_Ac(float init_balance);
    new_Bank_Ac();
    int get_acc_no();
    float get_init_balance();
    string get_branch_Code();
    string get_open_Date();

    void deposit(double amount);
    void withdraw(double amount);
    void display_basic_ac();
    double get_balance();

protected:
    int dm_account_no;
    int dm_balance;
    string dm_branch_code;
    string dm_open_Date;
    static int dm_ac_number;
};

int new_Bank_Ac::dm_ac_number = 30083001;

void new_Bank_Ac::display_basic_ac()
{
  cout << "|" << setw(15) << dm_account_no << setw(15) << dm_balance << "|" << endl;
}

class Current_Ac: public new_Bank_Ac /// Inherits account-related properties and methods from new_Bank_Ac
{
public:
    Current_Ac();
    string get_Cur_acc_type();
    float get_overdraft_limit();

private:
    string dm_type;
    float dm_over_draft;
};

class Saver_Ac: public new_Bank_Ac /// Inherits from new_Bank_Ac and adds specific functionality for Saver accounts
{
public:
    Saver_Ac();
    string get_Sav_acc_type();
    float get_Sav_interest();

private:
    string dm_S_type;
    float dm_Sav_Interest;
};

Saver_Ac::Saver_Ac()
{
 cout << "Key in account type: Student or Graduate" << endl;
 cin >> dm_S_type;

 cout << "Key in interest rate: 1% or 2.5%" << endl;
 cin >> dm_S_type;
}

string Saver_Ac::get_Sav_acc_type()
{
    return dm_S_type;
}

float Saver_Ac::get_Sav_interest()
{
    return dm_Sav_Interest;
}

new_Bank_Ac::new_Bank_Ac()
{
    dm_account_no = dm_ac_number ++;

cout << "Key in account balance: " << endl;
cin >> dm_balance;

cout << "Key in branch code: " << endl;
cin >> dm_branch_code;

cout << "Key in open date: " << endl;
///cin >> dm_open_Date;
}

new_Bank_Ac::new_Bank_Ac(float init_balance)
{
    dm_account_no = dm_ac_number++;
    dm_balance = init_balance;
}

double new_Bank_Ac::get_balance()
{
    return dm_balance;
}

void new_Bank_Ac::deposit(double amount)
{
    dm_balance = dm_balance + amount;
}

void new_Bank_Ac::withdraw(double amount)
{
    dm_balance = dm_balance - amount;
}

int new_Bank_Ac::get_acc_no()
{
    return dm_account_no;
}

float new_Bank_Ac::get_init_balance()
{
    return dm_balance;
}

string new_Bank_Ac::get_branch_Code()  ///ERROR 3
{
    return dm_branch_code; /// ERROR 4
}

string new_Bank_Ac::get_open_Date()
{
    return dm_open_Date;
}

Current_Ac::Current_Ac()
{
 cout << "Key in account type: Student or Graduate" << endl;
 cin >> dm_balance;

 cout << "Key in interest rate: 1% or 2.5%" << endl;
 cin >> dm_balance;
}

string Current_Ac::get_Cur_acc_type()
{
    return dm_type;
}

float Current_Ac::get_overdraft_limit()
{
    return dm_over_draft;
}

 cust_user:
    if (user_type == "C" || user_type == "c")
    {
        cout << endl;
        for (int i=0; i<40; i++)
        {
            cout << "_";
        }
        cout << "|" << setw(22) << "Indicate Account Type " << setw(18) << "|" << endl;
        cout << "|" << setw(40) << "|" << endl;
cout << "|" << setw(20) << "Account Type " << setw(20) << "|" << endl;
cout << "|" << setw(20) << "1 for current " << setw(20) << "|" << endl;
cout << "|" << setw(20) << "2 for saver " << setw(20) << "|" << endl;
    }

int AcNo[4] = {30083001,30083002,30083003,30083004};
float OpBal[4] = {500,350,290,850};
float Deposit1[4] = {450,650,200,850};
float Withdraw1[4] = {100,50,50,50};
int AccNo[2];
float balance[2];
string Branch_code[2];
string Open_date[2];
string account_type[2];
float over_draft[2];
string response;
string user_type;
int curr_option; ///ERROR1

int main()
{
    class Bank_Users cust_user(12345678,98887,"01021999");
    class Bank_Users staff_User1("Manager", 1234, "Password.1x");
    class Bank_Users staff_Users2("Trainee", 2334, "Password.2x");
system("COLOR 74");

/// Staff login validation
staff_User1.Validate_user();
cout << time(0) << endl;
start: srand (time(0));
cout <<"********************************************" << endl;
cout <<"|          Customer User Validation        |" << endl;
cout << " " << endl;
user_Id_label:cout << "Key in your 8 digit User ID (12345678)  :";
cin >> user_Id;
cout << endl;

cout << "Enter 3 randomly requested digits of your five digit" << endl;
cout << "Personal Access Code or PAC i.e. 98887" << endl;
cout << endl;

cout << endl;
pac1 = 1+ (rand()%5);
cout << "|" << setw(10) << "Enter PAC" << setw(3) << pac1 << setw(3) << ":";
start2:
pac2 = 1+ (rand()%5);
if (pac2 == pac1)
{
    goto start2;
}
pac3 = 1+ (rand()%5);
if (pac2 == pac1 || pac2 == pac3 || pac1 == pac3)
{
    goto start2;
}

cin >> user_pac1;
cout << "|" << setw(10) << "Enter PAC" << setw(3) << pac2 << setw(3) << ":";
cin >> user_pac2;
cout << "|" << setw(10) << "Enter PAC" << setw(3) << pac3 << setw(3) << ":";
cin >> user_pac3;

if ((cust_user.test_user_Id(user_Id) ==false ) || (cust_user.test_PAC(pac1,user_pac1) == false) || (cust_user.test_PAC(pac2,user_pac2 == false) || (cust_user.test_PAC(pac3,user_pac3) == false)))
    {
        cout << "Invalid login details" << endl;
        exit (EXIT_FAILURE);
    }

    else
    {
        cout << "VALID USER " << endl;
cout << "********************************************" << endl;
cout << setw(30) << " ************ " << endl;
    }


    for(int i=0; i<40; i++) ///Error 6
    {
        cout << "_";
    }
    cout << "********************************************" << endl;
    startA: cout << "|" << setw(20) << "Open Bank Account " << setw(20) << "|" << endl;  ///Error 7
    cout << "|" << setw(40) << "|" << endl;
    cout << "|" << setw(20) << "Key in " << setw(20) << "|" << endl;
    cout << "|" << setw(20) << "C for customer " << setw(20) << "|" << endl;
    cout << "|" << setw(20) << "S for staff" << setw(20) << "|" << endl;
    cout << "|" << setw(20) << "E to exit" << setw(20) << "|" << endl;
    cin >> user_type;
    cout << "|" << setw(40) << "|" << endl;
    for(int i=0; i<40; i++)
    {
        cout << "_";
    }

if (user_type == "S")
{
    new_Bank_Ac Customer5(OpBal[0]);
    new_Bank_Ac Customer6(OpBal[1]);
    new_Bank_Ac Customer7(OpBal[2]);
    new_Bank_Ac Customer8(OpBal[3]);
    Customer5.deposit(Deposit1[0]);
    Customer6.deposit(Deposit1[1]);
    Customer7.deposit(Deposit1[2]);
    Customer8.deposit(Deposit1[3]);
    Customer5.withdraw(Withdraw1[0]);
    Customer6.withdraw(Withdraw1[1]);
    Customer7.withdraw(Withdraw1[2]);
    Customer8.withdraw(Withdraw1[3]);
 cout << endl;
    Customer5.display_basic_ac();
    Customer6.display_basic_ac();
    Customer7.display_basic_ac();
    Customer8.display_basic_ac();

system("PAUSE");
goto startA;
}
if (user_type == "C")
{
    cout << "|" << setw(20) << "Select Account Type:" << setw(20) << "|" << endl;
    cout << "|" << setw(20) << "1. Current Account" << setw(20) << "|" << endl;
    cout << "|" << setw(20) << "2. Saver Account" << setw(20) << "|" << endl;
    cin >> curr_option;

    if (curr_option ==1)
    {
        Current_Ac Customer[1];

        AccNo[0] = Customer[0].get_acc_no();
        balance[0] = Customer[0].get_init_balance();
        Branch_code[0] = Customer[0].get_branch_Code();
        Open_date[0] = Customer[0].get_open_Date();
        account_type[0] = Customer[0].get_Cur_acc_type();
        over_draft[0] = Customer[0].get_overdraft_limit();

        cout << "|" << "You have created the following current account " << "|" << endl;
        cout << setw(20) << "Account No*" << setw(20) << AccNo[0] << endl;
        cout << setw(20) << "Opening Balance*" << setw(20) << balance[0] << endl;
        cout << setw(20) << "Branch Code*" << setw(20) << Branch_code[0] << endl;
        cout << setw(20) << "Opening Date*" << setw(20) << Open_date[0] << endl;
        cout << setw(20) << "Type *" << setw(20) << account_type[0] << endl;
        cout << setw(20) << "Overdraft Limit *" << setw(20) << over_draft[0] << endl;

        Customer[0].deposit(1000);
        Customer[0].display_basic_ac();
        system("PAUSE");
        goto start;
    }

    else if (curr_option == 2)
    {
        cout << "Opening Saver Account..." << endl;
        Saver_Ac SCustomer[1];
        // Assuming you'd want similar details displayed:
        AccNo[0] = SCustomer[0].get_acc_no();
        balance[0] = SCustomer[0].get_init_balance();
        Branch_code[0] = SCustomer[0].get_branch_Code();
        Open_date[0] = SCustomer[0].get_open_Date();
        account_type[0] = SCustomer[0].get_Sav_acc_type();
        float interest = SCustomer[0].get_Sav_interest();

        cout << "|" << "You have created the following saver account " << "|" << endl;
        cout << setw(20) << "Account No*" << setw(20) << AccNo[0] << endl;
        cout << setw(20) << "Opening Balance*" << setw(20) << balance[0] << endl;
        cout << setw(20) << "Branch Code*" << setw(20) << Branch_code[0] << endl;
        cout << setw(20) << "Opening Date*" << setw(20) << Open_date[0] << endl;
        cout << setw(20) << "Type *" << setw(20) << account_type[0] << endl;
        cout << setw(20) << "Interest Rate *" << setw(20) << interest << "%" << endl;

        SCustomer[0].deposit(500);
        SCustomer[0].display_basic_ac();
        system("PAUSE");
        goto start;
    }
}
}















