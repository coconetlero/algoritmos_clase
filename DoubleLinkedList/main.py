from list import *

list = List()

list.add_back(5)
print("add 5")
print("list size =", list.size())
list.add_back(7)
print("add 7")
print("list size =", list.size())
list.add_back(21)
print("add 21")
print("list size =", list.size())

list.add(2, 11)
print("Add 11 in the thirth position")
print("list size =", list.size())

print(list)

list.remove(3)

print(list)

list.remove(0)

print(list)
