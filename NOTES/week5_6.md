# LINUX

- Stop update notifier
1.  `sudo nano etc/update-manager/release-upgrades`
2.  change last line to `=never`

---
### What does it do
- Manage resources.
- Manage users.
- Manage files.
-> RTOS: Real time operating systems.
---
## Kernel
Responsibility:
- Manages processor and memory: Context switching(tasks switching).
- Later we will learn multitask/multithreading.
- Interthread communication.
- Driver to drive the device.

-> Abstraction layer, a virtual files system that makes it possible to support multiple file types.
-> Zafer?
---
## Architecture
- **Monolithic Kernel** with a *modular design*.
    Meaning a ***heavy*** kernel: good example `Freeartus`, `Zefer`.
- **H K S A U**: The layer names, each being built upon the layer under => Hardware, Kernel, Shell, Applications, Users.

-> A **scheduler** is run in the *kernel*.
-> Shell is the interface between *Kernel* and the *Application*.
---
## Terminal
- ls A*.txt : Any file that starts with A.
- ls My???: Any file that starts with MyXXX and the XXX being placeholder letters.
- ls [a-p0-5]*.*
- ls ~ and /home/Ahmet are the same, they will list the users files.
- ls -a: List all, even the hidden files.
---
## MKDIR
- mkdir -p(parent) Hello/World =>Hello will be the parent folder, world will be the child folder.
---
## Shortcuts
- Hardlinks: `ln fileName.txt nameOfLink.txt`.
- Softlinks: `ln -s fileName.txt nameOfLink.txt`.
---
## Persmisions
- ls -l: lists permisions.
- r: Read w: Write x: Execute
- -: 0
---
## important
- touch text.txt: if the file already exists, the timestamp of the file gets updated.
- pip operator `cat file.txt | sort`.
---
# GCC
- A very large, million line of code compiler.
- Supports multiple language including C, C++, Objective C, Objective C++, Go.
### Preprocessor & Compilation with GCC
1. Preprocessor: `g++ -E main.cpp -o main.ii` : Store the preprocessed code in that file. Error checking will be skipped.
2. Assembly: `g++ -S main.cpp`
3. Assembler translates assembly to machine code `g++ -C main.cpp -o main.o`
   `-D name[=definition]` : Define a macro.
   `-U name` : to undefine a macro.
   `-I directory` : Include path to a file.
   `-S -fverbose-asm main.cpp`
4. `.a` extension libraries are static libraries.
5. `-l nameOfMyLibrar.(a[stands for archieve] or .so[shared object])` to include my own librraies.
6. Static will include the library to your executable. But with the Dynamic, it will be loaded to the memory  and different programs will use the librrary simultanously. Example `-L`.
7. `-fPIC` While compiling, Position Independent Code: For sourcefiles, when compiling into an object file(.o). 
8. `ar -crv lib<libraryName>.a fil1.o file2.o file3.o`
9. 
---
# CMAKE & MAKE FILE
1. .c to .o
2. .o to .a
3. ``nm main`
4. `objdump main`
5. `strings main.o`
6. What is name-mangliing? (faroch said its a feature that C++ doesn't have).
7. `extern "C" void aRndmFunction(){}` (in main.cpp, :we're telling the compiler to not change this function, treat it like C?)
8. 1dd main (to see the shared libraries).
9. `g++ -pg main.cpp -o main && ./main && gprof ./main` -pg (Adds profiling for latter analysis) gprof (to generate graph) : used for analyzing speed it takes, performance of executable.
10. -Wall(warning all) -Werror(fail on all warniing) -Wextra(legal but questionable) -Wconversion(Get warnings on implicit type casting).

### Important!
#### CONCEPT
- 1.CPP 1.HPP => 1.O
- 2.MAIN.CPP 2.HPP => 2.O 
=> The .o object files compiled into a executable.exe
- 3.MAIN.CPP 3.HPP => 3.O
  
  But that way is not maintainable.
  #### Alternatives:
  1. Shellscript.
  2. Make: 
        1. Make works on rules with its own unique syntax.
        2. Uses files timestamps to figure out if a file is changed or not.
        3. `Makefile fileName`
        4. Write the rule in a file

#### RULES
1. Targets: dependencies:
   - Checks if any of the dependencies have been modified, it will run its compilation process if timestamp for the data.cpp does not match data.o
   - Example => 
   ```makefile
    <TAB keypress required>data.o: data.cpp data.h
    g++ -c data.cpp
2. Recursively vs Simply expended variable.
   - Recursively => Like a reference. => `X = hello   Y = $(X)` We can say that Y is a reference to X, if Y is changed, so will the X.
   - Simply => Like a normal variable => `X := world`
3. To make a command silent/not print to terminal, add '@' infront of the command.
4. `-B` (make all the files, assume they are all out of sync in their timestamps)

---
## Good to learn:
[] Directories
[] 

## I should read:
- https://www.geeksforgeeks.org/constructors-c/
- 