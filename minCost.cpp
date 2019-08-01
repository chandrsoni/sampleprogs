int main() {
    vector<int> a;
    a.push_back(8);
    a.push_back(4);
    a.push_back(6);
    a.push_back(12);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < a.size(); i++){
        q.push(a[i]);
    }
    int result = 0;
    while(q.size() > 1){
        int top1 = q.top();
        q.pop();
        int top2 = q.top();
        q.pop();
        q.push(top1 + top2);
        result += top1 + top2;
    }
    cout << result << endl;
    std::cout << "Hello World!\n";
}