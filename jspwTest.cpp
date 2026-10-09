#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << name << " " << age << '\n';
    }
};

int main() {
    Student s1;
    s1.name = "Rishabh";
    s1.age = 21;

    const Student s2;

    s1.display();
}