#!/usr/bin/env python3

theInt: int = 0 # to check the max range
theCounter: int = 1
theFactorial: int = 1 #to keep and print the total/factorial 1*2*3*4*5*6

while theInt < 1: #while theInt is less than 1
   theInt = int(input("Input a number greater than 0: ")) #take convert to int(input taken from user)

while theCounter <= theInt:
    print("The counter is: ",theCounter)
    theFactorial *= theCounter
    theCounter += 1

print("The factorial is: ", theFactorial)
