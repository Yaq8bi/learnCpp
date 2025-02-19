#!usr/bin/env python3

string = "Hello 320 a 83.2 World 989 Yes 76"

# num = ''.join(list(filter(str.isdigit, string)))
# print(num)

num = []
for v in string.split(): #split splits the numbers after spaces
    if v.isnumeric() and 1 <= len(v) <= 3:
        num.append(v)
        print(v, "is a decimal")
        
# 2) Write a Python program to validate an IPv4 address.
# IPv4 format is xxx.xxx.xxx.xxx and xxx shall be between 0 and 255.

ipV4Address: str = "192.168.128.341"
countTo4: int = 0

for n in ipV4Address.split("."):
    if n.isdigit(): 
        countTo4 += 1

result = "\nCorrect IPv4 Address" if countTo4 == 4 else "Wrong IPv4 Address"
print(result)

# 3) Write a Python program to replace whitespaces in a string,
# with an underscore and vice versa.

undrscr: str = "That_is_Spider man!"
        
# mask = str.maketrans("a n", "x N") replace a with x, n with N
mask = str.maketrans("_ ", " _")

undrscr = undrscr.translate(mask)
    
print(undrscr)

 
# 4) Write a Python program to validate and
# convert a date of yyyy-mm-dd format to dd/mm/yyyy format.

