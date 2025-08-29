#include<iostream>
using namespace std;

void Heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for(int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    // Step 2: Swap and Heapify
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      // Move max to end
        Heapify(arr, i, 0);        // Re-heapify reduced heap
    }
}

int main() {
    int arr[] = {54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, n);

    cout << "The heap sort is: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
