    int removeDuplicates(vector<int>& nums) {
        int current = nums[0], count = 1; 
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != current) {
                nums[count] = nums[i];
                current = nums[i];
                count++;
            }
        }
        
        return count;
    }

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout << removeDuplicates(nums) << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
}