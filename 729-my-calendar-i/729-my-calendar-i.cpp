class MyCalendar {
public:
    vector<vector<int>> temp;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(int i=0; i<temp.size(); i++){
            if(end>temp[i][0] && start<temp[i][1])return 0;
        }
        temp.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */