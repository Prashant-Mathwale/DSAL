//Problem Statement:
// •Implementation of a Priority Queue
// •Develop a priority queue where elements are dequeued based on priority rather than
// •insertion order.
// •Support operations such as insertion, deletion, and display.

#include<iostream>
using namespace std;

enum Priority{
    High=3,
    Medium=2,
    low = 1
};

class Node{
    public:
    string patient;
    Priority priority;
    Node* next;

    Node(){
        next = NULL;
    }
};

class PriorityQue{
    Node* front;

    public:

    PriorityQue(){
        front = NULL;
    }

    Node*getNode(){
        Node *newNode = new Node;
        cout<<"Enter Patient type :";
        cin>>newNode->patient;

        int prio;
        cout << "Enter priority (3 for HIGH, 2 for MEDIUM, 1 for LOW): ";
        
        while(true){
            cin>>prio;
            if(prio >= 1 && prio <= 3)break;
            else{
                cout<<"Enter valid choice "<<endl;
            }
        }
        newNode->priority = (Priority)prio;
        newNode->next = NULL;

        return newNode;
    }
    void enque(){

        Node* newNode = getNode();

        if(front == NULL || newNode->priority >= front->priority){
            newNode->next=front;
            front = newNode;
        }

        else{
            Node* temp = front;
            while(temp->next != NULL  && temp->next->priority >= newNode->priority){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

    }
    void deque(){
        if(front == NULL){
            cout<<"Queue is empty "<<endl;
            return;
        }
        else{
            Node*temp = front;
            front = front->next ;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty!"<<endl;
            return;
        }
        Node* temp = front;
        cout << "Priority Queue: ";
        while (temp != NULL) {
            cout << "(" << temp->patient << ", priority " << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
      
};
int main(){
    PriorityQue q;
    int choice;

    do{
        cout<<"\n1. To enque"<<endl;
        cout<<"2. To dequeue"<<endl;
        cout<<"3. To display"<<endl;
        cout<<"0. TO exit the program"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            q.enque();
            break;
        
        case 2:
            q.deque();
            break;

        case 3:
            q.display();
            break;
        
        case 0:
            break;

        default:
            cout<<"Invalid Choice "<<endl;
            break;
        }

    }while(choice != 0);
}

/*
OUTPUT :
1. To enque
2. To dequeue
3. To display
0. TO exit the program
1
Enter Patient type :Accident
Enter priority (3 for HIGH, 2 for MEDIUM, 1 for LOW): 3

1. To enque
2. To dequeue
3. To display
0. TO exit the program
1
Enter Patient type :cough
Enter priority (3 for HIGH, 2 for MEDIUM, 1 for LOW): 1

1. To enque
2. To dequeue
3. To display
0. TO exit the program
1
Enter Patient type :Injury
Enter priority (3 for HIGH, 2 for MEDIUM, 1 for LOW): 2

1. To enque
2. To dequeue
3. To display
0. TO exit the program
3
Priority Queue: (Accident, priority 3) -> (Injury, priority 2) -> (cough, priority 1) -> NULL

1. To enque
2. To dequeue
3. To display
0. TO exit the program
2

1. To enque
2. To dequeue
3. To display
0. TO exit the program
3
Priority Queue: (Injury, priority 2) -> (cough, priority 1) -> NULL

1. To enque
2. To dequeue
3. To display
0. TO exit the program
*/