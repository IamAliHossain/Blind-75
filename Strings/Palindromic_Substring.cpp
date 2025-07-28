#include<bits/stdc++.h>
using namespace std;


bool dp[1010][1010];


int main(){

    // string s = "leetcode";
    // string s = "longtimenosee";
    // string s = "fdsklf";
    string s = "itsbeenalongtime";
    int palindromCnt = s.size();
    for(int i=0; i<s.size(); i++){
        dp[i][i] = true;
    }
    cout << palindromCnt << endl;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]){ 
            dp[i][i+1] = true;
            palindromCnt++;
        }
    }
    cout << palindromCnt << endl;
    for(int len = 3; len<=s.size(); len++){
        for(int i=0; i<s.size()-len+1; i++){
            int j = i+len-1;
            if(s[i] == s[j] and dp[i][j] == true){ 
                dp[i][j] = true;
                palindromCnt++;
            }
        }
    }
    cout << palindromCnt << endl;

}