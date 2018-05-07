	.module cadenas

    ;hacemos que todo pueda ser usado en el resto de ficheros
	.globl menu
	.globl instrucciones
	.globl elementos
	.globl mensaje_lista
	.globl introduce
	.globl mensaje_limite
	.globl pausa

menu:   .ascii "    Menu del programa"
        .byte 10
        .byte 10
        .ascii " 1) Empezar"
        .byte 10
        .ascii " 2) Mostrar las instrucciones"
        .byte 10
        .ascii " 3) Salir"
        .byte 10
        .byte 10
        .ascii " Opcion: "
        .byte 0
        
instrucciones:

.ascii "1 para empezar la ejecucion del programa:"
.byte 10
.ascii "Llena una lista de numeros, si introduces un 0 se acaba esta parte."
.byte 10
.ascii "Se muestra la lista y el numero de elementos que tiene."
.byte 10
.ascii "Mete un numero para eliminar todos los superiores o iguales a ese."
.byte 10
.ascii "Se muestra la lista actualizada y el numero de elementos que le quedan."
.byte 10
.byte 10
.ascii "2 para ver las instrucciones"
.byte 10
.byte 10
.ascii "3 para acabar programa"
.byte 10
.byte 10
.byte 10
.ascii "Intro para continuar"
.byte 10
.byte 0

pausa:
.byte 10
.ascii "Intro para continuar"
.byte 10
.byte 0

introduce:
.byte 10
.ascii "Mete los elementos de tu lista: "
.byte 10
.byte 0

elementos:
.byte 10
.ascii "Numero de elementos: "
.byte 0
          
mensaje_lista:
.ascii "Lista: "
.byte 0                

mensaje_limite:
.byte 10
.ascii "Limite superior: "
.byte 0
