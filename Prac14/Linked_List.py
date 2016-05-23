class Node(object):
    
    def __init__(self, data):
        self.next = None
        self.data = data
        
    def __str__(self):
        return str(self.data)

class Linked_List(object):
    
    def __init__(self):
        self.head = None
        self.tail = None

    def __str__(self):
        if self.head != None:
            nodes = []
            current = self.head
            while current != None:
                nodes.append(current)
                current = current.next         
            return str([str(x) for x in nodes])
        else:
            return "List is empty"
                
                        
    def is_empty(self):
        """
        test if the list is empty 
        """
        if self.head == None:
            return True
        else:
            return False
    
    
    def append(self, data):
        """
        Add the data to the end of the list
        """
        node = Node(data)

        if self.is_empty():
            self.head = node
            self.tail = node
            node.next = None            
        else:
            self.tail.next = node
            self.tail = node
            node.next = None
    
    
    
    
## test the stack        
if __name__ == '__main__':
    
    list = Linked_List()
    print(list)
    
    list.append(5)
    list.append(35)
    list.append(23)
    
    print(list)
            
    