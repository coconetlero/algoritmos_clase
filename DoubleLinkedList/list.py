class Node(object):
    def __init__(self, data, prev, next):
        self.data = data        
        self.prev = prev
        self.next = next

class List(object):
    def __init__(self):
        self.head = None
        self.tail = None
        
        
    def is_empty(self):
        if self.head == None:
            return True
        else:
            return False
    
    
    def append(self, data):
        node = Node(data, None, None)

        if self.is_empty():
            self.head = node
            self.tail = node
        else :
            node.prev = self.tail;
            node.next = None;
            self.tail.next = node;
            self.tail = node;
            
    def pop_head(self):
        if not(self.is_empty()):
            node = self.head;

            if (self.head.next != None): 
                self.head = self.head.next;
                self.head.prev = None;
            else:
                self.head = None;
                self.tail = None;    
          
            return node.data;                    
        else:
            print("Error: the list is empty \n");    
            return None;
        
            

    def print(self):
        print("[", end="")
        
        current = self.head
        while current.next != None:
            print(current.data, ", ", end="")
            current = current.next
            
        print(current.data, "]")


        
l = List()
l.append(4)
l.append(5)
l.append(3)
l.append(6)
l.print()

print(l.pop_head())
print(l.pop_head())
l.print()        
            
        