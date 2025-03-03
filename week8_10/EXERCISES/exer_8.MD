
Official string documentation:
https://docs.python.org/3/library/stdtypes.html

 

# 1. Create a new string by concatenating string a and string b
string_a = "This is"
string_b = " the way!"
new_string = <ADD CODE HERE>
print(new_string)


# 2. Create a lower case version of the following string (Hint: take a look at the string documentation for str.lower())
input_string = 'This Is The String'
lowercase_string = <ADD CODE HERE>
print(lowercase_string)


# 3. Create an upper case version of the following string
input_string = 'This Is The String'
uppercase_string = <ADD CODE HERE>
print(uppercase_string)


# 4. Does the string start with an 'S'?
string = 'Begin at once'
result = <ADD CODE HERE>
print(result)


# 5. Does the string end with a '.'?
string = 'The end.'
result = <ADD CODE HERE>
print(result)


# 6. Find the index of the first instance of 'and' (Hint: see str.find())
string = '"Tell me and I forget. Teach me and I remember. Involve me and I learn." -Benjamin Franklin'
index = <ADD CODE HERE>
print('Index:', index)
print('Content:', string[index:index+3])


# 7. Split the string at each comma into several strings in a list (Hint: str.split())
string = 'apples,bananas,cherries,dates'
fruit_list = <ADD CODE HERE>
for fruit in fruit_list:
    print('Fruit:', fruit)


# 8. Print out the number of items in the list
number_list = [45, 65, 2, 4, 10, 94, 23, 54, 2, 54]
list_length = <ADD CODE HERE>
print(list_length)


# 9. Print out the number of characters in the string
quote = '"Whoever is happy will make others happy too." -Anne Frank'
quote_length = <ADD CODE HERE>
print(quote_length)

 

# 10 Print out the values using string formatting
side_a = 2
side_b = 6
area = side_a * side_b
print('The area of a rectangle with sides {} and {} is {}'.<ADD CODE HERE>)

 

# 11 Print out the number of apples and oranges in a string using string formatting
basket = { 'apples': 10, 'oranges': 2 }
summary = <ADD CODE HERE>
print(summary)


# 12. Print out the quote inserting the strings in its respective places using string formatting.
name = 'Sir Lancelot of Camelot'
quest = 'To seek the Holy Grail'
favourite_colour = 'Blue'

quote = '''
Bridgekeeper: What is your name?
Lancelot: My name is <ADD CODE HERE>.
Bridgekeeper: What is your quest?
Lancelot: <ADD CODE HERE>.
Bridgekeeper: What is your favourite colour?
Lancelot: <ADD CODE HERE>.
Bridgekeeper: Right. Off you go.
'''
print(<ADD CODE HERE>)