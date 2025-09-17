#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
    string reverseString(string s){
        string ans = "";
        string temp = "";

        for(int i = s.length()-1;i>=0;i--){
            if(s[i] == '.'){
                reverse(temp.begin(),temp.end());
                ans = ans + temp;
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(),temp.end());
        ans = ans + temp;
        return ans;
    }
};