#include <iostream>
#include <string>
using namespace std;

class DList {
    struct Node {
        string name;
        string number;
        string email;
        Node* next;
        Node* prev;
    };

    Node* head;

public:
    // Constructor
    DList() {
        head = NULL;
    }

    // Function to create and validate a new node
    Node* getnode() {
        Node* t = new Node;
        string num, mail;

        cout << "Enter name: ";
        cin >> t->name;

        // Validate number
        while (true) {
            cout << "Enter number (10 digits): ";
            cin >> num;
            if (num.size() == 10) {
                bool valid = true;
                for (char c : num) {
                    if (!isdigit(c)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    t->number = num;
                    break;
                } else {
                    cout << "Invalid number! Only digits allowed." << endl;
                }
            } else {
                cout << "Invalid number! Must be exactly 10 digits." << endl;
            }
        }

        // Validate email
        while (true) {
            cout << "Enter email: ";
            cin >> mail;
            if (mail.find('@') != string::npos) {
                t->email = mail;
                break;
            } else {
                cout << "Invalid email! Must contain '@' symbol." << endl;
            }
        }

        t->next = NULL;
        t->prev = NULL;
        return t;
    }

    // Insert at last
    void insert_at_last() {
        Node* newNode = getnode();
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Record created successfully." << endl;
    }

    // Insert at start
    void insert_at_start() {
        Node* newNode = getnode();
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Record inserted at start successfully." << endl;
    }

    // Insert in between (by name)
    void insert_in_between() {
        if (head == NULL) {
            cout << "List is empty. Cannot insert in between." << endl;
            return;
        }

        string searchName;
        cout << "Enter name after which to insert: ";
        cin >> searchName;

        Node* temp = head;
        while (temp != NULL && temp->name != searchName) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Name not found in the list." << endl;
        } else {
            Node* newNode = getnode();
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            cout << "Record inserted successfully after " << searchName << "." << endl;
        }
    }

    // Delete head node
    void delete_head() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cout << "Head node deleted." << endl;
    }

    // Delete entire list
    void delete_LL() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        cout << "Entire list deleted." << endl;
    }

    // Search by name
    void search() {
        if (head == NULL) {
            cout << "List is empty. Nothing to search." << endl;
            return;
        }

        string searchName;
        cout << "Enter name to search: ";
        cin >> searchName;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == searchName) {
                cout << "Record found:" << endl;
                cout << "Name: " << temp->name << endl
                     << "Number: " << temp->number << endl
                     << "Email: " << temp->email << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Record not found." << endl;
    }

    // Display all records
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Contact List:" << endl;
        while (temp != NULL) {
            cout << "Name: " << temp->name << endl
                 << "Number: " << temp->number << endl
                 << "Email: " << temp->email << endl;
            cout << "--------------------------" << endl;
            temp = temp->next;
        }
    }

    // Reverse display
    void reverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Reversed Contact List:" << endl;
        while (temp != NULL) {
            cout << "Name: " << temp->name << endl
                 << "Number: " << temp->number << endl
                 << "Email: " << temp->email << endl;
            cout << "--------------------------" << endl;
            temp = temp->prev;
        }
    }

    // Destructor (kept last)
    ~DList() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        cout << "Destructor called: All nodes deleted." << endl;
    }
};

// Main Menu
int main() {
    DList obj;
    int choice;

    do {
        cout << "\n--- Contact Management System (Doubly Linked List) ---" << endl;
        cout << "1. Insert at Last" << endl;
        cout << "2. Insert at Start" << endl;
        cout << "3. Insert in Between (by name)" << endl;
        cout << "4. Delete Head" << endl;
        cout << "5. Delete Entire List" << endl;
        cout << "6. Search by Name" << endl;
        cout << "7. Display All" << endl;
        cout << "8. Display Reverse" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.insert_at_last();
                break;
            case 2:
                obj.insert_at_start();
                break;
            case 3:
                obj.insert_in_between();
                break;
            case 4:
                obj.delete_head();
                break;
            case 5:
                obj.delete_LL();
                break;
            case 6:
                obj.search();
                break;
            case 7:
                obj.display();
                break;
            case 8:
                obj.reverse();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
