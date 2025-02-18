Here's your improved and completed class notes with better explanations and corrections:

---

# C++ Notes

## `std::tuple`
`std::tuple` is a fixed-size collection of heterogeneous values. It is similar to `std::pair`, but can hold more than two values.

Example:
```cpp
#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");

    int i;
    double d;
    std::string s;

    std::tie(i, d, s) = myTuple; // Unpacking the tuple

    std::cout << "Integer: " << i << ", Double: " << d << ", String: " << s << std::endl;
}
```
Usage:
- Useful when returning multiple values from a function.
- Can be accessed with `std::get<N>(tuple)`, where `N` is the index.

---

## `TYPED_TEST_SUITE_P()`
This is a part of Google Test (gTest) for writing parameterized tests. 

- `TYPED_TEST_SUITE_P()` is used to declare a test suite for multiple types.
- You define test cases that work for all the types provided.

Example:
```cpp
#include <gtest/gtest.h>

template <typename T>
class MyTest : public ::testing::Test {};

TYPED_TEST_SUITE_P(MyTest);

TYPED_TEST_P(MyTest, ExampleTest) {
    TypeParam value = 42;
    EXPECT_EQ(value, 42);
}

REGISTER_TYPED_TEST_SUITE_P(MyTest, ExampleTest);

using MyTypes = ::testing::Types<int, double>;
INSTANTIATE_TYPED_TEST_SUITE_P(MyInstance, MyTest, MyTypes);
```

This allows the same test logic to be used for multiple types.

---

## Importance of PDF
PDF files are important in software development for:
1. **Documentation** – Manuals, API references, research papers.
2. **Reports** – Generated logs, test reports.
3. **Preserving Layout** – Unlike plain text, formatting remains consistent.

---

## CMake
CMake is a tool to manage the build process of C++ projects.

```cmake
cmake_minimum_required(VERSION 3.22)

project(stack)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE some_library)  # Specify the correct library
```
### Key Points:
- `CMAKE_CXX_STANDARD 17` ensures C++17 is used.
- `-Wall -Wextra -Wpedantic` enables warnings.
- `target_link_libraries()` links external libraries.

---

## Faking || Link-time Substitution
"Faking" refers to replacing real functionality with a controlled substitute, often for testing.

### Example: Faking the System Date
1. Create a header file `date.h`:
   ```cpp
   #pragma once
   #include <chrono>
   #include <ctime>

   class Date {
   private:
       int year, month, day;
   public:
       Date(); // Constructor
       int getYear() const { return year; }
   };
   ```

2. Implement `date.cpp`:
   ```cpp
   #include "date.h"

   Date::Date() {
       std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
       std::time_t time_temp = std::chrono::system_clock::to_time_t(now);
       const std::tm* local_tm = std::localtime(&time_temp);

       year = local_tm->tm_year + 1900;
       month = local_tm->tm_mon + 1; // Month starts from 0
       day = local_tm->tm_mday;
   }
   ```

3. Main function:
   ```cpp
   #include <iostream>
   #include "date.h"

   int main() {
       Date today;
       std::cout << "Year: " << today.getYear() << std::endl;
   }
   ```

### Extracting Date from a String:
```cpp
std::string date = "2024-02-16";
int year, month, day;
std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
```
- `std::sscanf()` parses the date string into integer values.

---

## Interface || Runtime Substitution
An **interface** in C++ is a class that contains only **pure virtual functions** (functions with `= 0`). It is commonly used in testing to provide mock implementations.

Example:
```cpp
class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << "Log: " << message << std::endl;
    }
};
```

This allows substituting implementations at runtime.

---

## gMock (Google Mock)
Google Mock (`gMock`) is used for creating mock objects in testing.

### Example:
```cpp
#include <gmock/gmock.h>

class MockLogger : public ILogger {
public:
    MOCK_METHOD(void, log, (const std::string&), (override));
};

TEST(LoggerTest, LogsMessage) {
    MockLogger mock;
    EXPECT_CALL(mock, log("Hello World")).Times(1);

    mock.log("Hello World"); // Will be checked by gMock
}
```
- `MOCK_METHOD()` generates mock methods.
- `EXPECT_CALL()` sets up expectations.

---

## ONEMLI - Target Skill Level
- The goal is to master **gTest**, **gMock**, **CMake**, and **advanced C++ techniques**.
- Work through example projects like `gtest2.zip`.

---
