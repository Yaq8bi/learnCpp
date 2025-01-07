#include <iostream>
#include <cassert>
#include "person.h"

int main() {
    // Test for person1
    person_t person1;
    person1.init(25, 1);
    assert(person1.get_age() == 25);
    assert(person1.get_id() == 1);

    // Test for person2
    person_t person2;
    person2.init(30, 2);
    assert(person2.get_age() == 30);
    assert(person2.get_id() == 2);

    std::cout << "All tests passed!\n";
    return 0;
}
