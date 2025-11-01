//Problem Statement:
// Implementation of a Double-Ended Queue (Deque)  
// • Implement a double-ended queue where insertion and deletion can happen from both ends.  
// • Support operations such as enqueue front, enqueue rear, deque front, dequeue rear. 

#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Deque(){
        front = NULL;
        rear = NULL;
    }

    // Check if deque is empty
    bool isEmpty() {
        if(front == NULL){
            return true;
        }
        else return false;
    }

    // Insert at front
    void insertFront(int x) {
        Node* newNode = new Node(x);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front = newNode;
        }
        cout << "Inserted " << x << " at front" << endl;
    }

    // Insert at rear
    void insertRear(int x) {
        Node* newNode = new Node(x);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted " << x << " at rear" << endl;
    }

    // Delete from front
    void deleteFront() {
        if (isEmpty()) {
            cout << " Deque is empty" << endl;
            return;
        }

        Node* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        cout << "Deleted " << temp->data << " from front" << endl;
        delete temp;
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << " Deque is empty" << endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = rear = nullptr;
            cout << "Deleted last element" << endl;
            return;
        }

        Node* temp = front;
        while (temp->next != rear) {
            temp = temp->next;
        }
        cout << "Deleted " << rear->data << " from rear" << endl;
        delete rear;
        rear = temp;
        rear->next = nullptr;
    }

    // Get front element
    void getFront() {
        if (isEmpty()) {
            cout << "Underflow: Deque is empty" << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Get rear element
    void getRear() {
        if (isEmpty()) {
            cout << "Underflow: Deque is empty" << endl;
            return;
        }
        cout << "Rear element: " << rear->data << endl;
    }

    // Display the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Deque elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\nDeque Menu " << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Get Front Element" << endl;
        cout << "6. Get Rear Element" << endl;
        cout << "7. Display Deque" << endl;
        cout << "8. Check if Deque is Empty" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;

            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.getFront();
                break;

            case 6:
                dq.getRear();
                break;

            case 7:
                dq.display();
                break;

            case 8:
                if (dq.isEmpty()) {
                    cout << "Deque is empty" << endl;
                } else {
                    cout << "Deque is not empty" << endl;
                }
                break;

            case 9:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}

/*
OUTPUT :

Deque Menu 
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 1
Enter value to insert at front: 10
Inserted 10 at front

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 2
Enter value to insert at rear: 20
Inserted 20 at rear

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 2
Enter value to insert at rear: 30
Inserted 30 at rear

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 7
Deque elements: 10 20 30 

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 4
Deleted 30 from rear

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 7
Deque elements: 10 20 

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 3
Deleted 10 from front

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 7
Deque elements: 20 

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 6
Rear element: 20

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 8
Deque is not empty

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 4
Deleted last element

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 8
Deque is empty

Deque Menu
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Get Front Element
6. Get Rear Element
7. Display Deque
8. Check if Deque is Empty
9. Exit
Enter your choice: 9
Exiting program...
*/