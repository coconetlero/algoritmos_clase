class Node(object):
    def __init__(self, data, prev, next):
        self.data = data
        self.prev = prev
        self.next = next


class List(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def __str__(self):
        string = "List => ["
        current = self.head
        while current is not None:
            string += str(current.data)
            if current.next is not None:
                string += ", "
            current = current.next

        string += "]"
        return string

    def is_empty(self):
        """
        test if this Linked List is empty
        """
        if self.head is None:
            return True
        else:
            return False

    def size(self):
        """
        Returns the number of elements in this list.
        """
        if self.is_empty():
            return 0
        else:
            current = self.head
            counter = 1

            while current.next is not None:
                counter += 1
                current = current.next
            return counter

    def add(self, index, data):
        """
        Inserts the specified element at the specified position in this list.
        """
        node = Node(data, None, None)

        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            current = self.head
            counter = 0
            while counter != index:
                if current.next is None:
                    print("Error: the index is out of bounds")
                    return None
                else:
                    current = current.next
                    counter += 1

            node.prev = current.prev
            node.next = current
            current.prev.next = node
            current.prev = node

    def add_front(self, data):
        """
        Inserts the specified element at the beginning of this list.
        """
        node = Node(data, None, None)

        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            node.prev = None
            node.next = self.head
            self.head.prev = node
            self.head = node

    def add_back(self, data):
        """
        Inserts the specified element at the end of this list.
        """
        node = Node(data, None, None)

        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            node.prev = self.tail
            node.next = None
            self.tail.next = node
            self.tail = node

    def remove(self, index):
        """
        Removes and returns the element in the index position on the list.
        """
        if not self.is_empty():
            current = self.head
            counter = 0
            while counter != index:
                if current.next is None:
                    print("Error: the index is out of bounds")
                    return None
                else:
                    current = current.next
                    counter += 1

            current.prev.next = current.next
            current.next.prev = current.prev
            return current.data
        else:
            print("Error: the list is empty \n")
            return None

    def remove_front(self):
        """
        Removes and returns the first element from this list.
        """
        if not self.is_empty():
            node = self.head

            if (self.head != self.tail):
                self.head = self.head.next
                self.head.prev = None
            else:
                self.head = None
                self.tail = None

            return node.data
        else:
            print("Error: the list is empty \n")
            return None

    def remove_back(self):
        """
        Removes and returns the last element from this list.
        """
        if not self.is_empty():
            node = self.tail

            if (self.head != self.tail):
                self.tail = self.tail.prev
                self.tail.next = None
            else:
                self.head = None
                self.tail = None

            return node.data
        else:
            print("Error: the list is empty \n")
            return None

    def get(self, index):
        """
        Returns the element in the index position on the list.
        """
        if not self.is_empty():
            current = self.head
            counter = 0
            while counter != index:
                if current.next is None:
                    print("Error: the index is out of bounds")
                    return None
                else:
                    current = current.next
                    counter += 1

            return current.data
        else:
            print("Error: the list is empty \n")
            return None

    def get_front(self):
        """
        Returns the first element from this list.
        """
        if not self.is_empty():
            return self.tail.data
        else:
            print("Error: the list is empty \n")
            return None

    def get_back(self):
        """
        Returns the last element from this list.
        """
        if not self.is_empty():
            return self.tail.data
        else:
            print("Error: the list is empty \n")
            return None

    def index_of(self, data):
        """
        Returns the index of the first occurrence of the specified element in this list,
        * or -1 if this list does not contain the element.
        """
        if not self.is_empty():
            current = self.head
            counter = 0
            while current.data != data:
                if current.next is None:
                    print("Error: the serched element is not in the list")
                    return -1
                else:
                    current = current.next
                    counter += 1

            return counter
        else:
            print("Error: the list is empty \n")
            return None
