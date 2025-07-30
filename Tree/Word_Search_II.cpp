/*
    Problem Link    : https://leetcode.com/problems/word-search-ii/description/
    Problem Name    : 212. Word Search II
    Difficulty      : Hard
    Time Complexity : 
    Space Complexity: 

    Author : Ali Hossain
    Date : 21-05-2025

===================================================================================================

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

*/



// Solution approach : DFS + TRIE

#include<bits/stdc++.h>
using namespace std;

// solution 1

/*
    This "word search II" problem can be solved using another approach 
    but TRIE the most efficient data structure

    Step1 --> 
        to do this first need to insert the given word to TRIE .
    Step2 -->
        To search for given string we must traverse throuh board using DFS technique for each cell


        ✅ Time Complexity :
            N = board.size()
            M = board[0].size();
            K = words.size();
            L = max length string from words

            for insert word in Trie takes O(K)
            for dfs call it takes O(N * M * 4^L)

            therefore TC : O(N * M * 4^L)
    
        ✅ Total Space Complexity:
            W = number of words in words
            L_avg = average length of a word in words
            L_max = maximum length of a word

            O(S + W × L_avg + K)
            (Trie + matched words + call stack)

            therefore SC : O(W × L_avg)

*/

class Node{
    public:
    Node* children[26];
    bool endChar = false;

    bool containsKey(char ch){
        if(children[ch - 'a'] != NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void put(char ch, Node* node){
        children[ch - 'a'] = node;
    }
    Node* get(char ch){
        return children[ch - 'a'];
    }

};

class Trie{
    public:
    Node* root ;

    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                Node* newNode = new Node();
                node->put(ch, newNode);
            }
            node = node->get(ch);
        }
        node->endChar = true; 
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, Node* curr, string target, vector<string> &ans){
        if(i < 0 || j < 0 || i== n || j == m || !curr || board[i][j] == '$' || !curr->containsKey(board[i][j])) return;
        target += board[i][j];
        Node* check = curr->get(board[i][j]);
        // if I get my target word then pushing the targert string in ans.
        if(check->endChar){
            ans.push_back(target);
            // to avoid duplicate make last as false
            check->endChar = false;
        }
    
        char ch = board[i][j];
        board[i][j] = '$';
        dfs(i+1, j, n, m, board, curr->get(ch), target, ans); 
        dfs(i-1, j, n, m, board, curr->get(ch), target, ans);
        dfs(i, j+1, n, m, board, curr->get(ch), target, ans);
        dfs(i, j-1, n, m, board, curr->get(ch), target, ans);

        board[i][j] = ch;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        
        Trie trieDS;
        // insert the given string words to trie data structur
        for(auto word : words){
            trieDS.insert(word);
        }
        

        Node* node = trieDS.root;
        vector<string> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                string target ="";
                trieDS.dfs(i, j, n, m, board, node, target, ans);
            }
        }
        return ans;
    }
};


/*-------------------------------------- solution 1 Ends----------------------------------*/








/*-------------------------------------- solution 2 Starts ----------------------------------*/

/*
    Time complexity: O(m*n*max(length of a word in the array ‘words’)), 
                    m*n because DFS calls are made for every cell in search of a word, 
                    and max(length of a word in the array ‘words’) means that these many recursive calls can be made at max. 

    Space complexity: O(max(length of word in the array ‘words’) * size of the ‘words’ array), 
                    Reason is, that we can’t consider ans array in this calculation as it is 
                    a necessity of the problem and that the recursive stack space used in the search() 
                    is, max(length of a word in the array ‘words’), which is relatively smaller to this. 
                    So the trie data structure can consume the largest space in the worst case.

*/
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
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

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }

    void dfs(int i, int j, int n, int m, vector<string> &ans, vector<vector<char>>& board, Node* curr, string s){
       
        if(i == n || i < 0 || j==m || j<0 || board[i][j] == '$' || !curr || !curr->containsKey(board[i][j])) return;
    
        s += board[i][j];
        Node* check = curr->get(board[i][j]);
        if(check->flag){
            ans.push_back(s) ;
            check->flag = false;
        }

        char ch = board[i][j];
        board[i][j] = '$';
        dfs(i+1, j, n, m, ans, board, curr->get(ch), s);
        dfs(i-1, j, n, m, ans, board, curr->get(ch), s);
        dfs(i, j+1, n, m, ans, board, curr->get(ch), s);
        dfs(i, j-1, n, m, ans, board, curr->get(ch), s);

        board[i][j] = ch;
    }
};

class Solution {
public:
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Trie trie;
        vector<string> ans;
        
        for(int i=0; i<words.size(); i++){
            trie.insert(words[i]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                trie.dfs(i, j, n, m, ans, board, trie.root, "");
            }
        }
        return ans;
    }
};