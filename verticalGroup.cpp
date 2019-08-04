vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(root == NULL) return vector<vector<int>>();
    int minIndex = 0;
    int maxIndex = 0;
    map<TreeNode*, int> verticalGroup;
    verticalGroup[root] = 0;
    queue<TreeNode*> traversalOrder;
    traversalOrder.push(root);
    while(!traversalOrder.empty()){
        TreeNode* top = traversalOrder.front();
        if(top -> left != NULL){
            traversalOrder.push(top->left);
            int lowerIndex = verticalGroup[top] -1;
            verticalGroup[top->left] = lowerIndex;
            if(lowerIndex < minIndex){
                minIndex = lowerIndex;
            }
        }
        if(top->right != NULL){
            traversalOrder.push(top->right);
            int upperIndex = verticalGroup[top] + 1;
            verticalGroup[top->right] = upperIndex;
            if(upperIndex > maxIndex){
                maxIndex = upperIndex;
            }
        }
        
        traversalOrder.pop();
    }
    
    cout << minIndex << ", " << maxIndex << endl;
    
    vector<vector<int>> result(maxIndex-minIndex+1, vector<int>());
    for(map<TreeNode*, int> :: iterator it = verticalGroup.begin(); it != verticalGroup.end();it++){
        // TODO: insert at the right place or sort afterwards.
        result[it->second - minIndex].push_back(it-> first->val);
    }
    
    for(int i = 0; i < result.size(); i++){
        sort(result[i].begin(), result[i].end());
    }
    return result;
}

void printResult(vector<vector<int>> result){
    for(int i =0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = new TreeNode(3);
    printResult(verticalTraversal(root));
    root -> left = new TreeNode(9);
    root-> right = new TreeNode(20);
    root-> right-> left = new TreeNode(15);
    root-> right -> right = new TreeNode(7);
    printResult(verticalTraversal(root));
    delete(root);
    root = new TreeNode(1);
    root-> left = new TreeNode(2);
    root-> right = new TreeNode(3);
    root-> left -> left = new TreeNode(4);
    root-> left -> right = new TreeNode(5);
    root-> right -> left = new TreeNode(6);
    root-> right -> right = new TreeNode(7);
    printResult(verticalTraversal(root));
    std::cout << "Hello World!\n";
}