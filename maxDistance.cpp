int maxDistance(string s1, string s2){
    int minLength = s1.size() > s2.size() ? s1.size() : s2.size();
    int lengthSum = s1.size() + s2.size();
    for(int i = 0; i < minLength; i++){
        if(s1[i] != s2[i]){
            return lengthSum - 2 * i;
        }
    }
    
    return lengthSum - 2 * minLength;
}

int main() {
    cout << maxDistance("000", "110") << endl;
    cout << maxDistance("000", "000") << endl;
    cout << maxDistance("000", "1100") << endl;
    cout << maxDistance("000", "0000") << endl;
    cout << maxDistance("0000", "110") << endl;
    cout << maxDistance("0000", "000") << endl;
    cout << maxDistance("1011000", "1011110") << endl;
    std::cout << "Hello World!\n";
}