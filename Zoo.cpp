//
// Created by wxrstvrsn on 30.03.2023.
//

#include <vector>
#include "Zoo.h"
#include "Animal.h"

Animal *Zoo::get() {
    if (animals.empty()) {
        return nullptr;
    }
    Animal *animal = animals.back();
    animals.pop_back();
    return animal;
}

void Zoo::put(Animal *_animal) {
    if (animals.size() > max) {
        std::cout << "Free cells are over" << std::endl;
    }
    animals.push_back(_animal);
}

Animal *Zoo::operator[](int index) {
    return animals[index];
}


/*Zoo::Zoo(const Zoo &other) {
    for (auto animal: other.animals) {
        animals.push_back(animal);
    }
    this->max = other.max;
}*/

Zoo::Zoo(Zoo &&other) {
    this->animals = std::move(other.animals);


    other.animals.clear();
    this->title = other.title;
    this->max = other.max;
}

Zoo &Zoo::operator=(Zoo &&other) {
    if (this == &other) {
        return *this;
    }
    this->animals = std::move(other.animals);
    other.animals.clear();
    this->title = other.title;
    this->max = other.max;

    return *this;
}


bool Zoo::operator==(const Zoo &other) {
    if (animals.size() != other.animals.size()) {
        return false;
    }

    //RETHINK сравнять по указателям
    //RETHINK либо вообще сравнивать по данным магазина (название, размер)

    // чекаем все ли из this есть в other и наоборот
    // need to overload comparison operator
    for (int i = 0; i < animals.size(); i++) {
        bool foundMatch = false;
        for (int j = 0; j < other.animals.size(); j++) {
            if (*animals[i] == *other.animals[j]) {
                foundMatch = true;
                break;
            }
        }
        if (!foundMatch) {
            return false;
        }
    }

    return true;
}

void Zoo::operator()() const {
    std::cout << "Information about Zoo store:" << "\n";
    std::cout << "Title: " << this->title << ", Size: "
              << this->animals.size() << "\n";
    std::cout << "Contained Animals:" << "\n";
    for (auto iter: this->animals) {
        std::cout << *iter << std::endl;
    }
    std::cout << max - this->animals.size() << std::endl;
}

Zoo::Zoo() {
    title = "None";
    max = 20;
}

/*void Zoo::operator<<(Animal *_animal) {
    if (animals.size() > max) {
        std::cout << "Free cells are over" << std::endl;
        return;
    }
    animals.push_back(_animal);
}*/


Zoo &Zoo::operator<<(Animal *animal) {
    put(animal);
    return *this;
}




/*std::ostream &operator<<(std::ostream &os, const Zoo &zoo) {
    os << "Information about Zoo store:" << "\n";
    os << "Title: " << zoo.title << ", Size: "
       << zoo.animals.size() << "\n";
    os << "Contained Animals:" << "\n";
    for (Animal *iter: zoo.animals) {
        os << *iter << "\n";
    }
    return os;
}*/

/*Zoo::~Zoo() {
    for (auto animal: animals) {
        delete animal;
    }
    animals.clear();
}*/