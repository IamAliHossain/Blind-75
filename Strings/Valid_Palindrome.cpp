#include<bits/stdc++.h>
using namespace std;


int main(){
    string s = "0p", t;
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 65 and s[i] <= 90){
            s[i] += 32;
        }
        if((s[i] >= 97 and s[i] <= 122) || (s[i] >= '0' and s[i] <= '9')){
            t.push_back(s[i]);
        }
    }
    // cout << t << endl;
    int right = t.size()-1;
    int left = 0;
    bool isPalindrom = true;
    while(left < right){
        if(t[left] != t[right]){
            // cout << t[left] << " " << t[right] << endl;
            // cout << "jhamela ache\n";
            isPalindrom = false;
        }
        left++;
        right--;
    }
    cout << isPalindrom << endl;
}