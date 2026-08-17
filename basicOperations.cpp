#include <iostream>
using namespace std;

class Stack {
    private:
    int top;
    int st[10];

    public:
    Stack(){
        top = -1;
    }

    void push(int x){
        if(top == 9 ){
            cout << " Overflow";
        }else{
            top++;
            st[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return -1;
        } else {
             int x = st[top];
            top--;
            return x;
        }
    }

    int stackTop(){
        if(top == -1){
            cout << "Empty";
            return -1;
        }
         return st[top];
    }

    bool empty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    int size(){
        return top + 1;
    }

    void display(){
        if(top == -1){
            cout << "Empty stack" << endl;
            return;
        }

        for(int i=top;i>=0;i--){
            cout <<  st[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    Stack s;

    s.push(9);
    s.push(8);
    s.push(6);
    
    s.display();

    cout << "popped is " << s.pop() << endl;
    cout << "Top element " << s.stackTop() << endl;
    cout << "Size is " << s.size() << endl;
    s.display();
    cout << "IsEmpty " << s.empty() << endl;
}

