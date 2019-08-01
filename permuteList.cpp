    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0){
            result.push_back(vector<int>());
            return result;
        }
        
        for(int i = 0; i < nums.size(); i++){
            int removedNum = nums[i];
            nums.erase(nums.begin() + i);
            vector<vector<int>> permuteSubset = permute(nums);
            for(int j = 0; j < permuteSubset.size(); j++){
                permuteSubset[j].insert(permuteSubset[j].begin(), removedNum);
            }
            result.insert(result.begin(), permuteSubset.begin(), permuteSubset.end());
            nums.insert(nums.begin() + i, removedNum);
        }
        
        return result;
    }

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> permuteResult = permute(nums);
    for(int i =0; i < permuteResult.size(); i++){
        for(int j = 0; j < permuteResult[i].size(); j++){
            cout << permuteResult[i][j] <<",";
        }
        cout << endl;
    }
    std::cout << "Hello World!\n";
}