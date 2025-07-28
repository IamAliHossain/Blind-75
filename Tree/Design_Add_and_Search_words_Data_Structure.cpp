/*
    Problem Link    : https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
    Problem Name    : 211. Design Add and Search Words Data Structure
    Difficulty      : Medium
    Time Complexity : 
    Space Complexity: 

    Author : Ali Hossain
    Date : 20-05-2025

========================================================================================================

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.

*/


/*
    This is a problem of Trie data structure where string data is stored and retreived
    word may contain dot(.) ascii of dot = 46
*/
#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void insertWord(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* getWord(char ch){
        return links[ch - 'a'];
    }

    bool setEnd(){
        flag = true;
        return flag;
    }
    bool isEnd(){
        return flag;
    }

};

class WordDictionary {
    // Declare a root
    Node* root;

public:
    WordDictionary() {
        // Initialize root
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->insertWord(word[i], new Node());
            }
            node = node->getWord(word[i]);
        }
        node->setEnd();
    }

// at every level of search, we can take 26 different paths(assume every 26 places have their descendants)
// so 26 choices for every character in word that is 26^n total paths :)
// (note:- 26X26X26X26X........n-times = 26^n)

// TC : O(m * 26^n) m is total num of queries

    bool searchUtill(Node* node, string word){
        if(node == NULL) return false;
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(int j=0; j<26; j++){
                    if(searchUtill(node->links[j], word.substr(i+1)) == true){
                        return true;
                    }
                }
                return false;
            }
            else if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getWord(word[i]);
        }
        return (node->isEnd() == true);
    }
    bool search(string word) {
        return searchUtill(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */