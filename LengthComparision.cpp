template <class T>
void print(vector<T> toPrint){
    for(int i = 0; i < toPrint.size(); i++){
        cout << toPrint[i] << endl;
    }
}

class newLength{
    public:
    int length;
    char lowChar;
    newLength(string s){
        length = 0;
        lowChar = CHAR_MAX;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == lowChar){
                length++;
            } else if(s[i] < lowChar){
                lowChar = s[i];
                length = 1;
            }
        }
    }
    
    bool operator<(const newLength& comparingTo){
        return length < comparingTo.length;
    }
};

vector<string> segregate(string& s,string& delimiter){
    vector<string> result;
    string remainingFrom = s;
    size_t found = remainingFrom.find(delimiter);
    while(found != string::npos){
        result.push_back(remainingFrom.substr(0, found));
        int startIndex = found + delimiter.size();
        remainingFrom = remainingFrom.substr(startIndex, remainingFrom.length() - startIndex);
        found = remainingFrom.find(delimiter);
    }
    result.push_back(remainingFrom);
    return result;
}

vector<int> getPos(string& matchFrom, string& matchTo){
    string delimiter = " ";
    vector<string> fromList = segregate(matchFrom, delimiter);
    vector<string> toList = segregate(matchTo, delimiter);
    print(fromList);
    print(toList);
    vector<int> result(toList.size());
    vector<newLength> fromLengths, toLengths;
    for(int i = 0; i < fromList.size(); i++){
        fromLengths.push_back(newLength(fromList[i]));
    }
    for(int i = 0; i < toList.size(); i++){
        toLengths.push_back(newLength(toList[i]));
    }
    
    for(int i =0; i < toList.size(); i++){
        int currentCount = 0;
        for(int j = 0; j < fromList.size(); j++){
            if(fromLengths[j] < toLengths[i]){currentCount++;}
        }
        result[i] = currentCount;
    }
    
    return result;
}

int main() {
    string left = "abcd aabc bd", right = "aaa aa";
    vector<int> pos = getPos(left, right);
    for(int i = 0; i < pos.size(); i++){
        cout << pos[i] << endl;
    }
    std::cout << "Hello World!\n";
}
