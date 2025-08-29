// Use unordered_map<char, int> to store the last index of each character.

// Expand the window by moving the right pointer.

// If a character repeats, shrink the window by moving the left pointer.

// Update the maximum length whenever a new valid window is found.



#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int longestSubstring(string s){
        vector<int>hash(256,-1);
        int n = s.size();
        int l =0;
        int r=0;
        int maxLen = 0;

        while(r<n){
            if(hash[s[r]] != -1 && hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
            int len = r-l+1;
            maxLen = max(len,maxLen);

            hash[s[r]] = r; // store the last occurrence
            r++;
        }
        return maxLen;
    }
};
int main(){
    Solution obj;
    string  s = "cadbzabcd";
    cout<<"Longest Substring without repeating :"<<obj.longestSubstring(s);
    return 0;

}


