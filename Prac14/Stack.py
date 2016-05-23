class Stack(object):

    def __init__(self, size):
        self.max_size = size
        self.array = [None] * self.max_size
        self.top = -1        

    def __str__(self):
        """
        print the stack    
        """
        return str([x for x in self.array])

    def push(self, data):
        """
        insert one element to the top of the stack
        """
        if self.top != self.max_size - 1:
            self.top += 1
            self.array[self.top] = data
        else:
            print("Error -> The stack is full")
    
    def pop(self):
        """
        return and remove the data contained at the top of the stack
        """
        if self.top >= 0:
            data =  self.array[self.top]
            self.top -= 1
            return data    
        else:
            print("Error -> The stack is empty")    
        
        
## test the stack        
if __name__ == '__main__':
    stack = Stack(5)
    print("stack =>", stack)
    stack.push(4)
    stack.push(12)
    stack.push(34)
    print("stack =>", stack)
    
    data = stack.pop()
    print("pop = ", data)
    data = stack.pop()
    print("pop = ", data)
    
    print("stack =>", stack)
    stack.push(7)
    stack.push(56)
    stack.push(78)    
    stack.push(98)
    stack.push(1029)
    print("stack =>", stack)
    