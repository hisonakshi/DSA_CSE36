//with vector so that dynmacally update the size 
// decimal to binary

#include <iostream>
using namespace std;

class Stack{
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

    bool empty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    void stackTop(){
        if(top == -1){
            cout << "EMPTY";
            

        }else{
            cout <<  st[top];
        }
    }
};

void DecimalToOctal( int N){
    Stack st;
    while(N!=0){
        int r = N % 8;
        st.push(r);
        N = N / 8;
    }

    cout << "Octal : ";

    while(!st.empty()){
        cout << st.pop();
    }
    cout << endl;
}

void DecimalToBinary(int N){
    Stack st;
    while(N!=0){
        int r=N%2;
        st.push(r);
        N = N/2;
    }

    cout << "Binary : ";

    while(!st.empty()){
        cout << st.pop();
    }
    cout << endl;
}

void DecimalToHexadecimal(int N){
    Stack st;

    while(N!=0){
        int r = N % 16;
        st.push(r);
        N = N / 16;
    }

    cout << "Hexadecimal ";

    while(!st.empty()){
        int x = st.pop();

        if(x>=0 && x<=9){
            cout << x;
        }else{
            cout << char(x-10+'A');
        }
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;

    DecimalToBinary(N);
    DecimalToOctal(N);
    DecimalToHexadecimal(N);
}





