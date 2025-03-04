import os # mkdir
from pathlib import Path # absolute path path = Path(___file__).parent

directory_name = "testFolder"

mainWord = "main"
cppName = 'cpp'
found: bool = False
mainCppPath = ""

# while found == False:
           
for entry in os.scandir(directory_name): # Scans the folder(where python script is running) Entry(every document inside)
    if entry.is_file() and entry.name.endswith('.cpp'): # If the entr/doc is a file.
        print("***STARTING TO SEARCH FOR THE FILES***")
        
        
        if entry.name.endswith('.cpp'): # If the name of the (current/this iteration) of files'(im in a loop) ends with '.cpp' do  the indentation below. 
            print("cpp file is found: {}".format(entry)) # Print the name of he file.
            with open(entry.path, 'r') as testFile: # Open the current iteration of file, because .cpp is found, with 'r' to read contnents(while still in the loop)
                 for line in testFile: # for each loop, in the testFile.
                      index = line.find(mainWord) # find the 'mainWord' in line using the find method, assign the return value to index.
        
                      if index == -1: # if it is not -1, it means the word was found, as .find() returns position of the first letter. If it doesn't find then -1 is returned.
                          print(f"{mainWord} is not found in the file")
                          break
                      else:
                          print(f"{mainWord} is found!")
                          oneLine = str(line.strip().split(' '))
                        #   if mainWord in oneLine:
                          if oneLine.find('main') != -1:
                               print(f"{mainWord.capitalize()} is found in {entry}")
                               found = True
                               
                               break
                          else:
                              print(f"{mainWord.capitalize()} WAS NOT FOUND IN ANY OF THE FILES!")
                              exit(1)
            if found == True:# to break the outermost loop(iterating through the files).
                break
            
