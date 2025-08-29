#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    cout<<"Printing the queue using priority Queue :"<<endl;
    //max heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"element of the Top :"<<pq.top()<<endl;
    pq.pop();
    cout<<"element of the Top :"<<pq.top()<<endl;
    cout<<"Size of :"<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }


    //min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;


        minHeap.push(4);
        minHeap.push(2);
        minHeap.push(5);
        minHeap.push(3);

        cout<<"Element at the top :"<<minHeap.top()<<endl;
        minHeap.pop();
        cout<<"THe top of the element :"<<minHeap.top()<<endl;
    return 0;

}