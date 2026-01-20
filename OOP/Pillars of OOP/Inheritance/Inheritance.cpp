#include <iostream>
#include <string>
using namespace std;

// ==================== BASE CLASS ====================
class Animal
{
private:
    string name;
    int age;

public:
    Animal(string n, int a)
    {
        name = n;
        age = a;
    }

    void setName(string n) { name = n; }
    string getName() { return name; }

    // Getter and Setter for age
    void setAge(int a) { age = a; }
    int getAge() { return age; }

    // Common method
    void eat()
    {
        cout << name << " is eating." << endl;
    }
};

// ==================== SIMPLE INHERITANCE ====================
class Mammal : public Animal
{
public:
    // Constructor that calls base class constructor
    Mammal(string n, int a) : Animal(n, a) {}

    void walk()
    {
        cout << getName() << " is walking." << endl;
    }
};

// ==================== INDEPENDENT CLASS ====================
class FlyingAnimal
{
public:
    void fly()
    {
        cout << "Flying..." << endl;
    }
};

// ==================== MULTILEVEL INHERITANCE ====================
class Dog : public Mammal
{
public:
    Dog(string n, int a) : Mammal(n, a) {}

    void bark()
    {
        cout << getName() << " is barking." << endl;
    }
};

class Puppy : public Dog
{
public:
    Puppy(string n, int a) : Dog(n, a) {}

    void play()
    {
        cout << getName() << " can play";
    }
};

// ==================== MULTIPLE INHERITANCE ====================
class Bat : public Mammal, public FlyingAnimal
{
public:
    Bat(string n, int a) : Mammal(n, a) {}

    // Override fly() to show bat name
    void fly()
    {
        cout << getName() << " is flying." << endl;
    }
};

// ==================== HYBRID INHERITANCE ====================
class SwimmingAnimal
{
public:
    void swim()
    {
        cout << "Swimming..." << endl;
    }
};

class Platypus : public Mammal, public SwimmingAnimal
{
public:
    Platypus(string n, int a) : Mammal(n, a) {}

    void swim()
    {
        cout << getName() << " is swimming." << endl;
    }
};

// ==================== MAIN FUNCTION ====================
int main()
{
    cout << "=== Dog ===" << endl;
    Dog d("Fido", 3);
    d.eat();
    d.walk();
    d.bark();

    cout << "\n=== Bat ===" << endl;
    Bat b("Bruce", 2);
    b.eat();
    b.walk();
    b.fly();

    cout << "\n=== Platypus ===" << endl;
    Platypus p("Perry", 5);
    p.eat();
    p.walk();
    p.swim();

    return 0;
}
