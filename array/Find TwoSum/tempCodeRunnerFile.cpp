return {}; // Return empty vector if no solution is found
    }
};

int main() {
    vector<int> nums = {2, 5, 6, 8, 11};
    Solution obj;
    
    vector<int> ans = obj.TwoSum(nums, 14);
    