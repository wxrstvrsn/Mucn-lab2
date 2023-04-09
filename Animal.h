//
// Created by wxrstvrsn on 30.03.2023.
//

#pragma once

#include <string>
#include <iostream>

/** Base class **/
class Animal {
public:
    /**C-tor with parameters */
    Animal(const std::string &name = "", int age = 0, const std::string &breed = "");

    //TODO: RETHINK about manual adding information bout animals from input buffer
    /**C-tor for manual adding animals [maybe i will rewrite it later {No, still feel lazy and folly} */
    Animal();

    virtual void Say() const = 0;

    virtual void Play() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Animal &animal);

    //FIXME
    /** Comparision Operator for correct work overload== in Zoo*/
    bool operator==(const Animal &other) const {
        return (name == other.name &&
                age == other.age &&
                breed == other.breed &&
                getSpecies() == other.getSpecies());
    }

    //SHTC ??
    /*virtual std::string getSpecies() const = 0;*/

    //CHECKFIXED
    static std::string getSpecies(){
        return species;
    }

    /** My name is Code, Shit Code  ??? */
    virtual Animal *clone() const = 0;

protected:
    std::string name;
    int age;
    std::string breed;

    //CHECKFIXED
    static std::string species;
};

/**Derived class **/
class Dog : public Animal {
public:

    Dog(const std::string &name = "", int age = 0, const std::string &breed = "");

    virtual void Say() const override;

    virtual void Play() const override;

    virtual Animal *clone() const override;

    /*std::string getSpecies() const override {
        return "Dog";
    }*/
};

/**Derived class **/
class Cat : public Animal {
public:
    Cat(const std::string &name = "", int age = 0, const std::string &breed = "");

    virtual void Say() const override;

    virtual void Play() const override;

    virtual Animal *clone() const override;

    /*std::string getSpecies() const override {
        return "Cat";
    }*/
};

class Rabbit : public Animal {
public:
    Rabbit(const std::string &name = "", int age = 0, const std::string &breed = "");

    virtual void Say() const override;

    virtual void Play() const override;

    virtual Animal *clone() const override;

    /*std::string getSpecies() const override {
        return "Rabbit";
    }*/
};