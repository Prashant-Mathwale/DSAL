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
#include <iomanip>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float cgpa;

    void getData() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void displayData() const {
        cout << left << setw(10) << rollNo
             << setw(25) << name
             << setw(10) << cgpa << endl;
    }
};

// Function to create file with initial data
void createFile() {
    ofstream fout("StudentData.txt", ios::out);
    if (!fout) {
        cout << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter number of student records to add: ";
    cin >> n;
    cin.ignore();

    Student s;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i + 1 << ":" << endl;
        s.getData();
        fout << s.rollNo << "|" << s.name << "|" << s.cgpa << "\n";
    }

    fout.close();
    cout << "\nFile created and records saved successfully!\n";
}

// Function to display all records
void displayFile() {
    ifstream fin("StudentData.txt", ios::in);
    if (!fin) {
        cout << "File not found!" << endl;
        return;
    }

    cout << "\n---- Student Records ----\n";
    cout << left << setw(10) << "RollNo"
         << setw(25) << "Name"
         << setw(10) << "CGPA" << endl;

    Student s;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        s.rollNo = stoi(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.cgpa = stof(line.substr(pos2 + 1));
        s.displayData();
    }

    fin.close();
}

// Function to add a new record
void addRecord() {
    ofstream fout("StudentData.txt", ios::app);
    if (!fout) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    cout << "\nEnter details of new student:\n";
    s.getData();
    fout << s.rollNo << "|" << s.name << "|" << s.cgpa << "\n";
    fout.close();

    cout << "\nRecord added successfully!\n";
}

// Function to search for a record by roll number
void searchRecord() {
    ifstream fin("StudentData.txt", ios::in);
    if (!fin) {
        cout << "File not found!" << endl;
        return;
    }

    int key;
    cout << "\nEnter Roll Number to search: ";
    cin >> key;

    bool found = false;
    string line;
    Student s;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        s.rollNo = stoi(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.cgpa = stof(line.substr(pos2 + 1));

        if (s.rollNo == key) {
            cout << "\nRecord Found:\n";
            cout << left << setw(10) << "RollNo"
                 << setw(25) << "Name"
                 << setw(10) << "CGPA" << endl;
            s.displayData();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found!\n";

    fin.close();
}

// Function to modify a record
void modifyRecord() {
    ifstream fin("StudentData.txt");
    ofstream fout("Temp.txt");
    if (!fin || !fout) {
        cout << "Error opening file!" << endl;
        return;
    }

    int key;
    cout << "\nEnter Roll Number to modify: ";
    cin >> key;

    bool found = false;
    Student s;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        s.rollNo = stoi(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.cgpa = stof(line.substr(pos2 + 1));

        if (s.rollNo == key) {
            cout << "\nCurrent record:\n";
            s.displayData();
            cout << "\nEnter new details:\n";
            s.getData();
            found = true;
        }
        fout << s.rollNo << "|" << s.name << "|" << s.cgpa << "\n";
    }

    fin.close();
    fout.close();

    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");

    if (found)
        cout << "\nRecord modified successfully!\n";
    else
        cout << "\nRecord not found!\n";
}

// Function to delete a record
void deleteRecord() {
    ifstream fin("StudentData.txt");
    ofstream fout("Temp.txt");
    if (!fin || !fout) {
        cout << "Error opening file!" << endl;
        return;
    }

    int key;
    cout << "\nEnter Roll Number to delete: ";
    cin >> key;

    bool found = false;
    Student s;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        s.rollNo = stoi(line.substr(0, pos1));
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.cgpa = stof(line.substr(pos2 + 1));

        if (s.rollNo == key) {
            found = true;
            continue; // Skip writing this record
        }
        fout << s.rollNo << "|" << s.name << "|" << s.cgpa << "\n";
    }

    fin.close();
    fout.close();

    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");

    if (found)
        cout << "\nRecord deleted successfully!\n";
    else
        cout << "\nRecord not found!\n";
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\nStudent File Handling\n";
        cout << "1. Create File\n";
        cout << "2. Display All Records\n";
        cout << "3. Add Record\n";
        cout << "4. Search Record\n";
        cout << "5. Modify Record\n";
        cout << "6. Delete Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createFile(); break;
            case 2: displayFile(); break;
            case 3: addRecord(); break;
            case 4: searchRecord(); break;
            case 5: modifyRecord(); break;
            case 6: deleteRecord(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}


/*
OUTPUT:
Student File Handling
1. Create File
2. Display All Records
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 1
Enter number of student records to add: 3

Enter details of student 1:

Enter Roll Number: 23326
Enter Name: Prashant
Enter CGPA: 9.4

Enter details of student 2:

Enter Roll Number: 23342
Enter Name: Sanket 
Enter CGPA: 9.6

Enter details of student 3:

Enter Roll Number: 23342
Enter Name: Om
Enter CGPA: 10  

File created and records saved successfully!

Student File Handling
1. Create File
2. Display All Records
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 2

---- Student Records ----
RollNo    Name                     CGPA
23326     Prashant                 9.4
23342     Sanket                   9.6
23342     Om                       10

Student File Handling
1. Create File
2. Display All Records
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 3

Enter details of new student:

Enter Roll Number: 23347
Enter Name: Pruthviraj
Enter CGPA: 9 

Record added successfully!

Student File Handling
1. Create File
2. Display All Records
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 4

Enter Roll Number to search: 23326 

Record Found:
RollNo    Name                     CGPA
23326     Prashant                 9.4

Student File Handling
1. Create File
2. Display All Records
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 5

Enter Roll Number to modify: 23342

Current record:
23342     Sanket                   9.6

Enter new details:

Enter Roll Number: 6
Enter Name: 
Enter CGPA: 9  

Current record:
23342     Om                       10

Enter new details:

Enter Roll Number: 23347
Enter Name: P
Enter CGPA: 9

Record modified successfully!

Student File Handling
1. Create File
2. Display All Records
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
7. Exit
Enter your choice: 7
Exiting...*/
