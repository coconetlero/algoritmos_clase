import time

def binary_search(list, data, init, end):
    if init > end:
        return -1
    else:
        index = (init + end) // 2        
        if list[index] == data:
            return index
        else:
            if list[index] > data:
                return binary_search(list, data, init, index-1)
            else:
                return binary_search(list, data, index+1, end)


def search (list, data):
    idx = 0
    for d in list: 
        if d == data:
            return idx
        idx = idx + 1
    
    
    
# list generation
l = []
for i in range(20000):
    l.append(i)

start_time = time.time()
pos = binary_search(l, 18000, 0, len(l)-1)
elapsed_time = time.time() - start_time
print("time recursive \t", pos, elapsed_time)                



start_time = time.time()
pos = search(l, 18000)
elapsed_time = time.time() - start_time
print("brute force \t", pos, elapsed_time)                