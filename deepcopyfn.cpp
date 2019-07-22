class NodeN{
    public:
    int value;
    NodeN* left;
    NodeN* right;
    NodeN* deepCopy(){
        NodeN* result = new NodeN();
        result -> value = value;
        result -> left = left == NULL ? NULL : left-> deepCopy();
        result -> right = right == NULL ? NULL : right-> deepCopy();
        return result;
    }
}

int main() {
    std::cout << "Hello World!\n";
}