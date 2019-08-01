int main() {
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    a.insert(a.begin(), b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    std::cout << "Hello World!\n";
}