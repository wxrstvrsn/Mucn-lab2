#include <iostream>


/*
class Base {
public:
    std::string name;
    int age;

    Base(std::string _name, int _age) : age(_age), name(_name) {}
};

class Derived : public Base {
public:
    Derived(std::string _name, int _age) : Base(_name, _age) {}
};

*/

#include "Zoo.h"

int main() {
    /*Base zoo1 = Base("Bobby", 40);
    Derived second = Derived("Sam", 27);

    std::cout << second.name << std::endl;*/
    Zoo zoo1;
    Cat pet1 = Cat("Barsik", 3, "MainKun");
    zoo1 << pet1;
    Cat pet2 = Cat("Aboba", 10, "Cringe");
    zoo1.put(pet2);

    Zoo zoo2;
    zoo2 << pet1 << pet2;

    std::cout << "DUUUUDE" << *zoo2.get() << std::endl;

    std::cout << "\n---------------------"
                 "\n---------------------"
                 "\n---------------------" << std::endl;
    zoo1.display();
    std::cout << "UPDATED\n" << std::endl;
    zoo2.display();

    std::cout << "\n\n00000000000000000000000000000000\n\n";
    std::cout << zoo1 << std::endl;

    std::cout << (zoo1 == zoo2) << " COMPARISON HERE" << std::endl;
}
