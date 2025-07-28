#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    // s = "()[]{}";
    // s = "({[)}]";
    // s = "({[]})";
    // s = "({)}";
    s = "}}";
    stack<char> st;
    bool valid = false;
    bool open = false;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' or s[i] == '{' or s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(!st.empty() and (st.top() == '(' and s[i] == ')') or (st.top() == '{' and s[i] == '}') or
                (st.top() == '[' and s[i] == ']')){
                st.pop();
            }
            else{
                valid = false;
                continue;
            }
        }
    }
    if(st.empty()){
        valid = true;
    }
    cout << (valid&open) << endl;
}