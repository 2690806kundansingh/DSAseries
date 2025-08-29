#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet{
    public:
    vector<int>vec;
    unordered_map<int,int>mp;

    RandomizedSet(){

    }
    bool insert(int val){
        if(mp.find(val) != mp.end())
          return false;

        vec.push_back(val);
        mp[val] = vec.size()-1;//finding the index in map
        return true;

    }
    bool remove(int val){
        if(mp.find(val) == mp.end())
            return false;
        
        int idx = mp[val];//access the index which we have to remove
        int lastElement = vec.back();
        vec.back() = val;

        vec[idx] = lastElement;
        mp[lastElement] = idx;

        vec.pop_back();
        mp.erase(val);
        return true;

    }
    int getRandom(){
        int n = vec.size();
        int randomIndex = rand()%n;//0.....(n-1)
        return vec[randomIndex];
    }
};
