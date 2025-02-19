import os 

os.system("gcc -c *.c; gcc *.o -o run && ./run; rm run *.o")
