vector<int> mergeUnique(vector<int>& q1, vector<int>& q2){
    vector<int> result;
    int i1 = 0, i2 = 0;
    while(i1 < q1.size() && i2 < q2.size()){
        if(q1[i1] == q2[i2]){
            result.push_back(q1[i1++]);
            i2++;
        }
        else if(q1[i1] < q2[i2]){
            result.push_back(q1[i1++]);
        }
        else{
            result.push_back(q2[i2++]);
        }
    }
    
    while(i1 < q1.size()){
        result.push_back(q1[i1++]);
    }
    while(i2 < q2.size()){
        result.push_back(q2[i2++]);
    }
    
    return result;
}

void print(vector<int> queue){
    for(int i =0; i < queue.size(); i++){
        cout << queue[i] <<",";
    }
    cout << endl;
}

int main() {
    vector<int> a1;
    vector<int> a2;
    a1.push_back(1);
    a2.push_back(4);
    print(mergeUnique(a1,a2));
    a1.push_back(2);
    print(mergeUnique(a1,a2));
    a2.push_back(5);
    a2.push_back(6);
    print(mergeUnique(a1,a2));
    a1.push_back(3);
    print(mergeUnique(a1,a2));
    a1.push_back(4);
    a2.push_back(7);
    print(mergeUnique(a1,a2));
    std::cout << "Hello World!\n";
}