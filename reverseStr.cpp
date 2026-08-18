#include <iostream>
#include <stack>
using namespace std;

class Solution{
    public:
    void reverseStr(string str){
        stack<char>st;

        for(int i=0;i<str.size();i++){
            int c = str[i];
            st.push(c);
        }

        while(!st.empty()){
            char x = st.top();
            st.pop();
            cout << x;
        }
    }
};

int main(){
    Solution obj;
    string str;
    cin >> str;
    obj.reverseStr(str);
}