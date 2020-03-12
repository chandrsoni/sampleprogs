template <class T>
void printVec(vector<T>& vec){
    for(T vecObj: vec){
        cout << vecObj << ", ";
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums) {
    long long int product = 1;
    for(int num: nums){
        product *= num;
    }
    
    vector<int> exceptSelf(nums.size(), product);   
    for(int i = 0; i < nums.size(); i++){
        exceptSelf[i] /= nums[i];
    }
    
    return exceptSelf;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums;
    int input;
    for(int i = 0; i < size; i++) {
        cin >> input;
        nums.push_back(input);
    }
    
    printVec<int>(nums);
    vector<int> products = productExceptSelf(nums);
    printVec<int>(products);
    
    std::cout << "Hello World!\n";
}
