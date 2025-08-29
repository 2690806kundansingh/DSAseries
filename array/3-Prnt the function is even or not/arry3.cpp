#include<iostream>
using namespace std;

bool isEeven(int a){
    if(a&1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int num;
    cin>>num;
    if(isEeven(num)){
        cout<<"The number is even"<<endl;
    }
    else{
        cout<<"it is not even";
    }
    return 0;
}