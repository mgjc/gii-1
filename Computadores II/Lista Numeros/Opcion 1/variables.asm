	.module cadenas

    ;hacemos que todo pueda ser usado en el resto de ficheros
	.globl limpia
	.globl menu
	.globl instrucciones
	.globl total
	.globl contador
	.globl corte
	.globl mensaje_total1
	.globl mensaje_total2
	.globl mensaje_lista
	.globl introduce
	.globl pide_corte
	.globl pausa
	.globl resta
	.globl decenas
	
total:      .byte 0
contador:   .byte 0
corte:      .byte 0
resta:      .byte 0
decenas:    .byte 0
	
menu:   .ascii "    Lista de numeros"
        .byte 10
        .byte 10
        .ascii " 1) Introduce y muestra"
        .byte 10
        .ascii " 2) Instrucciones"
        .byte 10
        .ascii " 3) Salir"
        .byte 10
        .byte 10
        .ascii " Opcion -> "
        .byte 0
        
instrucciones:

.ascii "Pulsa 1 e introduce una lista de numeros hasta pulsar 0, el cero no se almacenara."
.byte 10
.ascii "Introduce un numero, ese sera el numero de corte, si hay alguno en tu lista igual "
.ascii "o superior a este se eliminara. Tanto al inicio como al final se muestra el numero de elementos que hay"
.byte 10
.ascii "Una vez acabada la ejecucion se vaciara la lista."
.byte 10
.ascii "Pulsa 2 para mostrar de nuevo estas instrucciones"
.byte 10
.ascii "Pulsa 3 para salir del programa"
.byte 10
.byte 10
.ascii "<< Pulsa una tecla para continuar >>"
.byte 10
.byte 0
pausa:
.byte 10
.ascii "<< Pulsa una tecla para continuar >>"
.byte 10
.byte 0

introduce:
.byte 10
.ascii "Introduce una serie de numeros aleatorios: "
.byte 10
.byte 0

mensaje_total1:
.byte 10
.ascii "En tu lista quedan: "
.byte 0
                
mensaje_total2:
.ascii " elementos"
.byte 10
.byte 0
                
mensaje_lista:
.ascii "Tu lista:"
.byte 10
.byte 0                

pide_corte:
.byte 10
.ascii "Introduce un numero para el corte: "
.byte 0
limpia:
.asciz "\33[2J\33[1;1H"
