using namespace std;

bool isZombied(vector<vector<bool>>& humanStatus) {
    for(int i = 0; i < humanStatus.size(); i++){
        for(int j = 0; j < humanStatus[i].size(); j++){
            if(!humanStatus[i][j]){
                return false;
            }
        }
    }
    
    return true;
}

void setZombieIndex(vector<vector<bool>>& humanStatus, int i, int j){
    if(i >=0 && i < humanStatus.size() && j >=0 && j < humanStatus[i].size()){
        humanStatus[i][j] = true;
    }
}

void dayPass(vector<vector<bool>>& humanStatus) {
    vector<vector<bool>> nextDayStatus(humanStatus);
    for( int i = 0; i < humanStatus.size(); i++) {
        for(int j = 0; j < humanStatus[i].size(); j++){
            if( humanStatus[i][j]){
                setZombieIndex(nextDayStatus, i-1, j);
                setZombieIndex(nextDayStatus, i+1, j);
                setZombieIndex(nextDayStatus, i, j-1);
                setZombieIndex(nextDayStatus, i, j+1);
            }
        }
    }
    
    humanStatus = nextDayStatus;
}

void printStatus(vector<vector<bool>>& humanStatus){
    for(int i = 0; i < humanStatus.size(); i++){
        for(int j = 0; j < humanStatus[i].size(); j++){
            cout << humanStatus[i][j] << ' ';
        }
        cout << endl;
    }
}

int daysForZombification(vector<vector<bool>>& humanStatus) {
    printStatus(humanStatus);
    if(isZombied(humanStatus)){
        cout << "zombied mate!" << endl;
        return 0;
    }
    dayPass(humanStatus);
    return daysForZombification(humanStatus) + 1;
};

int main() {
    int m, n;
    vector<vector<bool>> humanStatus;
    cin >> m >> n;
    if(m < 0 || n < 0){ 
        cerr << "invalid input!"<< endl; 
        return -1;
    }
    
    int input;    
    for(int i = 0; i < m; i++){
        humanStatus.push_back(vector<bool>());
        for(int j = 0; j < n; j++){
            cin >> input;
            humanStatus[i].push_back(input);
        }
    }
    
    cout << daysForZombification(humanStatus) << endl;
    std::cout << "Hello World!\n";
}
