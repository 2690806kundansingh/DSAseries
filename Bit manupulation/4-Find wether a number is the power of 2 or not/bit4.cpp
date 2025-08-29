#include<iostream>
using namespace std;

class Solution{
    public:
    bool isPowerOftwo(long long n){
        //base case
        if(n == 0)
          return false;
        if((n & (n-1)) == 0)
           return true;
        return false;     
    }
};
int main(){
    Solution obj;

    int n = 2;
    int result = obj.isPowerOftwo(n);
    if(result){
        cout<<"It is the power of 2 :";
    }
    else{
        cout<<"It is not power of 2 :";
    }
    return 0;

}