//
// Created by wxrstvrsn on 30.03.2023.
//

#pragma once

#include <string>
#include <iostream>

/** Base class **/
class Animal {
protected:
    std::string name;
    int age;
    std::string breed;

public:
    /**C-tor with parameters */
    Animal(const std::string &name = "", int age = 0, const std::string &breed = "");

    /**C-tor for manual adding animals [maybe i will rewrite it later {No, still feel lazy and folly} */
    Animal();

    virtual void Say() const = 0;

    virtual void Play() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Animal &animal);

    //FIXME
    /** Comparision Operator */
    bool operator==(const Animal &other) const {
        return (name == other.name &&
                age == other.age &&
                breed == other.breed &&
                species() == other.species());
    }

    //SHTC ??
    virtual std::string species() const = 0;


    /** My name is Code, Shit Code  ??? */
    virtual Animal *clone() const = 0;


};

/**Derived class **/
class Dog : public Animal {
public:

    Dog(const std::string &name = "", int age = 0, const std::string &breed = "");

    virtual void Say() const override;

    virtual void Play() const override;

    virtual Animal *clone() const override;

    std::string species() const override {
        return "Dog";
    }
};

/**Derived class **/
class Cat : public Animal {
public:
    Cat(const std::string &name = "", int age = 0, const std::string &breed = "");

    virtual void Say() const override;

    virtual void Play() const override;

    virtual Animal *clone() const override;

    std::string species() const override {
        return "Cat";
    }
};

