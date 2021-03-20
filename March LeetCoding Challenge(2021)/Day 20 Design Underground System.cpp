class UndergroundSystem {
public:
    map<int, pair<string, int>> in; // id, <stationame, time>
    map<pair<string, string>, vector<int>> time; // <from, to>, times taken for each trip
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto in_information = in[id];
        string from = in_information.first;
        int timeUsed = t - in_information.second;
        time[{from, stationName}].push_back(timeUsed);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto times = time[{startStation, endStation}];
        return (double) accumulate(times.begin(), times.end(), 0) / times.size();
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
