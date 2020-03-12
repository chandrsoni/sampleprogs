
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(),1);
    int forwardProd = 1;
    for(int i = 0; i < nums.size(); i++){
        result[i] *= forwardProd;
        forwardProd *= nums[i];
    }
    forwardProd = 1;
    for(int i = nums.size()-1; i >= 0;i--){
        result[i] *= forwardProd;
        forwardProd *= nums[i];
    }
    
    return result;
}

int main() {
    vector<int> nums{1,2,3,4};
    vector<int> prod = productExceptSelf(nums);
    for(int i = 0; i < prod.size(); i++){
        cout << prod[i] << endl;
    }
    std::cout << "Hello World!\n";
}
