#include <iostream>

using namespace std;


/*
 Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. 
A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first. 
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


class WordDictionary {
private:
    TrieNode* root;

public:
	WordDictionary(){
		 root = new TrieNode();
	}

    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
        TrieNode *cur = root;
        for(int i=0;i<len;i++){
        	if(cur->next[word[i]-'a']==NULL){
        		cur->next[word[i]-'a'] = new TrieNode();
        	}
        	cur = cur->next[word[i]-'a'];
        }
        cur->setLeaf();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.length();
        if(len == 0)
        	return true;
        TrieNode *cur = root;
        return search(word,cur);

    }

    bool search(string subword,TrieNode *cur){
    	int len = subword.length();
        if(len == 0)
        	return true;
        char c = subword[0];

	    if(c == '.'){
	    	bool found = false;
	        for(int i=0;i<26;i++){
	        	if(cur->next[i]!=NULL){
	        		if(len == 1){
	        			if(cur->next[i]->isLeaf()){
	        				found = true;
	        				break;
	        			}
	        		}else{

	        			found = search(subword.substr(1),cur->next[i]);
	        			if(found)
	        				break;
	        		}
	        	}
	        }

	        if(found)
	        	return true;
	        else
	        	return false;
	    }else{
	    	if(cur->next[c-'a']==NULL)
	    		return false;
	    	if(len == 1){
	    		if(cur->next[c-'a']->isLeaf())
	    			return true;
	    		else
	    			return false;
	    	}
	    	return search(subword.substr(1),cur->next[c-'a']);

	    }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main(){

	WordDictionary dict;

	dict.addWord("bad");
	dict.addWord("dad");
	dict.addWord("mad");
	cout<<dict.search("pad")<<endl;
	cout<<dict.search("bad")<<endl;
	cout<<dict.search(".ad")<<endl;
	cout<<dict.search("b..")<<endl;

	
	return 0;
}