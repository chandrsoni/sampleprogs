
// stores size - 1 objects as the differentiator for 
template <class T>
class CircularQueue{
    public:
    vector<T> data;
    int size;
    int startPointer;
    int endPointer;
    bool empty, full;
    CircularQueue(T init, int size){
        this->size = size;
        data = vector<T>(size, init);
        startPointer = 0;
        endPointer =  0;
        empty = true;
        full = false;
    }
    
    bool push(T val){
        if(full) {
            return false;
        }
        empty = false;
        data[endPointer] = val;
        endPointer = (endPointer + 1)%size;
        cout << startPointer << ',' << endPointer << endl;
        if(endPointer == startPointer){full = true;}
        return true;
    }
    
    T pop(){
        if(empty){
            throw "Popped an empty queue";
        }
        full = false;
        int returnVal = data[startPointer];
        startPointer = (startPointer + 1) % size;
        if(startPointer == endPointer){ empty = true;}
        return returnVal;
    }
};

int main() {
    
    CircularQueue<int> q(0, 9);
    q.push(5);
    q.push(7);
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(3);
    for(int i = 0; i < 10; i++)cout << q.pop() << endl;
    std::cout << "Hello World!\n";
}
