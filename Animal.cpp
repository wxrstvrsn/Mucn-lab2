//
// Created by wxrstvrsn on 30.03.2023.
//


#include "Animal.h"

Animal::Animal(const std::string &_name, int _age, const std::string &_breed) :
        name(_name), age(_age), breed(_breed) {}


std::ostream &operator<<(std::ostream &os, const Animal &animal) {
    os << "Name: " << animal.name << ", Age: "
       << animal.age << ", Breed: " << animal.breed <<
       ", Species: " << animal.species();
    return os;
}



//FIXME
//const std::string Dog::type = "Dog";


Dog::Dog(const std::string &name, int age, const std::string &breed)
        : Animal(name, age, breed) {}

void Dog::Say() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::Play() const {
    std::cout << "Crunching a toy bone (▽◕ ᴥ ◕▽)" << std::endl;
}

Animal *Dog::clone() const {
    return new Dog(*this);
}

//RETHINK
//const std::string &Dog::getSpecies() const {
//    static const std::string species = "Dog";
//    return species;
//}

//FIXME
//const std::string Cat::species = "Cat";

Cat::Cat(const std::string &name, int age, const std::string &breed)
        : Animal(name, age, breed) {}

void Cat::Say() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::Play() const {
    std::cout << "Chasing a toy mouse (^˵◕ω◕˵^)" << std::endl;
}

Animal *Cat::clone() const {
    return new Cat(*this);
}


//FIXME
//const std::string &Cat::getSpecies() const {
//    static const std::string species = "Cat";
//    return species;
//}
