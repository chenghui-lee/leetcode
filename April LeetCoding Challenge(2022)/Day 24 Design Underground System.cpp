class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> tripCost; // tripid, [total cost, num of trip]
    unordered_map<int, pair<string, int>> checkins; // id, [station_from, departTime]
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& tmp = checkins[id];
        string route = tmp.first + "_" + stationName;
        tripCost[route].first += t - tmp.second;
        tripCost[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto& tmp = tripCost[route];
        return (double) tmp.first / tmp.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
