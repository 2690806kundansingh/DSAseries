#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    void insert(int x, TrieNode* root) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int query(int x, TrieNode* root) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->children[1 - bit] != nullptr) {
                maxXor |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

vector<int> maximumXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int m = queries.size();
    
    vector<int> ans(m, -1);
    vector<vector<int>> queriesIndexed;
    
    for (int i = 0; i < m; i++) {
        queriesIndexed.push_back({queries[i][0], queries[i][1], i});
    }
    
    sort(nums.begin(), nums.end());
    sort(queriesIndexed.begin(), queriesIndexed.end(), comp);
    
    int i = 0;
    TrieNode* root = new TrieNode();
    Solution sol;
    
    for (auto& q : queriesIndexed) {
        int x = q[0], limit = q[1], index = q[2];
        while (i < n && nums[i] <= limit) {
            sol.insert(nums[i], root);
            i++;
        }
        if (i > 0) {
            ans[index] = sol.query(x, root);
        }
    }
    
    return ans;
}

int main() {
    vector<int> nums = {5, 2, 8, 10};
    vector<vector<int>> queries = {{3, 10}, {5, 8}, {2, 6}};
    vector<int> result = maximumXor(nums, queries);
    
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
