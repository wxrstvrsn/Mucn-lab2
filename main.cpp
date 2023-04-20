#include <iostream>


#include "Zoo.h"

int main() {
    Zoo zoo1 = Zoo("Kitty-Bun", 10);
    Rabbit rab1 = Rabbit("Guus", 1, "The Flemish Giant");
    Cat cat1 = Cat("Maxwell", 4, "Siberian");
    Dog dog1 = Dog("Goofy", 6, "Beagle");



    zoo1 << &rab1 << &cat1 << &dog1;
    /*zoo1 << &cat1;
    zoo1 << &dog1;*/

    zoo1();

    /*Zoo zoo2 = std::move(zoo1);

    Dog dog2 = Dog("Boobby", 1, "Russel Terrier");
    zoo2 << &dog2;

    zoo1();
    zoo2();*/

    return 0;

}