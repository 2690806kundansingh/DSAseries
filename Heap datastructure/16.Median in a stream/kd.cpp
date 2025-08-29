#include<iostream>
#include<map>
#include<hash_map>
#include<queue>
#include<vector>

using namespace std;

class Solution{
    public:

    //signum function
    int signum(int a,int b){
        if(a==b)
           return 0;
        if(a > b)
           return 1;
        else 
          return -1;      
    }

    void callMedian(int element,priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini,int &median){
        switch(signum(maxi.size(),mini.size())){
            case 0: if(element > median){
                       mini.push(element);
                       median = mini.top();
                    }
                    else{
                        maxi.push(element);
                        median = maxi.top();
                    }
                    break;
            case 1: if(element > median){

                        mini.push(element);
                        median = (mini.top() + maxi.top())/2;
                    } 
                    else{
                        mini.push(maxi.top());
                        maxi.pop();
                        maxi.push(element);
                        median = (mini.top() + maxi.top())/2;
                    } 
                    break;
            case -1: if(element > median){
                        maxi.push(mini.top());
                        mini.top();
                        mini.push(element);
                        median = (mini.top() + maxi.top())/2;
                      }
                      else{
                        maxi.push(element);
                        median = (mini.top() + maxi.top())/2;
                      } 
                      break;       

        }
    }
    vector<int>FindMedian(vector<int>&arr ,int n){
        vector<int>ans;
        priority_queue<int>maxheap;
        priority_queue<int,vector<int>,greater<int>>minheap;
        int median = 0;

        for(int i = 0; i<n ;i++){
            callMedian(arr[i],maxheap,minheap,median);
           ans.push_back(median);
        }
        return ans;
    }
};
   


//accepted on leetcode 
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxheap; // Max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap for larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxheap.empty() || num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        // Rebalance the heaps
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size() == minheap.size()) {
            return (maxheap.top() + minheap.top()) / 2.0;
        } else {
            return maxheap.top(); // maxheap has the extra element
        }
    }
};
int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;  // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl;  // 2.0
    return 0;
}
