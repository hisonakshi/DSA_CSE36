#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class PrefixEva{
    public:
    int evaluation(string prefix){
        stack<int>st;

        int i = prefix.size() - 1;
        while(i>=0){
            char symbol = prefix[i];
            i--;

            if(isdigit(symbol)){
                st.push(symbol-'0');
            }else{

                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int value;
                switch(symbol){
                    case '+':
                    value = a + b;
                    break;

                    case '-':
                    value = a-b;
                    break;

                    case '*':
                    value = a * b;
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
    PrefixEva obj;
    string prefix;
    cin >> prefix;

    cout << obj.evaluation(prefix) << endl;

}
