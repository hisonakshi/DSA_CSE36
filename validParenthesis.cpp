#include <iostream>
using namespace std;

class Solution{
    public:
    bool validParenthesis(string str){
        stack<char>st;

        for(auto ch : str){
            if(ch == '('){
                st.push(ch);
            }else if(ch == ')'){
                
                if(st.empty())return false;

                if( (ch == ')' && st.top() == '(' )){
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
   cout <<  obj.validParenthesis(str) << endl;

}