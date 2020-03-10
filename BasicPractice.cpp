using namespace std;

int add(int a, int b){
    return a + b;
}

class a{
    public:
    int part1;
    int part2;
    a(){
        part1 = 5;
        this->part2 = 6;
    }
    
    void print(){
        cout << part1 << ", " << part2 << endl;
    } 
};

template<class T>
class templ{
    int privat;
    public:
    int publi;
};

template<class T>
void print(vector<T> Tvec){
    for(int i = 0; i < Tvec.size(); i++){
        cout << Tvec[i] << endl;
    }
}

int main() {
    vector<int> intVec;
    for(int i = 0; i < 10;i++){
        intVec.push_back(i);
        std::cout << i << endl;
    }
    print(intVec);
    int* ad = new int(5);
    cout << add(2,3) << endl;
    a inst;
    inst.print();
    cout << &ad << ", "<< *ad << endl;
    std::cout << "Hello World!\n";
}
