void nextPermutation(vector<int>& nums) {
    if(nums.size() <= 1){
        return;
    }
    
    for(int i = nums.size() -1; i > 0; i--){
        if(nums[i-1] < nums[i]){
            int minIndex = i;
            for(int j = i; j < nums.size();j++){
                if(nums[j] > nums[i-1] && nums[j] < nums[minIndex]){
                    minIndex = j;
                }
            }
            swap(nums[i-1], nums[minIndex]);
            sort(nums.begin() + i, nums.end());
            return;
        }
    }
    
    reverse(nums.begin(), nums.end());
}

void print(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] <<", ";
    }
    cout << endl;
}

int main() {
    vector<int> swapingVec{1,2,3};
    print(swapingVec);
    nextPermutation(swapingVec);
    print(swapingVec);
    swapingVec = {1,3,2};
    print(swapingVec);
    nextPermutation(swapingVec);
    print(swapingVec);
    std::cout << "Hello World!\n";
}
