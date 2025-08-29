#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal = false;

    TrieNode(char ch){
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    TrieNode*root;
    public:

    Trie(){
        root = new TrieNode('\0');
    }
    bool prefixUtil(TrieNode*root,string word){
        //base case
        if(word.length() == 0){
            return true;
        }
        int index = word[0] -'a';
        TrieNode*child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        //recursive call
        return prefixUtil(child,word.substr(1));
    }

    bool startwith(string prefix){
        return prefixUtil(root,prefix);
    }
};