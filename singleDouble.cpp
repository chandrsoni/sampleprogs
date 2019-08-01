int singleElement(vector<int> list){
    if(list.size() == 1){
        return list[0];
    }
    for(int i = 0; i < list.size()-1; i++){
        if(list[i] != list[++i]){
            return list[i-1];
        }
    }
    
    return list[list.size()-1];
}

int main() {
    vector<int> input;
    input.push_back(1);
    cout << singleElement(input) << endl;
    input.push_back(1);
    input.push_back(2);
    cout << singleElement(input) << endl;
    input.push_back(2);
    input.push_back(9);
    input.push_back(9);
    input.push_back(5);
    input.push_back(2);
    input.push_back(2);
    cout << singleElement(input) << endl;
    std::cout << "Hello World!\n";
}