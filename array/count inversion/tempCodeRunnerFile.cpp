#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1, inv_count = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv_count += (mid - i + 1); // Count inversions
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return inv_count;
    }

    int mergeSortAndCount(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;
        
        int mid = (left + right) / 2;
        int inv_count = 0;

        inv_count += mergeSortAndCount(arr, left, mid);
        inv_count += mergeSortAndCount(arr, mid + 1, right);
        inv_count += mergeAndCount(arr, left, mid, right);

        return inv_count;
    }

    int countInversions(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {8, 4, 2, 1};
    Solution solution;
    cout << "Inversion Count: " << solution.countInversions(arr) << endl;
    return 0;
}




