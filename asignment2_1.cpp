//Problem Statement:
// Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such
// as print job scheduling or process management in an operating system

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node() {
        data = "";         
        next = NULL;
    }
};

class Stack {
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    // Create a new node with user input
    Node* getNode() {
        Node* newNode = new Node;
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = NULL;
        return newNode;
    }

    // Push with user input
    void pushWithInput() {
        Node* newNode = getNode();
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  
        }
    }

    // Push with given data (for undo/redo, insert at end)
    void push(string val) {
        Node* newNode = new Node;
        newNode->data = val;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;   
        }
    }

    // Pop from end 
    string pop() {
        if (head == NULL) {
            return "";
        }
        if (head->next == NULL) {   
            string val = head->data;
            delete head;
            head = NULL;
            return val;
        }

        Node* temp = head;
        while (temp->next->next != NULL) { 
            temp = temp->next;
        }
        string val = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        return val;
    }

    // Clear stack
    void clear() {
        while (head != NULL) {
            pop();
        }
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    // Peek top element
    string peek() {
        if (head == NULL) return "";
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }
};

int main() {
    Stack undoStack, redoStack;
    int choice;

    do {
        cout << "\nMenu\n";
        cout << "1. Do Action (Push)\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Display Undo Stack\n";
        cout << "5. Display Redo Stack\n";
        cout << "0. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // New Action
                undoStack.pushWithInput(); 
                redoStack.clear(); 
                break;
            }

            case 2: { // Undo
                string val = undoStack.pop();
                if (val == "") {
                    cout << "Nothing to undo!" << endl;
                } else {
                    redoStack.push(val);
                    cout << "Undo: " << val << endl;
                }
                break;
            }

            case 3: { // Redo
                string val = redoStack.pop();
                if (val == "") {
                    cout << "Nothing to redo!" << endl;
                } else {
                    undoStack.push(val);
                    cout << "Redo: " << val << endl;
                }
                break;
            }

            case 4:
                cout << "Undo Stack: ";
                undoStack.display();
                break;

            case 5:
                cout << "Redo Stack: ";
                redoStack.display();
                break;

            case 0:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

//OUTPUT :
/* Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 1
Enter the data: study

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 1
Enter the data: coding

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 1
Enter the data: sport

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 4
Undo Stack: study coding sport 

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 
5
Redo Stack: Stack is empty

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 2
Undo: sport

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 4
Undo Stack: study coding 

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 5
Redo Stack: sport 

Menu
1. Do Action (Push)
2. Undo
3. Redo
4. Display Undo Stack
5. Display Redo Stack
0. Exit
Enter Your Choice: 0
Exiting
*/