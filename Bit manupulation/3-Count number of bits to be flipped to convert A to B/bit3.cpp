#include<iostream>
using namespace std;

class Solution{
    public:
    int countBitsFlip(int a,int b){
        int val = a ^ b;
        int count= 0;
        while(val){
            if(val & 1){
                count++;
            }
            val = val >> 1;
        }
        return count;
    }
};
int main(){

    Solution obj;

    int a = 20;
    int b = 25;

    int result = obj.countBitsFlip(a,b);
    cout<<"The flip count is :"<<result <<endl;
    return 0;
}