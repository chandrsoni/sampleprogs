
#define INTMAX 2147483647
#define INTMIN -2147483648
#define INTMINSTR "2147483648"

bool checkOutOfRange(string intString, bool negated){
    while(intString.size() > 0 && intString[0] == '0'){
        intString = intString.substr(1);
    }
    
    if(intString.size() > 10){
        return true;
    }
    if(intString.size() == 10){
        return intString >= INTMINSTR;
    }
    
    return false;
}

int myAtoi(string s){
    int i = 0; 
    while ( i < s.size()){
        if(s[i] != ' '){
            break;
        }
        
        i++;
    }
    
    bool negated = false;
    if(i < s.size() && s[i] == '-'){
        negated = true;
        i++;
    }
    if(i == s.size()){return 0;}
    int startIndex = i, lastIndex = -1;
    while(i < s.size()){
        if(s[i] < '0' || s[i] > '9'){
            lastIndex = i-1;
            break;
        }
        i++;
    }
    
    if(startIndex == i){return 0;}
    if(lastIndex < 0){lastIndex = s.size()-1;}
    string intString = s.substr(startIndex, lastIndex - startIndex + 1);
    if(checkOutOfRange(intString, negated)){return negated ? INTMIN : INTMAX;}
    int result = 0;
    for(int i = 0; i < intString.size(); i++){
        result *= 10;
        result += intString[i]-'0';
    }
    
    return negated ? -1 * result: result;
}

int main() {
    cout << myAtoi("      123  words") << endl;
    cout << myAtoi("      123") << endl;
    cout << myAtoi("      -123") << endl;
    cout << myAtoi("123") << endl;
    cout << myAtoi("42") << endl;
    cout << myAtoi("1") << endl;
    cout << myAtoi(" 1 ") << endl;
    cout << myAtoi("words and 987") << endl;
    std::cout << "Hello World!\n";
}