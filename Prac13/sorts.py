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
    



# Ejercicio:
# 1.- Implementar merge sort 
# 2.- generar listas de numeros aleatorios 
# 3.- comparar tiempos con merge sort


# def merge_sort(list):


lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("lista desordenada {}".format(lista))
insertion_sort(lista)
print("lista ordenada {}".format(lista))