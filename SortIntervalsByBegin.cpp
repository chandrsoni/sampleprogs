class MyInterval{
    public:
    int start;
    int end;
    int id;
    MyInterval(int id, int start, int end){
        this->id = id;
        this->start = start;
        this->end = end;     
    }
};

bool sortIntervalByBegin(const MyInterval& left, const MyInterval& right){
    return left.start < right.start;
}

int main() {
    vector<MyInterval> intervals;
    intervals.push_back(MyInterval(1, 150, 300));
    intervals.push_back(MyInterval(2, 100, 200));
    intervals.push_back(MyInterval(3, 300, 350));
    sort(intervals.begin(), intervals.end(), sortIntervalByBegin);
    int endLimit = 0;
    for(int i = 0; i < intervals.size(); i++){
        endLimit = max(endLimit, intervals[i].end);
    }
    int currentLocation = intervals[0].start;
    int currentObjectIndex = 0;
    
}
