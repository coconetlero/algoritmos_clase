class Queue(object):
    """
    Implements a Circular Queue data structure
    """

    def __init__(self, size):
        self.max_size = size
        self.array = [None] * self.max_size
        self.head = 0
        self.tail = 0
        self.current_size = 0

    def __str__(self):
        s = str([x for x in self.array])
        return "Queue => " + s

    def is_full(self):
        """
        Test if the Queue is full.
        """
        if self.current_size == self.max_size:
            return True
        else:
            return False

    def is_empty(self):
        """
        Test if the Queue is empty.
        """
        if self.current_size == 0:
            return True
        else:
            return False

    def enqueue(self, data):
        """
        Inserts the specified element into this queue, if the capacity allows this
        operation. By definition the data is appended to the queue.
        """
        if not self.is_full():
            self.array[self.tail] = data
            self.tail += 1
            self.current_size += 1

            if self.tail == self.max_size:
                self.tail = 0
        else:
            print("Error - The Queue is full")
            return False

    def dequeue(self):
        """
        Retrieves the head of this Queue.
        """
        if not self.is_empty():
            data = self.array[self.head]
            self.head += 1
            self.current_size -= 1

            if self.head == self.max_size:
                self.head = 0

            return data
        else:
            print("Error - The Queue is empty")
            return False
