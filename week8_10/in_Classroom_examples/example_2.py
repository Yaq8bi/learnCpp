a,b = 10, 1

try: 
    
    if a % 2 == 0:
        raise ValueError("Undivisible") #raise: prints a message that is seen as an error in terminal.
    print(a/b)
    
except (Exception, OSError) as exp:
    print(type(exp), exp)
    
    

printAmount: int = 15 
try:
    with open("file.txt", "wt") as file:
        
     for i in range(printAmount):
        file.write("{0}) Domain Expansion\n".format(i +1))
        pass
except:
    print("Error")
    
    
#READ
try:
    with open("file.txt", "rt") as file:
        # lines = file.readlines()
        # print(lines)
        # file.seek(0) #set the cursor back to start of file.
        for i in range(printAmount):
            l = file.readline()
            print(l) #print one line
        print("Size of the file is: {0}".format(file.tell()))
        
        
        lines = file.readlines()
        if len(lines) >= 10:
            print(lines[14].strip())
        else:
            print("Line 15 does not exist")
except:
    print("error")    