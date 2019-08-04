
bool isValid(string s) {
    stack<char> openBrackets;
    for(string::iterator it = s.begin(); it != s.end(); it++){
        char ithChar = *it;
        switch(ithChar){
            case '{':
            case '(':
            case '[':
                openBrackets.push(ithChar);
                break;
            case '}':
                if(openBrackets.empty() || openBrackets.top() != '{'){return false;}
                openBrackets.pop();
                break;
            case ')':
                if(openBrackets.empty() || openBrackets.top() != '('){return false;}
                openBrackets.pop();
                break;
            case ']':
                if(openBrackets.empty() || openBrackets.top() != '['){return false;}
                openBrackets.pop();
                break;
            default:
                return false;
        }
    }
    
    return openBrackets.empty();
}

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "([)]";
    string s4 = "(]";
    string s5 = "{[]}";
    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;
    cout << isValid(s3) << endl;
    cout << isValid(s4) << endl;
    cout << isValid(s5) << endl;
    std::cout << "Hello World!\n";
}