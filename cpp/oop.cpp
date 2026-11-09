// Basic OOP in C++: classes, inheritance, polymorphism
#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const { std::cout << "...\n"; }
    std::string name;
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << name << " says woof\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << name << " says meow\n"; }
};

int main() {
    std::unique_ptr<Animal> a = std::make_unique<Dog>();
    a->name = "Rex";
    a->speak();
    a = std::make_unique<Cat>();
    a->name = "Mimi";
    a->speak();
    return 0;
}
