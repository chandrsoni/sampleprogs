string add(string num1, string num2){
    if(num1.size() == 0) return num2;
    if(num2.size() == 0) return num1;
        char num1lbit = num1[num1.size()-1], num2lbit = num2[num2.size()-1];
        int num1lnum = num1lbit - '0', num2lnum = num2lbit - '0';
        string sum = add(num1.substr(0, num1.size() - 1), num2.substr(0, num2.size() - 1));
        if(num1lnum + num2lnum > 9){
            sum = add(sum, "1");
        }
    char lchar = (((num1lnum + num2lnum) % 10) + '0');
        sum.append(1, lchar);
    return sum;
}

int main() {
    cout << add("321", "789") << endl;
    std::cout << "Hello World!\n";
}