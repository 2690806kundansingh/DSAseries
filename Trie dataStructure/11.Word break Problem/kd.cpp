#include <iostream>
using namespace std;

struct TrieNode {
    char data;
    TrieNode* child[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

void add(TrieNode* root, string s) {
    TrieNode* curr = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (curr->child[index] == NULL) {
            curr->child[index] = new TrieNode(s[i]);
        }
        curr = curr->child[index];
    }
    curr->isTerminal = true; // Mark end of word
}

bool search(TrieNode* root, string s) {
    TrieNode* curr = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (curr->child[index] == NULL) {
            return false;
        }
        curr = curr->child[index];
    }
    return curr->isTerminal;
}

bool wordBreakUtil(TrieNode* root, string s) {
    if (s.length() == 0) return true;

    for (int i = 0; i < s.length(); i++) {
        string prefix = s.substr(0, i + 1);
        if (search(root, prefix) && wordBreakUtil(root, s.substr(i + 1))) {
            return true;
        }
    }
    return false;
}
int main() {
    TrieNode* root = new TrieNode('\0');
    string dictionary[] = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);

    for (int i = 0; i < n; i++) {
        add(root, dictionary[i]);
    }

    string test = "ilikeicecream";
    if (wordBreakUtil(root, test)) {
        cout << "Word can be broken into dictionary words.\n";
    } else {
        cout << "Word cannot be broken.\n";
    }

    return 0;
}
