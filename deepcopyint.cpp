class Node {
    public: 
    int value = 0;
    Node* left = NULL;
    Node* right = NULL;
    Node(){}
    Node(int val){
        value = val;
    }
    Node(const Node& copyRef){
        value = copyRef.value;
        left = copyRef.left == NULL ? NULL : new Node(*copyRef.left);
        right = copyRef.right == NULL ? NULL : new Node(*copyRef.right);
    }
    
    Node& operator=(const Node& copyRef) {
        if(this != &copyRef){
            this->value = copyRef.value;
            this->left = copyRef.left == NULL ? NULL : new Node(*copyRef.left);
            this->right = copyRef.right == NULL ? NULL : new Node(*copyRef.right);
        }
        return *this;
    }
    
    void Print(){
        cout << value << endl;
        if(left != NULL){left->Print();}
        if(right != NULL){right->Print();}
    }
    
    ~Node(){
        delete left;
        delete right;
    }
};

int main() {
    Node a(10);
    a.left = new Node(4);
    a.right = new Node(6);
    Node b = a;
    a.Print();
    b.Print();
    b.left -> value = 9;
    b.value = 21;
    a.Print();
    b.Print();
}