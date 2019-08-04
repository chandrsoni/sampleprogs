
class TrieNode{
    public:
    bool isEndNode;
    TrieNode* children[27];
    TrieNode(){
        isEndNode = false;
        for(int i = 0; i < 27; i++){
            children[i] = NULL;
        }
    }
    
    // Assuming words are only a-z.
    void addWord(string word){
        if(word.size() == 0){
            isEndNode = true;
            return;
        }
        
        int firstChar = (word[0]-'a')+1;
        if(children[0] == NULL){
            children[0] = new TrieNode();
        }
        if(children[firstChar] == NULL){
            children[firstChar] = new TrieNode();
        }
        children[0] -> addWord(word.substr(1));
        children[firstChar] -> addWord(word.substr(1));
    }
    
    bool search(string word){
        if(word.size() == 0){
            return isEndNode;
        }
        
        int firstCharIndex = word[0] == '.' ? 0 : (word[0] - 'a')+1;
            if(children[firstCharIndex] == NULL) return false;
            else return children[firstCharIndex]->search(word.substr(1));
    }
    void print(){
        cout << (isEndNode? "true": "false") << endl;
        for(int i =1; i < 27; i++){
            if(children[i] != NULL){
                cout << char('a' + (i-1));
                children[i] -> print();
            }
        }
    }
};

int main() {
    TrieNode* root = new TrieNode();
    root->addWord("bad");
    root->print();
root->addWord("dad");
root->addWord("mad");
cout << (root->search("pad")? "true": "false") << endl;
cout << (root->search("bad")? "true": "false") << endl;
cout << (root->search(".ad")? "true": "false") << endl;
cout << (root->search("b..")? "true": "false") << endl;
    std::cout << "Hello World!\n";
}