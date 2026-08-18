#include <iostream>
using namespace std;

class Solution{
    public:
    bool validBrackets(string str){
        stack<char>st;

        for(auto ch : str){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else if(ch == ')' || ch == '}' || ch == ']'){

                if(st.empty())return false;

                if( (ch == ')' && st.top() == '(' ) || (ch == '}' && st.top() == '{' ) || (ch==']' && st.top() == '[')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main(){
    Solution obj;
    string str;
    cin >> str;
   cout <<  obj.validBrackets(str) << endl;

}