bool isInteresting(string s){
    if(s.size() == 0){return true;}
    if(s[0] > '9' || s[0] < '0') return false;
    int cutLength = s[0] - '0';
    if(cutLength+1 > s.size()) return false;
    return isInteresting(s.substr(cutLength+1));
}

int main() {
    cout << (isInteresting("4g12y6hunter")? "true": "false") <<endl;
    cout << (isInteresting("124gray6hunter")? "true": "false") <<endl;
    cout << (isInteresting("31ba2a")? "true": "false") <<endl;
    std::cout << "Hello World!\n";
}