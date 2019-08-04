class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> dfsOrder;
        dfsOrder.push(root);
        string result;
        while(!dfsOrder.empty()){
            TreeNode* top = dfsOrder.front();
            if(top != NULL){
                dfsOrder.push(top -> left);
                dfsOrder.push(top -> right);
            }
            if(top == NULL){
                top = new TreeNode(-1);
            }
            char pos4 = ((top -> val) & (0xFF) << 24) >> 24;
            char pos3 = ((top -> val) & (0xFF) << 16) >> 16;
            char pos2 = ((top -> val) & (0xFF) << 8) >> 8;
            char pos1 = (top -> val) & (0xFF);
            result += pos4;
            result += pos3;
            result += pos2;
            result += pos1;
            dfsOrder.pop();
        }
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> treeNodesFree;
        TreeNode* current = NULL, root = NULL;
        bool leftSet= false;
        for(int i = 0; i < data.size(); i += 4){
            int val = data [i + 3] + data [i + 2] << 8 + data [i+1] << 16 + data [i] << 24;
            if(leftSet){
                
            }
        }
    }
};

int main() {
    TreeNode* a = new TreeNode(1);
    a-> left = new TreeNode(2);
    a->right = new TreeNode(3);
    a->right -> left = new TreeNode(4);
    a-> right -> right = new TreeNode(5);
    Codec encoder;
    string encoded = encoder.serialize(a);
    TreeNode* decoded = encoder.deserialize(a);
    cout << decoded-> val << endl;
    cout << decoded->left -> val << endl;
    cout << decoded-> right -> val << endl;
    cout << decoded-> right -> left-> val << endl;
    cout << decoded-> right -> right-> val << endl;
    std::cout << "Hello World!\n";
}