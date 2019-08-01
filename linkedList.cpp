
class ListN{
    public:
    int value;
    ListN* next;
    ListN(int val){
        value = val;
        next = NULL;
    }
};

class LinkedL{
    private:
    ListN* begin;
    public:
    LinkedL(){
        begin = NULL;
    }
    void insert(int val){
        ListN* toInsert = new ListN(val);
        toInsert -> next = begin;
        begin = toInsert;
    }
    
    void print(){
        ListN* cpointer = begin;
        while(cpointer != NULL){
            cout << cpointer -> value <<endl;
            cpointer = cpointer -> next;
        }
    }
};

int main() {
    LinkedL a;
    a.print();
    cout<<"here"<< endl;
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.insert(0);
    a.insert(9);
    a.insert(8);
    a.insert(7);
    a.insert(6);
    a.print();
}