class Person {
int id;
char name[5];
 public:
 void aboutMe() {
 cout << "I am a person." << endl;
 }

virtual bool addCourse(string s) = 0;
};


 class Student : public Person {
 public:
 void aboutMe() {
 cout << "I am a student." << endl;
 }

 bool addCourse(string s) {
 cout << "Added course " << s << " to student" << endl;
 return true;
 }
 };

 int main() {
 Student* p = new Student();
 p->aboutMe(); // prints "I am a student."
 p->addCourse("History");
delete p;
}