#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> allPossibleSub(string s) {
        vector<string> ans;
        int n = pow(2, s.length());

        for (int i = 1; i < n; i++) {
            int x = i;  // iterate on number size which are in decimal
            int j = 0;  // iterate on string
            string count = "";

            while (x) {
                if (x & 1) {
                    count = count + s[j];
                }
                j++;
                x = x >> 1;
            }

            ans.push_back(count);  // push after building subsequence
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    vector<string> result = sol.allPossibleSub(s);

    for (auto &sub : result) {
        cout << sub << endl;
    }
    return 0;
}
