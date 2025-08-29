#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int freq;
    unordered_map<char, TrieNode*> child;

    TrieNode() {
        freq = 0;
    }
};

void insert(const string& s, TrieNode* root) {
    TrieNode* curr = root;
    for (char c : s) {
        if (curr->child.find(c) == curr->child.end())
            curr->child[c] = new TrieNode();
        curr = curr->child[c];
        curr->freq++;
    }
}

string buildPrefix(const string& s, TrieNode* root) {
    TrieNode* curr = root;
    string ans;
    for (char c : s) {
        curr = curr->child[c];
        ans += c;
        if (curr->freq == 1) break;
    }
    return ans;
}

class Solution {
public:
    vector<string> findPrefixes(string arr[], int n) {
        TrieNode* root = new TrieNode();
        vector<string> result;

        // Insert all words into the Trie
        for (int i = 0; i < n; i++) {
            insert(arr[i], root);
        }

        // Find shortest unique prefix for each word
        for (int i = 0; i < n; i++) {
            result.push_back(buildPrefix(arr[i], root));
        }

        return result;
    }
};




//submit on gfg
// #include <bits/stdc++.h>
// using namespace std;

// struct TrieNode {
//     int freq;
//     unordered_map<char, TrieNode*> child;

//     TrieNode() {
//         freq = 0;
//     }
// };

// void insert(const string& s, TrieNode* root) {
//     TrieNode* curr = root;
//     for (char c : s) {
//         if (curr->child.find(c) == curr->child.end())
//             curr->child[c] = new TrieNode();
//         curr = curr->child[c];
//         curr->freq++;
//     }
// }

// string buildPrefix(const string& s, TrieNode* root) {
//     TrieNode* curr = root;
//     string ans;
//     for (char c : s) {
//         curr = curr->child[c];
//         ans += c;
//         if (curr->freq == 1) break;
//     }
//     return ans;
// }

// class Solution {
// public:
//     vector<string> findPrefixes(string arr[], int n) {
//         TrieNode* root = new TrieNode();
//         vector<string> result;

//         // Insert all words into the Trie
//         for (int i = 0; i < n; i++) {
//             insert(arr[i], root);
//         }

//         // Find shortest unique prefix for each word
//         for (int i = 0; i < n; i++) {
//             result.push_back(buildPrefix(arr[i], root));
//         }

//         return result;
//     }
// };
