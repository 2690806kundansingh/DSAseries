#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep, int n) {
        // sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int pt_no = 1;   // current platform needed
        int ans = 1;     // maximum platforms needed
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { 
                // new train has arrived before previous departs
                pt_no++;
                i++;
            } else { 
                // one train has departed
                pt_no--;
                j++;
            }
            ans = max(ans, pt_no); 
        }
        return ans;
    }
};
