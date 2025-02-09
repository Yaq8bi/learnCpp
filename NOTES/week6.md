- std::tuple
- TYPED_TEST_SUITE_P();
- PDF is important.

## CMake
```cmake
minimum_required_version(VERSION 3.22)

project(stack)
set(CMAKE_CXXSTANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(test test.cpp)
target_link_directories(test PRIVATE )
```

## Faking || Link time substitution
1. header file, with a class of date.(Hes trying to teach us "faking").
2. 3 priv int: Year, Month, Day;
3. in the constructor he gets the date from the system using the chrono library.
   ```cpp
   //now is the tiime that is being counted second by second since 1970,010101...
   std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
   //System time will be convrted to int, in seconds.
   std::time_t time_temp = std::chrono::system_clock::to_time_t(now);
   //time converter?
   const std::tm *local_tm = std::localime(&time_temp);
    //Month starts from 0 and december will be 11(instead of 12).

    year = local_tm->tm_year + 1900;
    month = local_tm->tm_mon + 1;
    day = local_tm->tm_day;

   ```
4. Main
   ```cpp
   #include <iostream>
   #include "date.h"

   int main()
   {
   Date today;

   std::cout << today.getYear() << std::endl;
   }
   ```
5. Extracts data from a string: `std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);`

# INTERFACE || Runtime Substitution
- Is a class that includes purely virtual functions: For purposes of testing and production.
### gMock || Important

---
# ONEMLI - Bu seviyede olmaliyim.
### EXAMPlES: gtest2.zip
