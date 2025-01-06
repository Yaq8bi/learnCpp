<h1 style="color:orange">Modularity</h4>

---

#### Doxygen in header file. 
-  Functions from module should start with module name(check, dogru mu ve chatGPT ne diyor? nasil gorunur bu?)
- struct should not be in the .h(header file). **incomplete declaration**
---
#### Naming for modularity
- In embedded, the first func in module is initializatioin. 
- If module names are `LED.Cpp` | `LED.H` then the func should be       `LED_init();`.
  
- Always include the header file in the source file!
---
#### Variable Types
- **Extern:** Globally accesible.
- **Constexpr:** Similar to #define, used in Cpp.
    ```c++
  constexpr int len{10};
    int a{8};
    ```
- **Static:** Only way to access it, with the help of a "Helper function".

---

#### New & Deleete
1. **`New`** allocates memory, **`Delete`** deallocates the memory.

```cpp
  int *ptr = new int(10);//Allocate new block in memory that is of size 10 integers.

  delete ptr;
  ptr = nullptr;
```
2. To ***Dynamically*** allocate memory. 
```cpp
  int *ptr{new int};
```
---
#### Assert in Cpp
1. Useful when debugging, the final product shall not have any assert in the code.
```cpp
  static_assert( sizeof(int) == 4, "int must be 4 bytes!");
```

---
#### Important 
1. Include guards
  - If file is included, don't import.
2. No more `#define`. We use `constexpr`!
3. When working with *multi instance* module, we must have *create* and *destroy* funcions!
4. With single instance, we must have a *initialize* and a *deinitialize* functions.
5. If its *dymanic memory allocation*, **always clean afterwards**
   ```cpp
   free();
   ```
6. Pointer allocates how many bytes?
- En sevdigim numara...

## Last lecture with Faroch
[Screenshots](https://discord.com/channels/1023897516141461514/1319594548871299092)
1. Why Pointer?
  - Does not create a copy of value unlike other types.
  - important 
  - not safe to convert 1 pointer type to another pointer type.
2. Bu ne yapiyor?
  - `.person_t *person{reinterpret cast<person_t *>(array)};`
3. A pointer is an object.
  - This indicates that we can have a double pointer.
4. const pointer will lock the value, but not reassigning the address. const* infront of the first const to lock the adress aswell.
```cpp
  const int* const* ptr{&var};
```
5. R-Value expression:
   - `int &&rref{2 * var + 9};`
6. Type deduction:
   - `auto var{10};
7. Decltype:
- `decltype(2*var) i;` : Whatever type of "i" is, make the type of (2*var) of "that" type that var "i" has.
8. .
```cpp
  int var{10};

  auto func = [=/*when locking||consting the int value or an ampersand '&' for dynamic value */, b = 7](){
    var = 100;//would NOT work with ampersand '&'
    sd::cout << var * b << std::endl;
  }
```

## To-Do

- [] Visit pdf from week 51, tuesday.
- [] Ask Khan about this loop. What does the `(rptr - mtrxArr)` do?
```cpp
for (int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        printf("Row: %i", (rptr - mtrxArr));
    }
```
- []
---
### Tekrarla ve anla
1. week50, Exercise 10.
   - Cok onemli gorunuyor. Bu field'ta pointerlar onemli, bu loopu kullan ve anlamaya calis.
2. Exercise 14'te Bool ve compare_t olan fonksiyonlari pek anlamadim. Tekrarla ve anla!
---
<h1 style="color:blue; font-family:cursive; -webkit-text-stroke: 2px red;">C++</h1>

#### Check if input it's number
```cpp
if(std::cin.fail()){
  elem.age = -1;
  std::cin.clear();
  std::cin.ignore(std::numberic_limits<std::streamsize>::max(), '\n');
}
```

#### Sleep in C++
```cpp

  #include <thread>//CPU thread funcs.
  #include <chrono>//Miliseconds counter.

   std::this_thread::sleep_for(std::chrono::milliseconds(200));
```

### VECTOR
```cpp
#include <vector>

std::vector<int> emptyVector(5); //a empty vector of int elements.
std::vector<int> numVector = {1,2,3}; // Initialized with 3 integers.

```
1. Array gibi ama 