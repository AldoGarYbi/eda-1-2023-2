import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import random

times=0
global times2
global times3

def insertionSort_graph(n_lista):
    global times
    for index in range(1, len(n_lista)):
        times+=1
        actual = n_lista[index]
        posicion = index
        while(posicion>0 and n_lista[posicion-1]>actual):
            times+=1
            n_lista[posicion]=n_lista[posicion-1]
            posicion=posicion-1
        n_lista[posicion]=actual
    return n_lista

def merge_graph(arr1, arr2):
        
    result = []
    
    i = 0 
    j = 0
    
    while i < len(arr1) and j < len(arr2):
        
        
        if arr1[i]<arr2[j]:
            result.append(arr1[i])
            i+=1
        else:
            result.append(arr2[j])
            j+=1
            
    if i == len(arr1):
        for k in range(j, len(arr2)):
            
            result.append(arr2[k])
        
    if j == len(arr2):
        for k in range(i, len(arr1)):
            
            result.append(arr1[k])
    
    return result



def merge_sort(arr):
    
    times2 = 0
    
    times2+=1
    
    if len(arr) < 2:
        return arr
    else:
        mitad = (len(arr))//2
        arr1 = merge_sort(arr[:mitad])
        arr2 = merge_sort(arr[mitad:])
        
        return merge_graph(arr1, arr2)
        
def quicksort(arreglo, izquierda, derecha):
    
    global times3
    
    times3+=1
    
    if izquierda < derecha:
        indiceParticion = particion(arreglo, izquierda, derecha)
        quicksort(arreglo, izquierda, indiceParticion)
        quicksort(arreglo, indiceParticion + 1, derecha)


def particion(arreglo, izquierda, derecha):
    pivote = arreglo[izquierda]
    while True:

        while arreglo[izquierda] < pivote:
            
            izquierda += 1

        while arreglo[derecha] > pivote:
            
            derecha -= 1


        if izquierda >= derecha:
          
            return derecha
        else:
            
            arreglo[izquierda], arreglo[derecha] = arreglo[derecha], arreglo[izquierda]


            izquierda += 1
            derecha -= 1

        
TAM = 101
eje_x = list(range(1, TAM, 1))
eje_y = []
lista_variable = []

for num in eje_x:
    
    lista_variable = random.sample(range(0, 1000), num)
    print(lista_variable)
    times = 0
    lista_variable = insertionSort_graph(lista_variable)
    eje_y.append(times)
    
print(lista_variable)


fig, ax = plt.subplots(facecolor = 'w', edgecolor='k')
ax.plot(eje_x, eje_y, marker="o", color="b", linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Insertion Sort"])

plt.title("Insertion Sort")
plt.show()

eje_x2 = list(range(1, TAM, 1))
eje_y2 = []
lista_variable2 = []

for num2 in eje_x2:
    
    lista_variable2 = random.sample(range(0, 1000), num2)
    print(lista_variable2)
    times2 = 0
    lista_variable2 = merge_sort(lista_variable2)
    eje_y2.append(times2)
    
print(lista_variable2)


fig, ax = plt.subplots(facecolor = 'w', edgecolor='k')
ax.plot(eje_x2, eje_y2, marker="o", color="r", linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Merge Sort"])

plt.title("Merge Sort")
plt.show()

eje_x3 = list(range(1, TAM, 1))
eje_y3 = []
lista_variable3 = []

for num3 in eje_x3:
    
    lista_variable3 = random.sample(range(0, 1000), num3)
    print(lista_variable3)
    times3 = 0
    quicksort(lista_variable3, 0, len(lista_variable3)-1)
    eje_y3.append(times3)
    
print(lista_variable3)


fig, ax = plt.subplots(facecolor = 'w', edgecolor='k')
ax.plot(eje_x3, eje_y3, marker="o", color="y", linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Quick Sort"])

plt.title("Quick Sort")
plt.show()
