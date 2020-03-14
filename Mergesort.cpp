
void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

void merge(vector<int>& array, int startIndex, int midIndex, int lastIndex){
    int leftCounter = startIndex, rightCounter = midIndex + 1;
    vector<int> sortedArray;
    while(leftCounter <= midIndex && rightCounter <= lastIndex){
        if(array[leftCounter] < array[rightCounter]){
            sortedArray.push_back(array[leftCounter++]);
        }
        else {
            sortedArray.push_back(array[rightCounter++]);
        }
    }
    while (leftCounter <= midIndex){
        sortedArray.push_back(array[leftCounter++]);
    }
    while (rightCounter <= lastIndex){
        sortedArray.push_back(array[rightCounter++]);
    }
    for(int i = startIndex; i <= lastIndex; i++){
        array[i] = sortedArray[i - startIndex];
    }
}

void mergeSort(vector<int>& array, int startIndex, int lastIndex){
    if(lastIndex == startIndex){
        return;
    }
    
    if(lastIndex == startIndex + 1){
        if(array[startIndex] > array[lastIndex]){
            swap(array[startIndex], array[lastIndex]);
        }
        return;
    }
    
    int midIndex = (startIndex + lastIndex) / 2;
    mergeSort(array, startIndex, midIndex);
    mergeSort(array, midIndex+1, lastIndex);
    merge(array, startIndex, midIndex, lastIndex);
}

int main() {
    int size;
    cin >> size;
    int input;
    vector<int> array;
    for(int i = 0; i < size; i++){
        cin >> input;
        array.push_back(input);
    }
    
    mergeSort(array, 0, array.size() - 1);
    
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << ',';
    }
    
    cout << endl;
    std::cout << "Hello World!\n";
}
