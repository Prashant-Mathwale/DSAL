//Problem statement:
//Undo/Redo Functionality (Stack): Implementing an undo/redo feature in text editors or
//design software using a last-in, first-out (LIFO) approach.

#include<iostream>
#include<string>
using namespace std;

enum Priority { HIGH, MEDIUM, LOW };

class Node {
public:
    string task;
    Priority priority;
    int hours;
    Node* next;

    Node() {
        next = NULL;
    }
};

class queue {

    Node* front;
    Node* rear;

public:
    queue() {
        front = NULL;
        rear = NULL;
    }
Node* getNode() {
    Node* temp = new Node;
    cout << "\nEnter the task: ";
    cin >> temp->task;

    int prio;
    cout << "Enter priority (0 for HIGH, 1 for MEDIUM, 2 for LOW): ";
    while (true) {
        cin >> prio;
        if (prio >= 0 && prio <= 2) break;
        cout << "Invalid priority. Enter 0, 1, or 2: ";
    }
    temp->priority = (Priority)prio;  // <-- old-style cast here

    cout << "Enter number of hours required: ";
    cin >> temp->hours;

    temp->next = NULL;
    return temp;
}

    void enqueue() {
        Node* newNode = getNode();
        if (front == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (front == NULL) {
            cout << "\nQueue is empty " << endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == NULL) {
                rear = NULL;
            }
        }
    }

    void peek() {
        if (front == NULL) {
            cout << "List is empty " << endl;
        }
        else {
            cout << "First Task is: " << front->task << endl;
            cout << "Priority: ";
            switch (front->priority) {
                case HIGH: cout << "High"; break;
                case MEDIUM: cout << "Medium"; break;
                case LOW: cout << "Low"; break;
            }
            cout << endl;
            cout << "Hours required: " << front->hours << endl;
        }
    }
    void display() {
        if (front == NULL) {
            cout << "\nTask List is empty" << endl;
            return;
        }
        cout << "\nList of the Tasks is:" << endl;
        Node* temp = front;
        while (temp != NULL) {
            cout << "Task: " << temp->task << endl;
            cout << "Priority: ";
            switch (temp->priority) {
                case HIGH: cout << "High"; break;
                case MEDIUM: cout << "Medium"; break;
                case LOW: cout << "Low"; break;
            }
            cout << endl;
            cout << "Hours required: " << temp->hours << endl;
            cout << "-------------------" << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    void isEmpty() {
        if (front == NULL) {
            cout << "\nTask List is empty" << endl;
        }
        else {
            cout << "\nList is not empty" << endl;
        }
    }
};

int main() {
    queue q;
    int choice;
    do {
        cout << "\nMENU" << endl;
        cout << "Enter 1 to add Task " << endl;
        cout << "Enter 2 to delete Task " << endl;
        cout << "Enter 3 to display all Tasks" << endl;
        cout << "Enter 4 to show first Task" << endl;
        cout << "Enter 5 to check the List is empty or not" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            q.enqueue();
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.peek();
            break;

        case 5:
            q.isEmpty();
            break;

        case 0:
            cout << "Exiting " << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}

//OUTPUT

/*
MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
1

Enter the task: study
Enter priority (0 for HIGH, 1 for MEDIUM, 2 for LOW): 0
Enter number of hours required: 4

MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
1    

Enter the task: coding
Enter priority (0 for HIGH, 1 for MEDIUM, 2 for LOW): 1
Enter number of hours required: 3

MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
1

Enter the task: sport 
Enter priority (0 for HIGH, 1 for MEDIUM, 2 for LOW): 2
Enter number of hours required: 2

MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
3

List of the Tasks is:
Task: study
Priority: High
Hours required: 4
-------------------
Task: coding
Priority: Medium
Hours required: 3
-------------------
Task: sport
Priority: Low
Hours required: 2
-------------------


MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
4
First Task is: study
Priority: High
Hours required: 4

MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
4
First Task is: study
Priority: High
Hours required: 4

MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
5

List is not empty

MENU
Enter 1 to add Task 
Enter 2 to delete Task 
Enter 3 to display all Tasks
Enter 4 to show first Task
Enter 5 to check the List is empty or not
Enter 0 to exit
0
Exiting */