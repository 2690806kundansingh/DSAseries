#include<iostream>
#include<limits.h>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>>& a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1: Create a min heap for the first element of each row
    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    // Process the min heap
    while (!minHeap.empty()) {
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // Update range if smaller
        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // If next element exists in the same row
        if (temp->col + 1 < n) {
            int nextElement = a[temp->row][temp->col + 1];
            maxi = max(maxi, nextElement);
            minHeap.push(new node(nextElement, temp->row, temp->col + 1));
        } else {
            break;
        }
    }

    return (end - start + 1);
}

int main() {
    vector<vector<int>> arr = {
        {1, 5, 8},
        {4, 12, 15},
        {7, 8, 10}
    };

    int k = arr.size();     // Number of rows
    int n = arr[0].size();  // Number of columns

    int lengthOfSmallestRange = kSorted(arr, k, n);
    cout << "Length of the smallest range: " << lengthOfSmallestRange << endl;

    return 0;
}
