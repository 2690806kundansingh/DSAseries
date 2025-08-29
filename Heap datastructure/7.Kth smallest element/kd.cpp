#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int kthsmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;

        // Step 1: Push first k elements into max-heap
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // Step 2: Compare remaining elements with top of heap
        for (int i = k; i <= r; i++) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // The top of the max-heap is the kth smallest element
        return pq.top();
    }
};

int main() {
    Solution s;
    int arr[] = {7, 10, 4, 20, 15};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = s.kthsmallest(arr, 0, n - 1, k);
    cout << "The " << k << "th smallest element is: " << result << endl;
    return 0;
}
