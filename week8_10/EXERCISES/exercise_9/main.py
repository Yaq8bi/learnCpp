# Description
# Do exercise 5, but load the message from data.json file.

# import and use the json module.

#!usr/bin/env python3
import json

try:
    with open('data.json') as file:
        try:
            message = json.load(file)
        except:
            print("FAILED TO PARSE")
            exit(1)
except:
    print("FAILED TO OPEN")
    exit(1)



signals = message['signals']
del message 

title = { # dictionary of titles(names)
    "name": "Signal",
    "type":"Type",
    "length": "Length",
    "comment": "Description"
}

size = {} #dictionary
for key in title: # Key iterates through title names.
    size[key] = len(title[key]) # size{} dictionary gets assigned title name, and holds number of the amount of letters.
    print("SIZE[key]: {} --- TITLE[key]: {}".format(size[key], title[key] ))


for signal in signals:
    print("SIGNAL IS: {}".format(signal))
    for key in signal:
        print("KEY IS: {}".format(key))
        length = len(str(signal[key]))
        if size[key] < length:
            size[key] = length
             


print("\n{} | {} | {} | {}".format(
    title['name'].ljust(size['name']),
    title['type'].ljust(size['type']),
    title['length'].ljust(size['length']),
    title['comment'].ljust(size['comment'])))

print('-' * (sum(size.values()) + 9))

for siganl in signals:
    length = str(siganl['length']).rjust(size['length'] // 2 + 1)
    print("{} | {} | {} | {}".format(
        siganl['name'].ljust(size['name']),
        siganl['type'].ljust(size['type']),
        length.ljust(size['length']),
        siganl['comment'].capitalize().ljust(size['comment'])))
