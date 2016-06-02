from queue import *


q = Queue(5)
print(q)

d = q.dequeue()

q.enqueue(20)
q.enqueue(10)
q.enqueue(23)
print(q)

d = q.dequeue()
print(d)
d = q.dequeue()
print(d)
print(q)

q.enqueue(15)
q.enqueue(7)
q.enqueue(19)
print(q)

d = q.dequeue()
print(d)
d = q.dequeue()
print(d)

q.enqueue(31)
print(q)

q.enqueue(27)
q.enqueue(1)
q.enqueue(9)
