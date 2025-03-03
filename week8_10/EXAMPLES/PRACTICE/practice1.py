import json

try:
    with open('data.json') as file:
        try:
            tableFromJson = json.load(file)
        except:
            print("FAILED")
            exit(1)

except:
    print("FAILED")
    exit(1)

peopleCloseCircle = tableFromJson['persons']
del tableFromJson

persons = {
    "name": "Name",
    "length": "200",
    "mbti": "XXXX"
}

size = {} #dictionary to hold size of chars
for key in persons: # loop through persons, iterate key
    size[key] = len(persons[key])  # loop1: Size{ "name": "Name"}. 
    
for person in peopleCloseCircle: # for 1person in dataInJsonFile
    for items in person: # Items of the person(1 line from json data)
        length = len(str(person[items])) # chars of item, we loop to hold the item that has the most chars.
        if size[items] < length: # If size of the items, are less then size 
            size[items] = length 
            
            

for persons in peopleCloseCircle:
    length = str(persons['length']).rjust(size['length'] // 2+1)
    print("Name: {} | Height: {} | MBTI: {}".format(
        persons['name'].ljust(size['name']),
        
        length.ljust(size['length']),
        
        persons['mbti'].upper().ljust((size['mbti']))
    ))





            

# Ahmet = {
#     "name": "Ahmet",
#     "birthdate": 2002
# }
# Arinah = {
#     "name": "Arinah",
#     "birthdate": 2003
# }
# currentYear = 2025
# age = currentYear - Ahmet["birthdate"], currentYear - Arinah["birthdate"]

# print("Ahmet is {} years old, Arinah is {}".format(age[0], age[1]))

# Love = True

# Marry = Love if abs(Ahmet["birthdate"] - Arinah["birthdate"]) <= 10 else False

# if Marry:
#     print("Old enough to marry")
# else:
#     print("Too old to marry")


# mylist = ["Bye"]
# mylist.append("Hello")

# mylist.extend(['My Friend', 3.14])

# tempList = [mylist[0], mylist[1]]

# mylist[0] = tempList[1]
# mylist[1] = tempList[0]

# print(mylist)