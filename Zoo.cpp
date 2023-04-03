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

void Zoo::put(const Animal &animal) {
    Animal *new_animal = animal.clone();
    animals.push_back(new_animal);
}

Animal *Zoo::operator[](int index) {
    return animals[index];
}

Zoo &Zoo::operator=(const Zoo &other) {
    if (this == &other) {
        return *this;
    }
    for (auto animal: animals) {
        delete animal;
    }
    animals.clear();
    for (auto animal: other.animals) {
        animals.push_back(animal);
    }
    return *this;
}

Zoo::Zoo(const Zoo &other) {
    for (auto animal: other.animals) {
        animals.push_back(animal);
    }
}

Zoo &Zoo::operator<<(const Animal &animal) {
    put(animal);
    return *this;
}

bool Zoo::operator==(Zoo &other) {
    if (animals.size() != other.animals.size()) {
        return false;
    }

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

std::ostream &operator<<(std::ostream &os, const Zoo &zoo) {
    os << "Information about Zoo store:" << "\n";
    os << "Name: " << zoo.title << ", Size: "
       << zoo.animals.size() << "\n";
    os << "Contained Animals:" << "\n";
    for (Animal *iter: zoo.animals) {
        os << *iter << "\n";
    }
    return os;
}

Zoo::Zoo() {
    title = "None";
}

