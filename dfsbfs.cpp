class Node {
    int value;
    public:
    vector<Node*> children;
    void dfs(){
        stack<Node*> dfsOrder;
        dfsOrder.push(this);
        
        while(!dfsOrder.empty()){
            Node* topNode = dfsOrder.top();
            cout << topNode -> value <<endl;
            dfsOrder.pop();
            for(int i = 0; i < topNode -> children.size(); i++){
                dfsOrder.push(topNode -> children[i]);
            }
        }
    }
    
    void dfsRec(){
        for(int i =0; i < children.size(); i++){
            children[i] -> dfsRec();
        }
        cout << value <<endl;
    }
    
    void bfs(){
        queue<Node*> bfsqueue;
        bfsqueue.push(this);
        while(!bfsqueue.empty()){
            Node* top = bfsqueue.front();
            for(int i = 0; i < top-> children.size(); i++){
                bfsqueue.push(top->children[i]);
            }
            cout << top -> value << endl;
            bfsqueue.pop();
        }
    }
    
    Node(int val){
        value = val;
    }
};

int main() {
    Node root(1);
    root.children.push_back(new Node(11));
    root.children.push_back(new Node(12));
    root.children.push_back(new Node(13));
    root.children.push_back(new Node(14));
    root.children.push_back(new Node(15));
    root.children[0]->children.push_back(new Node(111));
    root.children[0]->children.push_back(new Node(112));
    root.children[0]->children.push_back(new Node(113));
    root.children[0]->children.push_back(new Node(114));
    root.children[1]->children.push_back(new Node(121));
    root.children[1]->children.push_back(new Node(122));
    root.children[1]->children.push_back(new Node(123));
    root.children[1]->children.push_back(new Node(124));
    root.bfs();
}