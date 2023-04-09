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

    /** Constructor with title parameter */
    Zoo(const std::string &_title, size_t _max) : title(_title), max(_max){};

    /** D-tor */
    /*~Zoo();*/

    /** Returns the last Animal in Zoo store **/
    Animal *get();

    /** Puts the Animal to free cell **/
    void put(Animal *_animal);

    /** Getting animal by index **/
    Animal *operator[](int index);

    /** C-tor **/
    Zoo(const Zoo &other);

    /** Overload insertion operator for adding Animal to Zoo */
    void operator<<(Animal *_animal);

    /** Equal operator for Zoo stores **/
    bool operator==(const Zoo &other);


    /** Function call */
    void operator()() const;

private:
    std::string title;
    std::vector<Animal *> animals;
    size_t max;
};

