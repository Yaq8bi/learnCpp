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
---
- **Static:** Only way to access it, with the help of a "Helper function".

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
---
6. Pointer allocates how many bytes?
- En sevdigim numara...


## To-Do

[] Visit pdf from week 51, tuesday.
