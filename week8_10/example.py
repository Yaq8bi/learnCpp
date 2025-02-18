#!/usr/bin/env python3

# [to run without compiling, pythone3 example.py]
# python3 -m py_compile example.py
# after compiling using =>  make the output file an executable using [chmod +x example.py]
import sys

a = 12
b = 24

a, b = b, a #a and b, swapped.

if a is 24 and b is 12:
    print("The swap worked!")
else:
    print("The swap did not work!")



bool1: bool = False
bool2: bool = False

name: str = "Gojom"


if bool1 is not True and bool2 is False:
    print(name[0:-1])#from char 0, upto 1 char before end.
    #print(name[::-1]) to reverse the string.
    
    

# ARguments from terminal [ofcourse the "import sys", must be included]
print(sys.argv)
if len(sys.argv) >= 1:
    print("Terminal Arguments are more than 1")

# print(a+b,  "hello")