// Problem Statement: Department maintains student database. The file contains roll number, name, 
// division and address. Implement a CPP program to - 
// 1. Create a sequential file to store and maintain student data.  
// 2. It should allow the user to add and delete information of students.  
// 3. Display information of particular student.  
// i. If the student record does not exist an appropriate message is displayed.  
// ii. If student record is found it should display the student details. 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    string division;
    string address;
    string dob;
    float percentage;
    char grade;
};

class StudentDatabase
{
public:
    Student record;
    fstream file;

    void create();
    void add();
    void display();
    void search();
    void modify();
    void deleteRecord();
};

void StudentDatabase::create()
{
    file.open("StudentData.txt", ios::out);
    if (!file)
    {
        cout << "Error creating file!" << endl;
        return;
    }
    int n;
    cout << "Enter number of records to add: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> record.rollNo;
        cin.ignore();
        cout << "Name: ";
        getline(cin, record.name);
        cout << "Division: ";
        getline(cin, record.division);
        cout << "Address: ";
        getline(cin, record.address);
        cout << "Date of Birth (dd/mm/yyyy): ";
        getline(cin, record.dob);
        cout << "Percentage: ";
        cin >> record.percentage;
        cout << "Grade: ";
        cin >> record.grade;

        file << record.rollNo << " " << record.name << " " << record.division << " "
             << record.address << " " << record.dob << " " << record.percentage << " "
             << record.grade << endl;
    }
    file.close();
    cout << "\nFile created and records added successfully.\n";
}

void StudentDatabase::display()
{
    file.open("StudentData.txt", ios::in);
    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    cout << "\n---- Student Records ----\n";
    cout << "RollNo\tName\tDivision\tAddress\tDOB\tPercentage\tGrade\n";

    while (file >> record.rollNo >> record.name >> record.division >> record.address >>
           record.dob >> record.percentage >> record.grade)
    {
        cout << record.rollNo << "\t" << record.name << "\t" << record.division << "\t\t"
             << record.address << "\t" << record.dob << "\t" << record.percentage << "\t\t"
             << record.grade << endl;
    }

    file.close();
}

void StudentDatabase::add()
{
    file.open("StudentData.txt", ios::app);
    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    cin.ignore();
    cout << "\nEnter details of new student:\n";
    cout << "Roll No: ";
    cin >> record.rollNo;
    cin.ignore();
    cout << "Name: ";
    getline(cin, record.name);
    cout << "Division: ";
    getline(cin, record.division);
    cout << "Address: ";
    getline(cin, record.address);
    cout << "Date of Birth (dd/mm/yyyy): ";
    getline(cin, record.dob);
    cout << "Percentage: ";
    cin >> record.percentage;
    cout << "Grade: ";
    cin >> record.grade;

    file << record.rollNo << " " << record.name << " " << record.division << " "
         << record.address << " " << record.dob << " " << record.percentage << " "
         << record.grade << endl;

    file.close();
    cout << "New record added successfully.\n";
}

void StudentDatabase::search()
{
    int roll;
    bool found = false;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    file.open("StudentData.txt", ios::in);
    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    while (file >> record.rollNo >> record.name >> record.division >> record.address >>
           record.dob >> record.percentage >> record.grade)
    {
        if (record.rollNo == roll)
        {
            cout << "\nRecord Found:\n";
            cout << "Roll No: " << record.rollNo
                 << "\nName: " << record.name
                 << "\nDivision: " << record.division
                 << "\nAddress: " << record.address
                 << "\nDOB: " << record.dob
                 << "\nPercentage: " << record.percentage
                 << "\nGrade: " << record.grade << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found!\n";

    file.close();
}

void StudentDatabase::modify()
{
    int roll;
    cout << "Enter Roll Number to modify: ";
    cin >> roll;

    file.open("StudentData.txt", ios::in);
    ofstream temp("Temp.txt");

    if (!file || !temp)
    {
        cout << "File error!\n";
        return;
    }

    bool found = false;
    while (file >> record.rollNo >> record.name >> record.division >> record.address >>
           record.dob >> record.percentage >> record.grade)
    {
        if (record.rollNo == roll)
        {
            cout << "\nEnter new details:\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, record.name);
            cout << "Division: ";
            getline(cin, record.division);
            cout << "Address: ";
            getline(cin, record.address);
            cout << "Date of Birth: ";
            getline(cin, record.dob);
            cout << "Percentage: ";
            cin >> record.percentage;
            cout << "Grade: ";
            cin >> record.grade;
            found = true;
        }
        temp << record.rollNo << " " << record.name << " " << record.division << " "
             << record.address << " " << record.dob << " " << record.percentage << " "
             << record.grade << endl;
    }

    file.close();
    temp.close();

    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");

    if (found)
        cout << "Record modified successfully.\n";
    else
        cout << "Record not found.\n";
}

void StudentDatabase::deleteRecord()
{
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    file.open("StudentData.txt", ios::in);
    ofstream temp("Temp.txt");

    if (!file || !temp)
    {
        cout << "File error!\n";
        return;
    }

    bool found = false;
    while (file >> record.rollNo >> record.name >> record.division >> record.address >>
           record.dob >> record.percentage >> record.grade)
    {
        if (record.rollNo == roll)
        {
            found = true;
            continue;
        }
        temp << record.rollNo << " " << record.name << " " << record.division << " "
             << record.address << " " << record.dob << " " << record.percentage << " "
             << record.grade << endl;
    }

    file.close();
    temp.close();

    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}

int main()
{
    StudentDatabase db;
    int choice;

    do
    {
        cout << "\n===== STUDENT DATABASE MENU =====\n";
        cout << "1. Create File\n";
        cout << "2. Display All Records\n";
        cout << "3. Add New Record\n";
        cout << "4. Search Record\n";
        cout << "5. Modify Record\n";
        cout << "6. Delete Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            db.create();
            break;
        case 2:
            db.display();
            break;
        case 3:
            db.add();
            break;
        case 4:
            db.search();
            break;
        case 5:
            db.modify();
            break;
        case 6:
            db.deleteRecord();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}


/*
OUTPUT:
===== STUDENT DATABASE MENU =====
1. Create File
2. Display All Records
3. Add New Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 1
Enter number of records to add: 2

Enter details for student 1:
Roll No: 23326
Name: Prashant
Division: 11
Address: Nanded
Date of Birth (dd/mm/yyyy): 04/07/2007
Percentage: 98
Grade: A

Enter details for student 2:
Roll No: 23324
Name: Sanket
Division: 11
Address: Sambhaji nagar 
Date of Birth (dd/mm/yyyy): 05/10/2005
Percentage: 99
Grade: A

File created and records added successfully.

===== STUDENT DATABASE MENU =====
1. Create File
2. Display All Records
3. Add New Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 2

---- Student Records ----
RollNo  Name    Division        Address DOB     Percentage      Grade
23326   Prashant        11              Nanded  04/07/2007      98              A
23324   Sanket  11              Sambhaji        nagar   5               /

===== STUDENT DATABASE MENU =====
1. Create File
2. Display All Records
3. Add New Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 3

Enter details of new student:
Roll No: 23342
Name: Om
Division: 11
Address: Nagpur
Date of Birth (dd/mm/yyyy): 14/05/2006
Percentage: 98
Grade: A
New record added successfully.

===== STUDENT DATABASE MENU =====
1. Create File
2. Display All Records
3. Add New Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 6
Enter Roll Number to delete: 23326
Record deleted successfully.

===== STUDENT DATABASE MENU =====
1. Create File
2. Display All Records
3. Add New Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 2

---- Student Records ----
RollNo  Name    Division        Address DOB     Percentage      Grade
23324   Sanket  11              Sambhaji        nagar   5               /

===== STUDENT DATABASE MENU =====
1. Create File
2. Display All Records
3. Add New Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 7
Exiting program...*/
