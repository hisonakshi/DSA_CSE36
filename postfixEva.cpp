//POSTFIX EVALUATION
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class PostfixEva{
    public : 
    int evaluation(string postfix){
        stack<int>st;

        int i=0;
        
        while(i<postfix.size()){
            char symbol = postfix[i];
            i++;

            if(isdigit(symbol)){
                st.push(symbol-'0');
            }else{
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int value;

                switch(symbol){
                    case '+':
                    value = a+b;
                    break;

                    case '-':
                    value = a-b;
                    break;

                    case '*':
                    value = a*b;
                    break;

                    case '/':
                    value = a/b;
                    break;

                    case '^':
                    value = pow(a,b);
                    break;

                    default:
                    break;
                }

                st.push(value);

            }
        }

        return st.top();

    }
};

int main(){
    PostfixEva obj;
    string postfix;
    cin >> postfix;
    cout << obj.evaluation(postfix) << endl;
}