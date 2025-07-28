/*
    Problem Link    : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
    Problem Name    : 208. Implement Trie (Prefix Tree)
    Difficulty      : Medium
    Time Complexity : 
    Space Complexity: 

    Author : Ali Hossain
    Date : 19-05-2025

========================================================================================================

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

#include<bits/stdc++.h>
using namespace std;



struct Node{
    Node* links[26] ;
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL); // not null means chararcter ache refernce e
    }
    // and if character na pawa jay tahole insert korbo
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    // string er end k true korte
    bool setEnd(){
        flag = true;
        return flag;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    private : Node* root ;
public:
    Trie() {
        // creat root node 1st to traverse
        root = new Node();
    }
    /*
        Time Complexity : O(string len)
        Space Complexity: O(1) only 26 length is used
    */
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            // move to reference trie
            node = node->get(word[i]);
        }
        // make sure character availability by setting end = treu after traversing full string 
        node->setEnd();
    }
    /*
        Time Complexity : O(string len)
        Space Complexity: O(1) only 26 length is used
    */
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return (node->isEnd() == true);
    }
    
    /*
        Time Complexity : O(string len)
        Space Complexity: O(1) only 26 length is used
    */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            // move to next refernce trie
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
