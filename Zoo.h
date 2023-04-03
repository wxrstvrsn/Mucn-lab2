//
// Created by wxrstvrsn on 30.03.2023.
//

#pragma once

#include <iostream>
#include <vector>
#include "Animal.h"

class Zoo {
public:
    Zoo();

    Zoo(const std::string &_title) : title(_title) {};

    /** Returns the last Animal in Zoo store **/
    Animal *get();

    /** Puts the Animal to free cell **/
    void put(const Animal &animal);

    /** Getting animal by index **/
    Animal *operator[](int index);

    /** Copy-assignment operator **/
    Zoo &operator=(const Zoo &other);

    /** C-tor **/
    Zoo(const Zoo &other);

    /** Overload insertion operator for adding Animal to Zoo */
    Zoo &operator<<(const Animal &animal);

    /** Equal operator for Zoo stores **/
    bool operator==(Zoo &other);

    /** Sending to console name, size and buddies */
    friend std::ostream &operator<<(std::ostream &os, const Zoo &zoo);

    /** Temporary void for db (until i create good realization of operator<< **/
    void display() {
        for (Animal *iter: animals) {
            std::cout << *iter << " ";
            std::cout << std::endl;
        }

    }


private:
    std::string title;
    std::vector<Animal *> animals;
};

