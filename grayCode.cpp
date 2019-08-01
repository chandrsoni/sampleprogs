
vector<int> graycode(int n){
    if( n == 0){
        return vector<int>({0});
    }
    if(n == 1){
        return vector<int>({0,1});
    }
    vector<int> result;
    vector<int> grayOneLess = graycode(n-1);
    bool set = false;
    for(int i = 0; i < grayOneLess.size(); i++){
        if(set){
            result.push_back(grayOneLess[i] * 2 + 1);
            result.push_back(grayOneLess[i] * 2 + 0);
        }
        else{
            result.push_back(grayOneLess[i] * 2 + 0);
            result.push_back(grayOneLess[i] * 2 + 1);
        }
        set = !set;
    }
    
    return result;
}

int main() {
    
    vector<int> gray = graycode(0);
    for(int i = 0; i < gray.size(); i++){
        cout << gray[i] << endl;   
    }
    gray = graycode(1);
    for(int i = 0; i < gray.size(); i++){
        cout << gray[i] << endl;   
    }
    gray = graycode(2);
    for(int i = 0; i < gray.size(); i++){
        cout << gray[i] << endl;   
    }
    gray = graycode(3);
    for(int i = 0; i < gray.size(); i++){
        cout << gray[i] << endl;   
    }
    std::cout << "Hello World!\n";
}