#!/usr/bin/env python3

string: str = input("Input a string: ")
position: int = 0

for i in string:
    position += 1
    
    if i.isupper():
        print(position)
        
