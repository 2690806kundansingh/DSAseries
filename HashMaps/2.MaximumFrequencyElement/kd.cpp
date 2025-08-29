#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxFrequenctElement(vector<int>&nums){
        unordered_map<int,int>count;

        int maxFreq = 0;

        //count the frequency of each number and find maximum frequency

        for(auto i : nums){
            count[i]++;
            maxFreq = max(maxFreq,count[i]);
        }
        //count how many element have maximum frequency
        int maxAns = 0;
        for(auto & [key,value] : count){
            if(value == maxFreq){
                maxAns += value;
            }
        }
        return maxAns;
    }
};

int main(){
    Solution obj;
    vector<int>nums = {1,3,2,2,3,1,3};
    int result = obj.maxFrequenctElement(nums);
    cout<<"Sum of element with maximum frequency:"<<result << endl;
    return 0;
}