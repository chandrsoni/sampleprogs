// TODO: memoize sumExists.
bool sumExists(vector<int> num, long long int sum){
    if(num.size() == 1){
        return num[0] == sum;
    }
    for(int i = 0; i< num.size(); i++){
        int numi = num[i];
        vector<int> numCopy(num.begin(), num.end());
        numCopy.erase(numCopy.begin() + i);
        if(sumExists(numCopy, sum)){return true;}
        if(sumExists(numCopy, sum-numi)){return true;}
    }
    return false;
}

bool canPartition(vector<int>& num){
    long long int sum = 0;
    for(int i = 0; i < num.size(); i++){
        sum +=num[i];
    }
    if(sum%2 != 0){return false;}
    sum = sum/2;
    return sumExists(num, sum);
}

int main() {
    vector<int> num{1,2,3};
    cout << (canPartition(num)? "true": "false") << endl;
    num.push_back(5);
    cout << (canPartition(num)? "true": "false") << endl;
    num.push_back(7);
    cout << (canPartition(num)? "true": "false") << endl;
    num.push_back(6);
    cout << (canPartition(num)? "true": "false") << endl;
    std::cout << "Hello World!\n";
}