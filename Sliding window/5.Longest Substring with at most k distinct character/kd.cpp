#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestSubstringwithkDistinct(string s,int k){
        unordered_map<char,int>mp;
        int l = 0;
        int r = 0;
        int maxlen = 0;

        while(r < s.size()){
            mp[s[r]]++;

            if(mp.size() > k){
                mp[s[l]]--;

                if(mp[s[r]] == 0){
                    mp.erase(mp[s[l]]);
                }
                l++;
            }
            // if(mp.size() <= k){
            //     maxlen = max(maxlen,r-l+1);
            //     r++;
            // }
            maxlen = max(maxlen, r - l + 1);
            r++; // Expand window by moving right pointer
        }
        return maxlen;
    }
};
int main(){
    Solution obj;
    string s = "aaabbccd";
    int k = 2;
    cout<<"The longest Substring with k distinct :"<<obj.longestSubstringwithkDistinct(s,k);
    return 0;
}