def decimalBinario(num):
    if num == 0:
        return 0
    else:
        return (num % 2 + 10 * decimalBinario(int(num // 2)))

lista = []

def fibonacci(num):
    if num <= 1:
        return 1
    else:
        return (fibonacci(num-1) + fibonacci(num-2))
    
def printFibo(nterms):
    if nterms <= 0:
        print("Ingrese un entero positivo")
    else:
        print("Secuencia de Fibonacci del mayor al menor:")
    for i in range(nterms-1, -1, -1):
        lista.append(fibonacci(i))
    
    print(lista)

while True:

    print("\nRecursividad\n")
    print("\nSeleccione la opcion deseada: ")
    print("\n1-Convertir a binario")
    print("\n2-Serie de Fibonacci")
    print("\n3-Salir")

    elec = int(input())

    if elec == 1:
        print("Digite el numero a convertir a binario: ")
        opc = int(input())

        print(f"El numero en binario es: {decimalBinario(opc)}")

    elif elec == 2:
        print("Digite hasta que numero de la serie de Fibonacci desea obtener")
        opc = int(input())

        printFibo(opc)

    elif elec == 3:

        exit(0)

    else: 

        print("No ha digitado ningun valor valido, por favor digite un valor valido.")
