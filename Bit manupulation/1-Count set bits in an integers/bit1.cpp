#include<iostream>
using namespace std;

class Solution{
    public:
    int setBits(int N){
        int count = 0;
        while(N){
            int bit = N & 1;

            if(bit)
              count++;
            N = N >> 1;  
        }
        return count;
    }
};
int main(){
    int N;
    cout<<"Enter a number";
    cin>> N;

    Solution obj;
    int result = obj.setBits(N);

    cout<< "Number of set bits in " << N <<"is"<<result <<endl;
    return 0;
}