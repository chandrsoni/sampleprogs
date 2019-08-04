string hint(string pin, string guess){
    if(pin.size() == 0 || pin.size() != guess.size()){
        // 400 Bad Request.
    }
    set<char> pinCharSet;
    for(int i = 0; i < pin.size(); i++){
        pinCharSet.insert(pin[i]);
    }
    
    string result;
    
    for(int i = 0; i < guess.size(); i++){
        if(pin[i] == guess[i]){result.append("*");}
        else if(pinCharSet.find(guess[i]) != pinCharSet.end()){
            result.append("0");
        }
        else result.append("_");
    }
    
    return result;
}

int main() {
    cout << hint("1234", "1426") << endl;
    std::cout << "Hello World!\n";
}