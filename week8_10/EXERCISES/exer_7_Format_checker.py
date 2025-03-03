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
ipV4Address: str = "192.168.128.241"
countTo4: int = 0

for n in ipV4Address.split("."):
    if n.isdigit(): 
        if int(n) <= 255:
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
# date: str = '01-2002-08'
date: str = '2025-12-31'
dateValues = [0, 0, 0]
flag: bool = False

i: int = 0
for num in date.split('-'):
    numberToInt = int(num)
    
    if len(num) == 4:
        dateValues[0] = numberToInt
    elif len(num) == 2: 
        if dateValues[1] == 0:
            dateValues[1] = numberToInt
        else:
            dateValues[2] = numberToInt   
    i += 1
print("\vDate in USA format: {2}/{1}/{0}".format(dateValues[0], dateValues[1], dateValues[2]))
# print("\vDay: {2}\nMonth: {1}\nYear: {0}".format(dateValues[0], dateValues[1], dateValues[2]))
        
        
# 5) Write a Python program to
# find all words starting with 'a' or 'e' in a given string.

findWords: str = "Write an amazing Python program to search for an un ending decimal numbers which have min. one and max. three digits, in a given string. That was the end of the requirements."
findWords.lower()

for oneWord in findWords.split(" "):
    if 'a' in oneWord[0] or 'e' in oneWord[0]:
        print(oneWord) 