class TrieNode {
    private:
    TrieNode* children[26];
    public:
    TrieNode(){
        for(int i =0; i < 26; i++){
            children[i] = NULL;
        }
    }
}

int main() {
}