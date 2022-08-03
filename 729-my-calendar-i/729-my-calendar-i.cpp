class MyCalendar {
public:
    unordered_map<int, int> log;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // sort(log.begin(), log.end());
        // for(int i =0; i < log.size(); i++){
        //     if(log[i][1] <= start || log[i][0] >= end )
        //         continue;
        //     return false;
        // }
        // log.push_back(vector<int>({start, end}));
        // return true;  
        
        for(auto [s, e] : log){
            if( !(s >= end || e <= start) )
                return false;
        }
        log[start] = end;
        return true;
        
        
        
       
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */