#ifndef PERSON_T_H
#define PERSON_T_H

#include <iostream>

class person_t
{
private:
    int age;
    int id;

public:
    // Constructor
    person_t() : age(0), id(0) {} // Default constructor because the members are set to private.

    // Member function to initialize values
    void init(int age, int id)
    {
        this->age = age; // this-> is a pointer to the object itself. Yani bu objenin age'ine erişmek istiyorum.
        this->id = id;
    }

    // Getter functions
    int get_id() const { return id; }
    int get_age() const { return age; }

    // Destructor
    ~person_t()
    {
        std::cout << "Person object destroyed!" << std::endl;
    }
};

#endif // PERSON_T_H
