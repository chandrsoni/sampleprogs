
string add(string num1, string num2){
    if(num1.size() == 0) return num2;
    if(num2.size() == 0) return num1;
    int n1lastDigit = (num1[num1.size() - 1] - '0'), n2lastDigit = (num2[num2.size() - 1]- '0');
    int lastDigitSum = n1lastDigit + n2lastDigit;
    string sum = add(num1.substr(0, num1.size() - 1), num2.substr(0, num2.size() - 1));
    if(lastDigitSum > 9){
        sum = add(sum, "1");
    }
    
    return sum.append(1, '0' + lastDigitSum % 10);
}

string multiply(string num1, string num2){
    if(num1.size() == 0){
        // Bad request 
        return "";
    }
    string result;
    string multiples[10];
    for(int i = 1; i < 10;i++ ){
        multiples[i] = add(multiples[i-1], num1);
    }
    for(int i = 0; i < num2.size(); i++){
        int n2lastDigit = (num2[num2.size() - 1 - i] - '0');
        string lastDigitProduct = multiples[n2lastDigit];
        result = add(result, lastDigitProduct.append(i, '0'));
    }
    
    return result;
}

int main() {
    cout << add("321", "789") << endl;
    cout << multiply("2", "3") << endl;
    cout << multiply("10", "20") << endl;
    cout << multiply("123","456") << endl;
    std::cout << "Hello World!\n";
}