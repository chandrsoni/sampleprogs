class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int val){
        this->value = val;
        this->left = this->right = NULL;
    }
    void add(int val){
        if (val < value) {
            if (this -> left != NULL) {
                this->left->add(val);
            }
            else {
                this -> left = new Node(val);
            }
        }
        else {
            if(this -> right != NULL) {
                this->right->add(val);
            }
            else {
                this->right = new Node(val);
            }
        }
    }
    
    void printInOrder(){
        if(this->left != NULL) {
            this->left->printInOrder();
        }
        cout << this->value << " ";
        if(this->right != NULL) {
            this->right->printInOrder();
        }
    }
};

int main() {
    
    int n;
    cin >> n;
    Node* root = NULL;
    int inp;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        if(root != NULL) {
            root->add(inp);
        }
        else {
            root = new Node(inp);
        }
    }
    if(root != NULL){
        root->printInOrder();
    }
    std::cout << "Hello World!\n";
}
