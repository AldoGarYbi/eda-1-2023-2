biblioteca = []
cont = 0
conte = 0

while True:

    print("\nBiblioteca\n")
    print("\nSeleccione la opcion deseada: ")
    print("\n1-Agregar Libro")
    print("\n2-Eliminar Libro")
    print("\n3-Ordenar Biblioteca")
    print("\n4-Ver Biblioteca")
    print("\n5-Salir")

    elec = int(input())

    if elec == 1:

        cont += 1
        print("\nEscriba el nombre del libro que va a agregar: ")
        libro = input()
        biblioteca.append([libro , cont])

    elif elec == 2:

        print("\nEscriba el id del libro que desea eliminar: ")
        borrar = int(input())
        

        var3 = 0

        while var3 < cont-conte-1:

            if borrar in biblioteca[var3]:

                biblioteca.pop(var3)
                conte += 1
            
            var3 += 1


    elif elec == 3:

        print("\nEliga el tipo de orden:")
        print("1-Orden Alfabético")
        print("2-Orden por ID")
        opc = int(input())
        
        if opc == 1:

            biblioteca.sort()
        
        elif opc == 2:

            var = 0

            while var < cont-conte:

                temp = biblioteca[var][0]
                biblioteca[var][0] = biblioteca[var][1]
                biblioteca[var][1] = temp
                var += 1

            biblioteca.sort()
            
            var2 = 0

            while var2 < cont-conte:

                temp = biblioteca[var2][0]
                biblioteca[var2][0] = biblioteca[var2][1]
                biblioteca[var2][1] = temp
                var2 += 1

        else:

            print("No has elegido ninguna opcion valida")

        if opc == 1 or opc == 2:

            print("\nLa biblioteca se ha ordenado")

    elif elec == 4:

        print("\nBiblioteca: ")
        print(biblioteca)

    elif elec == 5:

        exit(0)

    else:

        print("No se ha digitado un valor valido, por favor digite un valor valido")