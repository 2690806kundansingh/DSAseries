#include<iostream>
using namespace std;

struct Node{
    Node*links[26];
    bool constainskey(char ch){
        return links[ch - 'a'];
    }
    void put(char ch ,Node*node){
        links[ch - 'a'] = node;
    }
    Node*get(char ch){
        return links [ch -'a'];
    }
};
int countDistinctsubstring(string &s){
    int cnt = 0;
    Node*root = new Node();
    for(int i =0; i<s.size();i++){
        Node*node = root;
        for(int j = i;j<s.size();j++){
            if(!node->constainskey(s[i])){
                cnt++;
                node->put(s[i],new Node());
            }
            node = node->get(s[i]);
        }
    }
    return cnt+1;
}




// class Solution {
//     public:
//         int countDistinct(string s) {
//             unordered_set<string_view> ss;
//             int n = s.size();
//             string_view t, v = s;
//             for (int i = 0; i < n; ++i) {
//                 for (int j = i + 1; j <= n; ++j) {
//                     t = v.substr(i, j - i);
//                     ss.insert(t);
//                 }
//             }
//             return ss.size();
//         }
//     };