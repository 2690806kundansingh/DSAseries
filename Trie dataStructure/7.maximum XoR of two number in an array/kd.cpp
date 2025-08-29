// maximum Xor of two number in an array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    struct TrieNode{
        TrieNode*left;
        TrieNode*right;
    };

    void insert(TrieNode*root,int &nums){
        TrieNode*pcrawl = root ;
        for(int i =31; i>= 0; i--){
            int bit = (nums >> i)&1;
            if(bit ==0){
                if(pcrawl->left == NULL){
                    pcrawl->left = new TrieNode();
                    pcrawl = pcrawl->left;
                }
                pcrawl = pcrawl->right;
            }
            else{
                if(pcrawl->right == NULL){
                    pcrawl->right = new TrieNode();
                    pcrawl = pcrawl->right;
                }
                pcrawl = pcrawl->left;
            }
        }
    }

    int findmax(TrieNode*root,int &nums){
        int maxXor = 0;
        TrieNode*pcrawl = root;
        for(int i =31; i>= 0; i--){
            int bit = (nums >> i)&1;
            if(bit == 1){
                if(pcrawl->left != NULL){
                    maxXor += (1 << i);
                    pcrawl = pcrawl->left;
                }
                else{
                    pcrawl = pcrawl->right;
                }
            }
            else{
                if(pcrawl->right != NULL){
                    maxXor += (1 << i);
                    pcrawl = pcrawl->right;
                }
                else{
                    pcrawl = pcrawl->left;
                }
            }
        }
        return maxXor;
    }
    int findMaximumXor(vector<int>&nums){
        TrieNode*root = new TrieNode();
        for(int &num:nums){
            insert(root,num);
        }
        int maxresult = 0;
        for(int i = 0 ;i<nums.size();i++){
            int temp = findmax(root,nums[i]);
            maxresult = max(maxresult,temp);
        }
        return maxresult;
    }
};

int main(){
    vector<int>nums = {9,8,7,5,4};
    Solution sol;
    int result = sol.findMaximumXor(nums);
    cout << "Maximum XOR of two numbers in the array: " << result << endl;
    return 0;
}