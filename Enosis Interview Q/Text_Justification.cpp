/*
    Problem Link : https://leetcode.com/problems/text-justification/description/
    Problem Name : Text Justification
    Difficulty : Hard

    Date : 1st october 2025

    Company Tag : Enosis solutions(For Fresher SWE)

===========================================================================================

    Given an array of strings words and a width maxWidth, format the text such that each 
    line has exactly maxWidth characters and is fully (left and right) justified.

    You should pack your words in a greedy approach; that is, pack as many words as you 
    can in each line. Pad extra spaces ' ' when necessary so that each line has exactly 
    maxWidth characters.

    Extra spaces between words should be distributed as evenly as possible. If the number 
    of spaces on a line does not divide evenly between words, the empty slots on the left 
    will be assigned more spaces than the slots on the right.

    For the last line of text, it should be left-justified, and no extra space is inserted 
    between words.

    Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.
    

    Example 1:

    Input: words = ["This", "is", "an", "example", "of", "text", "justification."], 
    maxWidth = 16
    Output:
    [
    "This    is    an",
    "example  of text",
    "justification.  "
    ]
    Example 2:

    Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
    Output:
    [
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
    ]
    Explanation: Note that the last line is "shall be    " instead of "shall     be", 
    because the last line must be left-justified instead of fully-justified.

    Note that the second line is also left-justified because it contains only one word.
    Example 3:

    Input: words = ["Science","is","what","we","understand","well","enough","to",
    "explain","to","a","computer.","Art","is","everything","else","we","do"], 
    maxWidth = 20
    Output:
    [
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
    ]
    

    Constraints:

    1 <= words.length <= 300
    1 <= words[i].length <= 20
    words[i] consists of only English letters and symbols.
    1 <= maxWidth <= 100
    words[i].length <= maxWidth



*/

#include<bits/stdc++.h>
using namespace std;

/*

    Time Complexity: O(n)
    Space Complexity: O(k×m)
    এখানে k হলো আউটপুটে মোট লাইনের সংখ্যা এবং m হলো maxWidth।
    
*/

class Solution {
public:
    int MAX_WIDTH;
    string findLine(int i, int j, int spaceInEachGap, int extraSpace, vector<string> &words){
        string line = "";
        for(int k = i; k<j; k++){
            line += words[k];
            if(k == j-1){
                continue;
            }
            for(int z = 0; z<spaceInEachGap; z++){
                line += " ";
            }
            // extraSpace থাকলে বামদিক থেকে একে একে বাড়তি space দেওয়া হয়।
            if(extraSpace > 0){
                line += " ";
                extraSpace--;
            }
        }

        // লুপটি নিশ্চিত করে যে লাইনের মোট দৈর্ঘ্য maxWidth-এর সমান হয়। 
        // এটি মূলত শেষ লাইনের জন্য বা যে লাইনে একটি মাত্র শব্দ আছে, তার শেষে প্রয়োজনীয় 
        // space যোগ করে।
        while(line.size() < MAX_WIDTH){
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        MAX_WIDTH = maxWidth ;
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while(i < n){
            int lettersCount = words[i].size();
            int j = i+1;
            string line = words[i];
            int gap = 0;
            while(j < n && words[j].size() + 1 + gap + lettersCount <= maxWidth){
                lettersCount += words[j].size();
                gap++;
                j++;
            }
            int totalSpace = maxWidth - lettersCount;
            int spaceInEachGap = (gap == 0 ? 0 : totalSpace/gap);

            //মানে কিছু জায়গায় ১টা extra space দিতে হবে, যাতে পুরোপুরি maxWidth হয়)।
            int extraSpace = (gap == 0 ? 0 : totalSpace % gap);
            
            //যদি j == n (মানে শেষ লাইন), তখন সব শব্দ শুধু ১টা space দিয়ে লিখব, বাকিটা শেষে space দিয়ে পূরণ করব।
            if(j == n){
                spaceInEachGap = 1;
                extraSpace = 0;
            }
            ans.push_back(findLine(i, j, spaceInEachGap, extraSpace, words));
            i = j;
        }
        return ans;
    }
};