#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    int age(int yearBorn) {
        return 2024 - yearBorn;
    }
};

class Child : public Person {
public:
    string son;
    Child() : son("Justin") {}
};

int main() {
    Person Obj1;
    Obj1.name = "Jena";

    Person Obj2;
    Obj2.name = "Lisa";

    cout << Obj1.name << "\n";
    cout << Obj2.name << "\n";

    // Call age method
    cout << "Age of " << Obj2.name << " is " << Obj2.age(1970) << "\n";

    // Create an object of Child to access 'son'
    Child childObj;
    cout << Obj2.name << " is the mother of " << childObj.son << "\n";

    return 0;
}