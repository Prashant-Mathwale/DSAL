// Problem Statement: Implement a program to convert an infix expression to prefix and postfix
// notation. 
//• Evaluate both prefix and postfix expressions. Use STL for implementation.

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include<cmath>
using namespace std;

// Check if character is operator
bool isOperator(char ch) {
    return (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}

// Precedence of operators
int precedence(char ch) {
    if (ch == '^') return 3;  
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Convert Infix → Postfix
string infixToPostfix(const string &infix) {
    string postfix = "";
    stack<char> st;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand → directly to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // '(' → push
        else if (ch == '(') {
            st.push(ch);
        }
        // ')' → pop until '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // Operator
        else if (isOperator(ch)) {
            while (!st.empty() && st.top() != '(' &&
                   ((ch != '^' && precedence(st.top()) >= precedence(ch)) ||
                    (ch == '^' && precedence(st.top()) > precedence(ch)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Convert Infix → Prefix using Reverse method
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix
    reverse(infix.begin(), infix.end());

    // Step 2: Swap ( and )
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Convert to postfix
    string postfix = infixToPostfix(infix);

    // Step 4: Reverse postfix → prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Apply operator on two operands
float applyOp(float op1, float op2, char ch){
    switch(ch){
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            if(op2 == 0){
                cout << "Division by zero error!" << endl;
                return 0;
            }
            else{
                return op1 / op2;
            }
        case '^':
            return pow(op1, op2);
        default:
            cout << "Invalid operator " << ch << endl;
            return 0;
    }
}

// Evaluate Postfix Expression
float PostfixEvaluate(const string &postfix){
    stack<float> st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (!isOperator(ch)) {
            // Operand: prompt user for value
            float val;
            cout << "Enter the value of operand '" << ch << "': ";
            cin >> val;
            st.push(val);
        }
        else {
            // Operator: pop two operands
            if (st.size() < 2) {
                cout << "Error: insufficient operands for operator '" << ch << "'\n";
                return 0;
            }
            float right = st.top(); st.pop();
            float left = st.top(); st.pop();

            float result = applyOp(left, right, ch);
            st.push(result);
        }
    }

    if (st.size() != 1) {
        cout << "Error: invalid postfix expression\n";
        return 0;
    }

    return st.top();
}

int main() {
    int choice;
    string infix, postfix;

    do {
        cout << "\nInfix Expression Conversion Menu \n";
        cout << " 1. Convert Infix to Postfix\n";
        cout << " 2. Convert Infix to Prefix\n";
        cout << " 3. Exit\n";
        cout << " 4. Evaluate Postfix expression\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter infix expression: ";
                cin >> infix;
                postfix = infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;

            case 2:
                cout << "\nEnter infix expression: ";
                cin >> infix;
                cout << "Prefix expression: " << infixToPrefix(infix) << endl;
                break;

            case 3:
                cout << "Exiting program \n";
                break;

            case 4:
                cout << "Enter postfix expression to evaluate: ";
                cin >> postfix;
                cout << "Result of Postfix Expression: " << PostfixEvaluate(postfix) << endl;
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

/*
OUTPUT :

Infix Expression Conversion Menu 
 1. Convert Infix to Postfix
 2. Convert Infix to Prefix
 3. Exit
 4. Evaluate Postfix expression
Enter your choice: 1

Enter infix expression: (A+B)*(C-D)+F
Postfix expression: AB+CD-*F+

Infix Expression Conversion Menu 
 1. Convert Infix to Postfix
 2. Convert Infix to Prefix
 3. Exit
 4. Evaluate Postfix expression
Enter your choice: 2

Enter infix expression: (A+B)*(C-D)+F
Prefix expression: +*+AB-CDF

Infix Expression Conversion Menu 
 1. Convert Infix to Postfix
 2. Convert Infix to Prefix
 3. Exit
 4. Evaluate Postfix expression
Enter your choice: 4
Enter postfix expression to evaluate: AB+CD-*F+
Result of Postfix Expression: Enter the value of operand 'A': 5
Enter the value of operand 'B': 4
Enter the value of operand 'C': 6
Enter the value of operand 'D': 8
Enter the value of operand 'F': 2
-16

Infix Expression Conversion Menu 
 1. Convert Infix to Postfix
 2. Convert Infix to Prefix
 3. Exit
 4. Evaluate Postfix expression
Enter your choice: 3
Exiting program */