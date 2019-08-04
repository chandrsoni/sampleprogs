
int maxCountWindow(vector<int>& timeData, int windowSize){
    if(timeData.size() < windowSize){
        // bad request.
        return -1;
    }
    int windowMax = 0;
    int currentWindow = 0;
    
    for(int i = 0; i < windowSize; i++){
        if(timeData[i] == 1)currentWindow++;
    }
    
    windowMax = currentWindow;
    
    for(int i = windowSize; i < timeData.size(); i++){
        int newData = timeData[i], oldData = timeData[i - windowSize];
        if(newData== 0 && oldData == 1){
            if(currentWindow > windowMax){
                windowMax = currentWindow;
            }
            currentWindow--;
        }
        if(newData != oldData){
            currentWindow++;
        }
    }
    
    return windowMax;
}

int main() {
    vector<int> timeData;
    timeData.push_back(0);
timeData.push_back( 1);
timeData.push_back( 1);
timeData.push_back( 0);
timeData.push_back( 1);
timeData.push_back( 1);
timeData.push_back( 0);
timeData.push_back( 1);
timeData.push_back( 0);
timeData.push_back( 0);
timeData.push_back( 0);

    int windowSize = 5;
    cout << maxCountWindow(timeData, windowSize) << endl;
    std::cout << "Hello World!\n";
}