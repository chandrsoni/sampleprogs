
class A {
    public:
    void func(){
        cout<< "A" <<endl;
    }
};

class B: public A {
    public:
    void func(){
        cout <<"B" << endl;
    }
};

class C {
    public:
    virtual void func(){
        cout<< "C" <<endl;
    }
};

class D: public C {
    public:
    void func(){
        cout <<"D" << endl;
    }
};

class E : public C {
    public:
    void func() override{
        cout << "E" << endl;
    }
};

int main() {
    A a;
    B b;
    C c;
    D d;
    a.func(); // prints A
    b.func(); // prints B
    c.func(); // prints C
    d.func(); // prints D
    A* aa = new A();
    A* ab = new B();
    B* bb = new B();
    aa -> func(); // prints A
    ab -> func(); // prints A
    bb -> func(); // prints B
    C* cc = new C();
    C* cd = new D();
    D* dd = new D();
    C* ce = new E();
    E* ee = new E();
    cc -> func(); // prints C
    cd -> func(); // prints D
    dd -> func(); // prints D
    ce -> func(); // prints E
    ee -> func(); // prints E, override only ensures that the orig func is virtual.
    std::cout << "Hello World!\n";
}