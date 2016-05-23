import random
from time import time

def insertion_sort(list):
    for index in range(1, len(list)):
        current = list[index]
        position = index

        while position > 0 and list[position - 1] > current:
            list[position] = list[position - 1]
            position = position - 1

        list[position] = current

    return list


def merge_sort(list):

    if len(list)  <= 1:
        return list

    left = []
    right = []

    for i in range(len(list)):
        if (i % 2) != 0:
            left.append(list[i])
        else:
            right.append(list[i])

    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)


def merge(left, right):
# merge process in merge sort algorithm
    result = []

    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    while left:
        result.append(left.pop(0))

    while right:
        result.append(right.pop(0))

    return result
    


# ---------------------- test sort algorithms -----------------------
step = 500
size = 10000

insert_time = []
merge_time = []

while step <= size:

    list = [None] * size

    for i in range(size):
        list[i] = random.randint(0, 100)

    t1 = time()
    insertion_sort(list)
    t2 = time()
    insert_time.append(t2 - t1)

    t1 = time()
    merge_sort(list)
    t2 = time()
    merge_time.append(t2 - t1)

    size += 500


    
print("Insertion sort execution time:")
for d in insert_time:
    print(d)
        
print("Merge sort execution time:")
for d in merge_time:
    print(d)


    
    
    
        
