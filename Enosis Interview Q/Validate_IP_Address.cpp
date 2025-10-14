/*
    Problem Link : https://leetcode.com/problems/validate-ip-address/description/
    Problem Name : Validate IP Address
    Difficulty : Medium

    Date : 13th october 2025

    Company Tag : Enosis solutions(For Fresher SWE)

===========================================================================================

    Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid 
    IPv6 address or "Neither" if IP is not a correct IP of any type.

    A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot 
    contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses 
    while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

    A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

    1 <= xi.length <= 4
    xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and 
    upper-case English letters ('A' to 'F').
    Leading zeros are allowed in xi.
    For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" 
    are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and 
    "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

    

    Example 1:

    Input: queryIP = "172.16.254.1"
    Output: "IPv4"
    Explanation: This is a valid IPv4 address, return "IPv4".
    Example 2:

    Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
    Output: "IPv6"
    Explanation: This is a valid IPv6 address, return "IPv6".
    Example 3:

    Input: queryIP = "256.256.256.256"
    Output: "Neither"
    Explanation: This is neither a IPv4 address nor a IPv6 address.
    

    Constraints:

    queryIP consists only of English letters, digits and the characters '.' and ':'.


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stringToInt(string s){
        int num = 0;
        for(int i=0; i<s.size(); i++){
            num = num * 10 + s[i] - '0';
        }
        return num;
    }

    string validIPAddress(string queryIP) {
        int v4 = false, v6 = false;
        int dot = 0, colon = 0;
        for(int i=0; i<queryIP.size(); i++){
            if(queryIP[i] == '.'){
                v4 = true;
                dot++;
            }
            else if(queryIP[i] == ':'){
                v6 = true;
                colon++;
            }
        }
        if((v4 and v6) || (dot != 3 && colon == 0) || (dot == 0 && colon != 7)){
            return "Neither";
        }
        vector<string> ipv4, ipv6;
        if(v4){
            string temp = "";
            for(auto ch : queryIP){
                if(ch != '.'){
                    temp += ch;
                }
                else if(ch == '.'){
                    if(temp.size())ipv4.push_back(temp);
                    temp = "";
                }
            }
            if(temp.size())ipv4.push_back(temp);
        }
        
        else if(v6){
            string temp = "";
            for(auto ch : queryIP){
                if(ch != ':'){
                    temp += ch;
                }
                else if(ch == ':'){
                    if(temp.size())ipv6.push_back(temp);
                    temp = "";
                }
            }
            if(temp.size())ipv6.push_back(temp);
        }
        if((ipv4.size() && ipv4.size() != 4) || (ipv6.size() && ipv6.size() != 8)){
            return "Neither";
        }

        string ans = "";
        if(v4){
            for(auto s : ipv4){
                bool invalid = false;
                for(int i=0; i<s.size(); i++){
                    if((s[i] >= 'a' and s[i]<='z') || (s[i] >= 'A' and s[i]<='Z')){
                        invalid = true;
                        ans = "Neither";
                        break;
                    }
                }
                if(invalid)break;
               
                if(s.size() <= 3 && stringToInt(s) > 255 ){
                    ans ="Neither";
                    break;
                }
                else if(s.size()>3 || (s.size()>1 && s[0] == '0')){
                   ans+="Neither";
                   break;
                }
            }
            if(ans.size() == 0 && ipv4.size()) ans = "IPv4";
        }
        else if(v6){ 
            
            for(auto s : ipv6){
                if(s.size()>4){
                    ans = "Neither";
                    break;
                }
                bool invalid = false;
                for(auto t : s){
                    if(!(t >= '0' && t<='9') && !(t >= 'a' && t<='f') && !(t >= 'A' && t <='F')){
                        invalid = true;
                        ans = "Neither";
                        break;
                    }
                }
                if(invalid)break;
                
            }
            if(ans.size() == 0 && ipv6.size()) ans = "IPv6";
        }
        
        return ans.size() == 0 ? "Neither" : ans ;
    }
};