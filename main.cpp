#include <iostream>


#include "Zoo.h"

int main() {
    Zoo zoo1 = Zoo("Kitty-Bun", 10);
    Rabbit rab1 = Rabbit("Guus", 1, "The Flemish Giant");
    Cat cat1 = Cat("Maxwell", 4, "Siberian");
    Dog dog1 = Dog("Goofy", 6, "Beagle");



    zoo1 << &rab1;
    zoo1 << &cat1;
    zoo1 << &dog1;

    Zoo zoo2(zoo1);

    Animal *getted = zoo2.get();

    zoo2();


    zoo1();
    return 0;

}