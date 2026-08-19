#include <iostream>
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

bool prcd(char a,char b){

    // with parenthesis
    if(a=='(' || b == '('){
        return false;
    }

    if(b==')' ) {
        return true;
    }
    // with parenthesis
    

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


string InfixToPostfix(string infix) {
    Stack s;
    string postfix;

    int i = 0;

    while(i < infix.size()) {

        char symbol = infix[i];
        i++;

        if(symbol >= 'a' && symbol <= 'z' || 
           symbol >= 'A' && symbol <= 'Z'  ||           // with parenthesis
           symbol >= '0' && symbol <= '9') {            // with parenthesis

            postfix += symbol;
        }
        else {
            while(!s.empty() && prcd(s.stackTop(), symbol)) {
                postfix += s.pop();
            }

            if(symbol != ')'){                             // with parenthesis
                s.push(symbol);
            }else{
                s.pop();
            }
            
        }
    }




    while(!s.empty()) {
        postfix += s.pop();
    }

    return postfix;
}





int main() {
    string infix;
    cin >> infix;
    cout << InfixToPostfix(infix) << endl;
    return 0;
}




