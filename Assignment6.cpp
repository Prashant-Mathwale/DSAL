// Problem Statement:
// Develop a hashing-based system for securely storing user credentials, where usernames act as keys
// and hashed passwords as values. Implement and demonstrate collision handling using:

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll_no;
    Student* next;
};

class Hash {
    Student* table[10];

    int hashFunction(int roll_no) {
        return roll_no % 10;
    }

public:
    Hash() {
        for (int i = 0; i < 10; i++) {
            table[i] = NULL; 
        }
    }

    void getdata() {
        string name;
        int roll_no;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student roll_no: ";
        cin >> roll_no;

        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->roll_no = roll_no;
        newStudent->next = NULL;

        int index = hashFunction(roll_no); 

        newStudent->next = table[index];
        table[index] = newStudent;

        cout << "Student inserted at index " << index << endl;
    }

    void search() {
        int roll_no;
        cout << "Enter roll_no to search: ";
        cin >> roll_no;

        int index = hashFunction(roll_no);
        Student* temp = table[index];

        while (temp != NULL) {
            if (temp->roll_no == roll_no) {
                cout << "Found: " << temp->name << " with roll_no " << roll_no << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Data not found.\n";
    }

    void displayTable() {
        cout << "\n--- Hash Table Contents ---\n";
        for (int i = 0; i < 10; i++) {
            cout << "Index " << i << ": ";
            Student* current = table[i];
            if (current == nullptr) {
                cout << "-> NULL";
            } else {
                while (current != nullptr) {
                    cout << "-> [" << current->name << ", " << current->roll_no << "]";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Hash h;
    int choice;

    while (true) {
        cout << "\nHash Table Menu\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.getdata();
                break;

            case 2:
                h.search();
                break;

            case 3:
                h.displayTable();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

/*
OUTPUT :

Hash Table Menu
1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter your choice: 1
Enter student name: Prashant
Enter student roll_no: 23326
Student inserted at index 6

Hash Table Menu
1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter your choice: 1
Enter student name: Sanket 
Enter student roll_no: 23342
Student inserted at index 2

Hash Table Menu
1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter your choice: 1
Enter student name: Om
Enter student roll_no: 23342
Student inserted at index 2

Hash Table Menu
1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter your choice: 2
Enter roll_no to search: 23326
Found: Prashant with roll_no 23326

Hash Table Menu
1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter your choice: 3

--- Hash Table Contents ---
Index 0: -> NULL
Index 1: -> NULL
Index 2: -> [Om, 23342]-> [Sanket, 23342]
Index 3: -> NULL
Index 4: -> NULL
Index 5: -> NULL
Index 6: -> [Prashant, 23326]
Index 7: -> NULL
Index 8: -> NULL
Index 9: -> NULL

Hash Table Menu
1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter your choice: 4
Exiting...*/