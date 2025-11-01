// Problem Statement:
// "Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for
// Contact Management System"
// Utilize Singly and Doubly Linked Lists to manage a Contact Management System. The system
// will support key operations such as:
// • Creating a contact list dynamically.
// • Adding new contacts efficiently.
// • Deleting contacts when no longer needed.
// • Searching for specific contacts based on name or number.
// • Reversing the contact list for alternate viewing orders.
// • Traversing through the list to display all stored contacts.


#include <iostream>
#include <string>
using namespace std;

struct Node {
    long long number;
    string name;
    string email;
    Node* next;
};

class MList {
    Node* head;

public:
    MList() {
        head = NULL;
    }

    Node* getnode() { 
        Node* t = new Node;

        cout << "Enter the name: ";
        cin >> t->name;
        while (t->name.length() < 2) {
            cout << "Enter a valid name (at least 2 characters): ";
            cin >> t->name;
        }

        cout << "Enter the number: ";
        cin >> t->number;
        while (t->number < 1000000000 || t->number > 9999999999) {
            cout << "Enter a valid 10-digit number: ";
            cin >> t->number;
        }

        cout << "Enter the email: ";
        cin >> t->email;
        while (t->email.find('@') == string::npos || t->email.find('.') == string::npos) {
            cout << "Enter a valid email (must contain '@' and '.'): ";
            cin >> t->email;
        }

        t->next = NULL;
        return t;
    }

    void create() {
        int n;
        cout << "How many nodes do you want to create? ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cout << "\nEnter data for node " << i + 1 << ":\n";
            Node* newNode = getnode();
            if (head == NULL) {
                head = newNode;
            } else {
                Node* tail = head;
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = newNode;
            }
        }

        cout << "Linked list created with " << n << " node(s).\n";
    }

    void insert_at_last() {
        Node* temp = getnode();
        if (head == NULL) {
            head = temp;
        } else {
            Node* tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = temp;
        }
    }

    void insert_at_start() {
        Node* temp = getnode();
        temp->next = head;
        head = temp;
    }

    void insert_in_between(string name) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node* p = head;
        while (p != NULL && p->name != name) {
            p = p->next;
        }

        if (p == NULL) {
            cout << "Node with name '" << name << "' not found in the list." << endl;
            return; 
        }

        Node* newNode = getnode();  
        newNode->next = p->next;
        p->next = newNode;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << "\nName: " << temp->name;
            cout << "\nNumber: " << temp->number;
            cout << "\nEmail: " << temp->email << endl;
            temp = temp->next;
        }
    }

    void delete_head() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
        } else {
            Node* t = head;
            head = head->next;
            delete t;
            cout << "Head node deleted" << endl;
        }
    }

    void delete_LL() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }

        string Name;
        cout << "Enter the name to be deleted: ";
        cin >> Name;


        while (head != NULL && head->name == Name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted a node with name " << Name << endl;
        }

        if (head == NULL) return;

        Node* current = head;
        while (current->next != NULL) {
            if (current->next->name == Name) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Deleted a node with name " << Name << endl;
            } else {
                current = current->next;
            }
        }
    }

    void search() {
        if (head == NULL) {
            cout << "List is empty, nothing to search.\n";
            return;
        }

        string searchName;
        cout << "Enter the name to search: ";
        cin >> searchName;

        Node* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->name == searchName) {
                cout << "\nFound record:\n";
                cout << "Name: " << temp->name << endl;
                cout << "Number: " << temp->number << endl;
                cout << "Email: " << temp->email << endl;
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No record found with name '" << searchName << "'\n";
        }
    }

    void reverse() {
        if (head == NULL || head->next == NULL) {
            cout << "List is empty or has only one node. No need to reverse." << endl;
            return;
        }

        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;   
            current->next = prev;   
            prev = current;         
            current = next;
        }

        head = prev;
        cout << "Linked list reversed successfully.\n";
    }
    ~MList() {
    Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

};

int main() {
    MList s;
    int choice;
    s.create();

    do {
        cout << " \nMENU"<<endl;
        cout << "1. Insert at last"<<endl;
        cout << "2. Delete head"<<endl;
        cout << "3. Delete by name"<<endl;
        cout << "4. Display"<<endl;
        cout << "5. Search by name"<<endl;
        cout << "6. Reverse"<<endl;
        cout << "7. Insert at start"<<endl;
        cout << "8. Insert in between"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char ch;
            do {
                s.insert_at_last();
                cout << "Do you want to insert another record? (y/n): ";
                cin >> ch;
            } while (ch == 'y' || ch == 'Y');
            break;
        }

        case 2:
            s.delete_head();
            break;

        case 3:
            s.delete_LL();
            break;

        case 4:
            s.display();
            break;

        case 5:
            s.search();
            break;

        case 6:
            s.reverse();
            break;

        case 7: {
            char ch1;
            do {
                s.insert_at_start();
                cout << "Do you want to insert another record? (y/n): ";
                cin >> ch1;
            } while (ch1 == 'y' || ch1 == 'Y');
            break;
        }

        case 8: {
            char ch2;
            do {
                string name;
                cout << "Enter the name after which you want to add the node: ";
                cin >> name;
                s.insert_in_between(name);
                cout << "Do you want to insert another record? (y/n): ";
                cin >> ch2;
            } while (ch2 == 'y' || ch2 == 'Y');
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 0);

    return 0;
}


// How many nodes do you want to create? 2

// Enter data for node 1:
// Enter the name: Prashant
// Enter the number: 9322830057
// Enter the email: prashant@gmail.com

// Enter data for node 2:
// Enter the name: Sanket
// Enter the number: 9878456532
// Enter the email: sanket@gmail.com
// Linked list created with 2 node(s).
 
// MENU
// 1. Insert at last
// 2. Delete head
// 3. Delete by name
// 4. Display
// 5. Search by name
// 6. Reverse
// 7. Insert at start
// 8. Insert in between
// 0. Exit
// Enter your choice: 4

// Name: Prashant
// Number: 9322830057
// Email: prashant@gmail.com

// Name: Sanket
// Number: 9878456532
// Email: sanket@gmail.com
 
// MENU
// 1. Insert at last
// 2. Delete head
// 3. Delete by name
// 4. Display
// 5. Search by name
// 6. Reverse
// 7. Insert at start
// 8. Insert in between
// 0. Exit
// Enter your choice: 0
// Exiting...