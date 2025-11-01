// Problem Statement:
// Create a student database of at least 5 SEIT students, each having:
// •Roll Number (Integer)
// •Name (String)
// •SGPA (Float)
// Perform the following operations on the array of structure:
// a. Sort students by roll number (ascending order) using Bubble Sort.
// b. Sort students alphabetically by name using Insertion Sort.
// c. Sort students by SGPA in descending order using Quick Sort to get top 10 toppers.
// d. Search for students by SGPA using Linear Search and display all matches.
// e. Search for student(s) by name using non-recursive Binary Search, display all partial matches.


#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float sgpa;
};

class StudentDB {
    Student s[50];
    int n;

public:
    // Create database
    void create_database() {
        cout << "Enter number of records: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\nEnter Roll No: ";
            cin >> s[i].roll_no;
            cout << "Enter Name: ";
            cin >> s[i].name;
            cout << "Enter SGPA: ";
            cin >> s[i].sgpa;
        }
    }

    // Display all students
    void display_database() {
        cout << "\nRoll No\tName\tSGPA\n";
        for (int i = 0; i < n; i++) {
            cout << s[i].roll_no << "\t" << s[i].name << "\t" << s[i].sgpa << endl;
        }
    }

    // Bubble Sort by Roll Number
    void bubble_sort() {
        for (int pass = 0; pass < n - 1; pass++) {
            for (int i = 0; i < n - pass - 1; i++) {
                if (s[i].roll_no > s[i + 1].roll_no) {
                    swap(s[i], s[i + 1]);
                }
            }
        }
        cout << "\nSorted by Roll No (Ascending):\n";
        display_database();
    }

    // Insertion Sort by Name
    void insertion_sort() {
        for (int i = 1; i < n; i++) {
            Student key = s[i];
            int j = i - 1;
            while (j >= 0 && s[j].name > key.name) {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = key;
        }
        cout << "\nSorted by Name (Alphabetical):\n";
        display_database();
    }

    // Partition function for Quick Sort
    int partition(int l, int h) {
        float pivot = s[l].sgpa;
        int i = l, j = h;
        while (i < j) {
            while (i <= h && s[i].sgpa >= pivot) i++;
            while (j >= l && s[j].sgpa < pivot) j--;
            if (i < j) swap(s[i], s[j]);
        }
        swap(s[l], s[j]);
        return j;
    }

    // Quick Sort
    void quicksort(int l, int h) {
        if (l < h) {
            int p = partition(l, h);
            quicksort(l, p - 1);
            quicksort(p + 1, h);
        }
    }

    // Sort by SGPA (Descending, show toppers)
    void sort_by_sgpa() {
        quicksort(0, n - 1);
        cout << "\nSorted by SGPA (Descending - Toppers):\n";
        int top = (n < 10) ? n : 10;
        for (int i = 0; i < top; i++) {
            cout << s[i].roll_no << "\t" << s[i].name << "\t" << s[i].sgpa << endl;
        }
    }

    // Linear Search by SGPA
    void linear_search(float key) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (s[i].sgpa == key) {
                cout << "\nFound: " << s[i].roll_no << "\t" << s[i].name << "\t" << s[i].sgpa << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "\nNo student found with SGPA = " << key << endl;
        }
    }

    // Binary Search by Name (Non-Recursive)
    void binary_search(string key) {
        insertion_sort();  // ensure sorted by name
        int l = 0, h = n - 1;
        bool found = false;

        while (l <= h) {
            int mid = (l + h) / 2;
            if (s[mid].name == key) {
                cout << "\nFound: " << s[mid].roll_no << "\t" << s[mid].name << "\t" << s[mid].sgpa << endl;
                found = true;
                break;
            }
            else if (key < s[mid].name) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (!found) {
            cout << "\nNo exact match found for name: " << key << endl;
        }
    }
};

int main() {
    StudentDB db;
    int choice;
    float sgpa_key;
    string name_key;

    while (true) {
        cout << "\nStudent Database Menu \n";
        cout << "  1. Create Database\n";
        cout << "  2. Display Database\n";
        cout << "  3. Sort by Roll No (Bubble Sort)\n";
        cout << "  4. Sort by Name (Insertion Sort)\n";
        cout << "  5. Sort by SGPA (Quick Sort)\n";
        cout << "  6. Search by SGPA (Linear Search)\n";
        cout << "  7. Search by Name (Binary Search)\n";
        cout << "  8. Exit\n";
        cout <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                db.create_database(); 
                break;

            case 2: 
                db.display_database(); 
                break;

            case 3: 
                db.bubble_sort(); 
                break;

            case 4: 
                db.insertion_sort(); 
                break;

            case 5: 
                db.sort_by_sgpa(); 
                break;

            case 6: 
                cout << "Enter SGPA to search: ";
                cin >> sgpa_key;
                db.linear_search(sgpa_key);
                break;

            case 7: 
                cout << "Enter Name to search: ";
                cin >> name_key;
                db.binary_search(name_key);
                break;

            case 8: 
                cout << "Exiting program. \n";
                return 0;

            default: 
                cout << "Invalid Choice! \n";
        }

    }
    return 0;
}

/*OUTPUT:

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 1
Enter number of records: 3

Enter Roll No: 23326 
Enter Name: Prashant
Enter SGPA: 9.4

Enter Roll No: 23342
Enter Name: Sanket
Enter SGPA: 9.6

Enter Roll No: 23342
Enter Name: Om
Enter SGPA: 10

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 2

Roll No Name    SGPA
23326   Prashant        9.4
23342   Sanket  9.6
23342   Om      10

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 3

Sorted by Roll No (Ascending):

Roll No Name    SGPA
23326   Prashant        9.4
23342   Sanket  9.6
23342   Om      10

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 2

Roll No Name    SGPA
23326   Prashant        9.4
23342   Sanket  9.6
23342   Om      10

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 4

Sorted by Name (Alphabetical):

Roll No Name    SGPA
23342   Om      10
23326   Prashant        9.4
23342   Sanket  9.6

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 5

Sorted by SGPA (Descending - Toppers):
23342   Om      10
23342   Sanket  9.6
23326   Prashant        9.4

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 6
Enter SGPA to search: 10

Found: 23342    Om      10

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 7
Enter Name to search: Sanket

Sorted by Name (Alphabetical):

Roll No Name    SGPA
23342   Om      10
23326   Prashant        9.4
23342   Sanket  9.6

Found: 23342    Sanket  9.6

Student Database Menu 
  1. Create Database
  2. Display Database
  3. Sort by Roll No (Bubble Sort)
  4. Sort by Name (Insertion Sort)
  5. Sort by SGPA (Quick Sort)
  6. Search by SGPA (Linear Search)
  7. Search by Name (Binary Search)
  8. Exit

Enter your choice: 8
Exiting program. 
*/