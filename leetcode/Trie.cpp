#include <iostream>
#include <string>

using namespace std;

/*
 Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
*/

class TrieNode {
    
    bool leaf;
public:
    // Initialize your data structure here.
    TrieNode *next[26];
    TrieNode() {
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
        leaf = false;
    }
    
    bool isLeaf(){
        return leaf;
    }
    
    void setLeaf(){
        leaf = true;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        int len = s.length();
        TrieNode *cur = root;
        for(int i=0;i<len;i++){
            if(cur->next[s[i]-'a'] == NULL){
                cur->next[s[i]-'a'] = new TrieNode();
            }
            cur = cur->next[s[i]-'a'];
        }
        cur->setLeaf();
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int len = key.length();
        TrieNode *cur = root;
        for(int i=0;i<len;i++){
            if(cur->next[key[i]-'a'] == NULL){
                return false;
            }
            cur = cur->next[key[i]-'a'];
        }
        if(cur->isLeaf())
            return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode *cur = root;
        for(int i=0;i<len;i++){
            if(cur->next[prefix[i]-'a'] == NULL){
                return false;
            }
            cur = cur->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){

    Trie t;
    string s = "somestring";
    string k1 = "some";
    t.insert(s);
    cout<<t.search(s);
    cout<<t.search(k1);
    cout<<t.startsWith(k1);


    return 0;
}