class Node {
    public:
    int value;
    Node* next;
    Node(int val){
        value = val;
        next = NULL;
    }
};

class LinkedL {
    public:
    Node *first, *last;
    int size;
    LinkedL(){
        size = 0;
        first = last = NULL;
    }
    void add_back(int val){
        cout << "adding number" << endl;
        size++;
        if(first == NULL){
            first = last = new Node(val);
            return;
        }
        last->next = new Node(val);
        last = last->next;
    }
    void add_front(int val){
        size++;
        if(first == NULL){
            first = last = new Node(val);
            return;
        }
        Node* tempFirst = new Node(val);
        tempFirst->next = first;
        first = tempFirst;
    }
    
    void print(){
        Node *it = first;
        while(it != NULL){
            cout << (it->value) << ',';
            it = it->next;
        }
        
        cout <<endl;
    }
};

int main() {
    int size, input;
    cin >> size;
    LinkedL numList;
    for(int i = 0; i < size; i++){
        cin >> input;
        numList.add_back(input);
    }
    
    numList.print();
    cout << "something" << endl;
}
