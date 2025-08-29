#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch; // Assign the character to data
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: word will be in lowercase letters
        int index = word[0] - 'a';
        TrieNode *child;

        // Check if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // If absent, create new TrieNode
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call for the next part of the word
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];

            prefix.push_back(lastch);

            // Check for lastch in the Trie
            TrieNode *curr = prev->children[lastch - 'a'];

            // If not found, break out of loop
            if (curr == NULL) {
                break;
            }

            // If found, collect suggestions
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    // Create a Trie
    Trie *t = new Trie();

    // Insert all contacts into Trie
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    // Return the suggestions based on query string
    return t->getSuggestions(queryStr);
}

int main() {
    vector<string> contactList = {"alice", "bob", "alicea", "alicia", "alex"};
    string queryStr = "ali";

    vector<vector<string>> suggestions = phoneDirectory(contactList, queryStr);

    for (int i = 0; i < suggestions.size(); i++) {
        cout << "Suggestions for '" << queryStr.substr(0, i + 1) << "': ";
        for (string s : suggestions[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}




// #include<iostream>
// #include<vector>
// using namespace std;

// class TrieNode{
//     public:
//     char data;
//     TrieNode*children[26];
//     bool isTerminal;

//     TrieNode(char ch){
//         char ch;
//         for(int i =0;i<26;i++){
//             children[i] = NULL;
//         }
//         isTerminal = false;
//     }
// };
// class Trie{
//     public:
//     TrieNode*root;
//     Trie(){
//         root = new TrieNode('\0');
//     }

//     void insertUtil(TrieNode*root,string word){
//         //base case
//         if(word.length() == 0){
//             root->isTerminal = true;
//             return;
//         }

//         //assumption word will be in caps
//         int index = word[0] - 'a';
//         TrieNode*child;

//         //present
//         if(root->children[index] != NULL){
//             child = root->children[index];
//         }
//         else{
//             //absent
//             child =  new TrieNode(word[0]);
//             root->children[index] = child;
//         }
//         //recursion call
//         insertUtil(child,word.substr(1));
//     }

//     void insertWord(string word){
//         insertUtil(root,word);
//     }

//     void printSuggestions(TrieNode*curr,vector<string>&temp,string prefix){
//         if(curr->isTerminal){
//             temp.push_back(prefix);
//         }

//         for(char ch = 'a';ch<= 'z';ch++){
//             TrieNode *next = curr->children[ch-'a'];

//             if(next != NULL){
//                 prefix.push_back(ch);
//                 printSuggestions(next,temp,prefix);
//                 prefix.pop_back();
//             }
//         }
//     }

//     vector<vector<string>>getSuggestions(string str){
//         TrieNode*prev = root;
//         vector<vector<string>>output;
//         string prefix = "";

//         for(int i =0 ;i<str.length();i++){
//             char lastch = str[i];

//             prefix.push_back(lastch);

//             //check for lastch
//             TrieNode*curr = prev->children[lastch - 'a'];

//             //if not found
//             if(curr == NULL){
//                 break;
//             }
//             // if found
//             vector<string>temp;
//             printSuggestions(curr,temp,prefix);

//             output.push_back(temp);
//             temp.clear();
//             prev = curr;
//         }
//         return output;
//     }
// };



// vector<vector<string>> phoneDirectry(vector<string>&contactList,string &queryStr){

//     //creation of trie
//     Trie *t = new Trie();

//     //insert all the contact in trie
//     for(int i =0; i<contactList.size() ; i++){
//         string str = contactList[i];
//         t->insertWord(str);
//     }
//     //return ans
//     return t->getSuggestions(queryStr);
// }




// Algorithm Steps
// Step 1: Construct the Trie
// Create a TrieNode structure with:

// A children array of size 26 (for lowercase English letters).

// A boolean flag isTerminal to mark the end of a valid word.

// Insert all contact names into the Trie.

// Insertion of a Word in Trie:
// Start from the root node.

// Traverse each character in the word:

// Compute the index using index = character - 'a'.

// If the character node does not exist, create a new TrieNode.

// Move to the next TrieNode.

// Once the full word is inserted, mark the last node as terminal (isTerminal = true).

// Time Complexity:

// Each insertion takes O(L) time (L = length of the word).

// For N words, total insertion time is O(N * L).



// Step 2: Search for the Query String
// Traverse through the Trie character by character for the given queryStr.

// If at any point the character is missing in the Trie, terminate the search.

// Otherwise, collect all words that match the prefix.

// Time Complexity:

// Searching each character takes O(L) time.

// If all words match, worst case is O(N * L).




// Step 3: Generate Suggestions
// Once the prefix is found in the Trie, use DFS (Depth-First Search) to collect all words starting from that node.

// Maintain a temporary list (temp) to store matching words.

// Print Suggestions Using DFS:
// If the current TrieNode is terminal (isTerminal == true), add it to temp.

// Iterate through all possible child nodes ('a' to 'z').

// If a child exists, recursively call the function to continue forming words.

// Time Complexity:

// In worst case, it explores all nodes in the Trie: O(N * L).




// Step 4: Return the Suggestions
// The result is stored in a vector of vectors, where:

// Each index i contains a list of words that match the prefix of length i+1.