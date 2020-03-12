int maxProd(vector<string>& words){
    vector<int> charIndex(words.size(), 0);
    for(int i = 0; i < words.size(); i++){
        int index = 0;
        for(int j = 0; j < words[i].size(); j++){
            index |= 1 << (words[i][j] - 'a');
        }
        charIndex[i] = index;
    }
    
    int maxProduct = 0;
    
    for(int i = 0; i < words.size(); i++){
        for(int j = i+1; j < words.size(); j++){
            if((charIndex[i] & charIndex[j]) == 0){
                int prod = words[i].size() * words[j].size();
                maxProduct = max(maxProduct, prod);
            } 
        }
    }
    
    return maxProduct;
}

int main() {
    vector<string> words{"cat", "dog", "pull", "feed", "space"};
    cout << maxProd(words) << endl;
    std::cout << "Hello World!\n";
}
