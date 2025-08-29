#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>&arr,int n){
    string ans = "";
    //traversing all the first character of string
    for(int i =0;i<arr[0].length(); i++){
        char ch = arr[0][i];
        bool match = true;

        //if comparing the character the rest of the string
        for(int j =1; j<n;j++){
            //if not match
            if(arr[j].size() <= i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false)
           break;
        else
           ans.push_back(ch);   
    }
    return ans;
}
int main(){
    vector<string>arr = {"flower","flow","flight"};
    int n = arr.size();
    cout<<"The longest common prefix :"<<longestCommonPrefix(arr,n);
    return 0;
}
