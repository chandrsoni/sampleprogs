int minimalNumberIndex(vector<int>& numbers){
    if(numbers.size() == 0){
        throw "invalid case of empty numbers array";
    }
    
    int minimal = numbers[0];
    int minimalIndex = 0;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] < minimal){
            minimal = numbers[i];
            minimalIndex = i;
        }
    }
    
    return minimalIndex;
}

int main() {
    int size;
    cin >> size;
    vector<int> numbers;
    int inputNumber;
    for(int i = 0; i < size; i++){
        cin >> inputNumber;
        numbers.push_back(inputNumber);
    }
    
    for(int i = 0; i < size; i++){
        int minimalIndex = minimalNumberIndex(numbers);
        cout << numbers[minimalIndex] << ", ";
        numbers.erase(numbers.begin() + minimalIndex);
    }
    cout << endl;
    std::cout << "Hello World!\n";
}
