#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    //cration map
    unordered_map<string,int>m;

    //insertion
    // 1.type
    pair<string,int>p = make_pair("babbar" , 3);
    m.insert(p);

    // 2.type
    pair<string,int>pair2("love",2);
    m.insert(pair2);

    //3.type
    m["mera"] = 2;
   
    //searching
    cout<<m["babbar"]<<endl;
    cout<<m.at("babbar") <<endl;

    cout<<m["unknown"] << endl;
    cout<<m.at("unknown")<<endl;

    //size
    cout<<m.size()<<endl;
    
    //to check presence
    cout<<m.count("babbar")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    // 1. acces the element in map
    for(auto i : m){
        cout<<i.first<<" " <<i.second<<endl;
    }
    // 2. iterator
    unordered_map<string,int>:: iterator it = m.begin();
    while(it != m.end()){
        cout<< it->first <<" " <<it->second << endl;
        it++;
    }


    return 0;
}