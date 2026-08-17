#include <iostream>
#include <stack>
using namespace std;

class Solution{
    public :
    bool isPalindrome(string str){
        stack<char>st;

        for(int i=0;i<str.size();i++){
            char c = str[i];
            st.push(c);
        }

        string rev= " ";
        while(!st.empty()){
            rev += st.top();
            st.pop();
        }
        return (str == rev);
    }
};

int main() {
    Solution obj;
    string str;
    cin >> str;

    if (obj.isPalindrome(str)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
    cout << endl;
}