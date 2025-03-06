

class A: # A singleton Class
    names = []
    counter = 0
    MAX_INSTANCE = 2
    
    # private member
    __private_member = "Secret User"
    def helperFunc():
        A.__print_secret()
    def __print_var():
        print(A.__private_member)
    # private members
    
    def __new__(cls, *args, **kargs):
        if cls.counter >= cls.MAX_INSTANCE:
            raise ValueError("Cannot create more than 2 instances")
        counter += 1
        return super().__new__(cls)
    
    def __init__(self, num):
        self.number = num
    
    def append_name(self, name):
        self.names.append(name)
        
    @staticmethod
    def func(num):
        print(num)
    
    def __del__(self):
        A.counter -= 1
        print("__del__")
        
        
anInstance = A
# del A
instance2 = A
instance3 = A
instance4 = A

print(anInstance.names)
anInstance.append_name(anInstance, "INFJ")
print(anInstance.names)


