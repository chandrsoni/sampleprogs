// assuming a-z for both s, t
bool isIsomorphic(string s, string t) {
    map<char, char> mapping;
    set<char> mappedValues;
    for(int i =0; i < s.size(); i++){
        if(mapping.find(s[i])  == mapping.end()){
            if(mappedValues.find(t[i]) != mappedValues.end()){
                return false;
            }
            mappedValues.insert(t[i]);

            mapping[s[i]] = t[i];
        }
        else if (mapping[s[i]] != t[i]){
            return false;
        }
    }

    return true;
}

void rhymes(int n, string currentPattern, vector<string>& rhymesList){
    if(currentPattern.size() == n){
        for(int i = 0; i < rhymesList.size(); i++){
            if(isIsomorphic(currentPattern, rhymesList[i])){
                return;
            }
        }
        
        rhymesList.push_back(currentPattern);
        return;
    }
    
    for(int i = 0; i < n; i++){
        currentPattern += (char)('A'+i);
        rhymes(n, currentPattern, rhymesList);
        currentPattern = currentPattern.substr(0, currentPattern.size() - 1);
    }
}

vector<string> rhymes(int n){
    vector<string> result;
    rhymes(n, "", result);
    return result;
}

void print(vector<string>& result){
    if(result.size() > 0)cout << "rhymes for " << result[0].size() << endl;
    for(int i =0; i < result.size(); i++){
        cout << result[i] << endl;
    }
}

int main() {
    // string s = "tomato", t = "potato";
    // cout << (isIsomorphic(s,t) ? "true": "false") << endl;
    // s = "egg"; t = "add";
    // cout << (isIsomorphic(s,t) ? "true": "false") << endl;
    // s = "foo"; t = "bar";
    // cout << (isIsomorphic(s,t) ? "true": "false") << endl;
    // s = "paper"; t = "title";
    // cout << (isIsomorphic(s,t) ? "true": "false") << endl;
    // s = "ab"; t = "aa";
    // cout << (isIsomorphic(s,t) ? "true": "false") << endl;
    vector<string> rhymeList;
    rhymeList = rhymes(0);
    print(rhymeList);
    rhymeList = rhymes(1);
    print(rhymeList);
    rhymeList = rhymes(2);
    print(rhymeList);
    rhymeList = rhymes(3);
    print(rhymeList);
    rhymeList = rhymes(4);
    print(rhymeList);
    rhymeList = rhymes(5);
    print(rhymeList);
    rhymeList = rhymes(6);
    
    std::cout << "Hello World!\n";
}
