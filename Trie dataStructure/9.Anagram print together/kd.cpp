#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> Anagram(vector<int>& nums) {
        unordered_map<string, vector<int>> map;
        for (auto x : nums) {
            string temp = to_string(x);
            sort(temp.begin(), temp.end());
            map[temp].push_back(x);
        }

        vector<vector<int>> ans;
        for (auto &x : map) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {123, 321, 213, 456, 654};
    vector<vector<int>> result = s.Anagram(nums);

    for (auto group : result) {
        for (int num : group) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
