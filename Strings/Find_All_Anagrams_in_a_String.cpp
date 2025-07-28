#include<bits/stdc++.h>
using namespace std;


// class Solution{
//     public:
//     vector<int> findAnagrams(string s, string p){
//         vector<int> hash;
//         for(char ch : p){
//             hash[ch]++;
//         }

//         int left = 0, right = 0;
//         int required = p.size();
//         while(right < s.size()){
//             char rightChar = s[right];

//         }
//     }
// };

int main(){
    string s = "cbaebabacd", p ="abc" ; 
    // cin >> s >> p;
    vector<int> hash(128, 0);
    for(char ch : p){
        hash[ch]++;
    }

    int left = 0, right = 0;
    int required = p.size();
    int len = 0;
    vector<int > ans;
    while(right < s.size()){

        char rightChar = s[right];
        hash[rightChar]--;
        if(hash[rightChar] >= 0){
            required--;
        }
        right++;
        
        while(required == 0 ){
            if(right - left == p.size()){
                ans.push_back(left);
            }
            char leftChar = s[left];
            hash[leftChar]++;
            if(hash[leftChar] > 0){
                required++;
            } 
            left++;
        }
    }
    // cout << endl;
    for(auto u : ans){
        cout << u << ' ';
    }
    return 0;
}