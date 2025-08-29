#include<iostream>
#include<unordered_map>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIn_mp; // id -> {entry station, entry time}
    unordered_map<string, pair<int, int>> checkOut_mp; // route -> {totalTime, count}

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkIn_mp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string startStation = checkIn_mp[id].first;
        int entryTime = checkIn_mp[id].second;

        string route = startStation + "_" + stationName;
        int totalTime = t - entryTime;

        checkOut_mp[route].first += totalTime;
        checkOut_mp[route].second += 1;

        checkIn_mp.erase(id); // Remove after processing
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;

        auto &it = checkOut_mp[route];
        int totalTime = it.first;
        int count = it.second;

        return (double)totalTime / count;
    }
};
