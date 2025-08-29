#include<iostream>
using namespace std;

class Solution{
    public:
    int findPostion(int n){
        if((n & (n-1)) == 0){
            int count = 0;
            while(n){
                count++;
                n = n >> 1;
            }
            return count;
        }
        else{
            return -1;
        }
    }
};

int main(){
    Solution obj;
    int n = 12;
    int result = obj.findPostion(n);
    cout<< " the position of set bit is :"<<result <<endl;
    return 0;

}