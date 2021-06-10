class MyCalendar {
public:
    set<pair<int, int>> events;
    
    bool book(int start, int end) {
        auto next = events.upper_bound({start, end});
        if(next != events.end() && next->first < end) return false;
        if(next != events.begin() && (--next)->second > start) return false;
        events.insert({start, end});
        return true;
    }
};

//OR

class MyCalendar {
public:
    vector<pair<int, int>> events;

    bool book(int start, int end) {
        for(auto i : events){
            int s = i.first;
            int e = i.second;
            
            if(e <= start || s >= end)
                continue;
            
            return false;
        }
        events.push_back({start, end});
        return true;
    }
};
