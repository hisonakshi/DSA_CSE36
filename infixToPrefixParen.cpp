//Without parenthesis
#include <iostream>
#include <algorithm>
using namespace std;

class Stack{
    int top;
    char st[10];

    public:
    Stack(){
        top = -1;
    }

    void push(char x){
        if(top == 9 ){
            cout << " Overflow";
        }else{
            top++;
            st[top] = x;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return -1;
        } else {
             int x = st[top];
            top--;
            return x;
        }
    }

    bool empty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
    char stackTop() {
        if (top == -1) {
            return '\0';
        }
        return st[top];
    }

};

bool prcd(char a,char b){               //same
    
    if(a=='(' || b == '('){
        return false;
    }

    if(b==')' ) {
        return true;
    }
    
    if(a == '^' || a=='*' || a=='/' || a=='%'){
        if(b=='^'){
            return false;
        }else{
            return true;
        }
    }

    if(a=='+'||a=='-'){
        if(b=='+' || b=='-'){
            return true;
        }else{
            return false;
        }
    }
    return false;
}


string InfixToPrefix(string infix) {
    Stack s;
    string prefix;

    int i = infix.size() - 1;

    while (i >= 0) {
        char symbol = infix[i];
        i--;

        // Operand
        if ((symbol >= 'a' && symbol <= 'z') ||
            (symbol >= 'A' && symbol <= 'Z') ||
            (symbol >= '0' && symbol <= '9')) {

            prefix += symbol;
        }

        // Closing parenthesis
        else if (symbol == ')') {
            s.push(symbol);
        }

        // Opening parenthesis
        else if (symbol == '(') {
            while (!s.empty() && s.stackTop() != ')') {
                prefix += s.pop();
            }

            // Remove ')'
            if (!s.empty()) {
                s.pop();
            }
        }

        // Operator
        else {
            while (!s.empty() && !prcd(symbol, s.stackTop())) {
                prefix += s.pop();
            }

            s.push(symbol);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        prefix += s.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix;
    cin >> infix;
    cout << InfixToPrefix(infix) << endl;
    return 0;
}





