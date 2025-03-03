#!usr/bin/env pyton3

# 1. Create a new string by concatenating string a and string b
string_a = "This is"
string_b = " the way!"
new_string = string_a + string_b
print(new_string)

# 2. Create a lower case version of the following string (Hint: take a look at the string documentation for str.lower())
input_string = 'This Is The String'
lowercase_string = input_string.lower();
print(lowercase_string)

# 3. Create an upper case version of the following string
input_string = 'This Is The String'
uppercase_string = input_string.upper();
print(uppercase_string)

# 4. Does the string start with an 'S'?
string = 'Begin at once'
result = "Starts with the letter S" if string[0] is 'S' else "Does not start with the letter S"
print(result)

# 5. Does the string end with a '.'?
string = 'The end.'
result = "Ends with a dot" if string[-1] is '.' else "Does not end with a dot"
print(result)

# 6. Find the index of the first instance of 'and' (Hint: see str.find())
string = '"Tell me and I forget. Teach me and I remember. Involve me and I learn." -Benjamin Franklin'
index =  string.find('and')
print('Index:', index)
print('Content:', string[index:index+3]) #[start at this postion:end at that + the number of letters it is.]

# 6. Find the index of the first instance of 'and' (Hint: see str.find())
string = '"Tell me and I forget. Teach me and I remember. Involve me and I learn." -Benjamin Franklin'
index =  string.find('Tell')
print('Index:', index)
print('Content:', string[index:index+4]) #[start at this postion:end at that + the number of letters it is.]

# 7. Split the string at each comma into several strings in a list (Hint: str.split())
string = 'apples,bananas,cherries,dates'
fruit_list = string.split(',')
for fruit in fruit_list:
    print('Fruit:', fruit)

# 8. Print out the number of items in the list
number_list = [45, 65, 2, 4, 10, 94, 23, 54, 2, 54]
list_length = len(number_list)
print(list_length)

# 10 Print out the values using string formatting
side_a = 2
side_b = 6
area = side_a * side_b
print('The area of a rectangle with sides {} and {} is {}'.format(side_a, side_b, area))

# 11 Print out the number of apples and oranges in a string using string formatting
basket = { 'apples': 10, 'oranges': 2 }
summary = basket['apples'], basket['oranges']
print(summary)


# 12. Print out the quote inserting the strings in its respective places using string formatting.
name = 'Sir Lancelot of Camelot'
quest = 'To seek the Holy Grail'
favourite_colour = 'Blue'

quote = '''
Bridgekeeper: What is your name?
Lancelot: My name is {}.
Bridgekeeper: What is your quest?
Lancelot: {}.
Bridgekeeper: What is your favourite colour?
Lancelot: {}.
Bridgekeeper: Right. Off you go.
'''.format(name, quest, favourite_colour)
print(quote)
