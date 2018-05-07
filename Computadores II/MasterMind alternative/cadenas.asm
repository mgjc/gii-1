	.module cadenas

	.globl	menu
	.globl	instrucciones
	.globl	dificultad
	.globl	configuravidas
	.globl	vidas
	.globl	limpia
	.globl	jugando
	.globl	vidas
	.globl	cifra1
	.globl 	cifra2
	.globl	cifra3
	.globl	cifra4
	.globl	iguales
	.globl	dificult
	.globl	introSemilla
	.globl	generando
	.globl	numero1
	.globl	numero2
	.globl	numero3
	.globl	numero4
	.globl	presiona
	.globl	temp
	.globl	aciertos
	.globl	coincidencias
	.globl	ganador
	.globl	perdedor
	.globl	mensajeVidas
	.globl	mensajeCoincidencias
	.globl	mensajeAciertos
	.globl	semilla

		;Variables

maxd:		.byte '6
maxf:		.byte '8
min:		.byte '1
temp:		.byte 0
vidas:	.byte	'4
cifra1:	.byte	0
cifra2:	.byte	0
cifra3:	.byte	0
cifra4:	.byte	0
numero1: .byte 0
numero2: .byte 0
numero3: .byte 0
numero4: .byte 0
semilla: .byte 0
dificult:.byte 0
aciertos:.byte 0
coincidencias:.byte 0

			;Cadenas
menu:	.ascii	"-------------MASTERMIND-----------------\n"
	.ascii	"Menu\n"
	.ascii	"  1)Jugar\n"		
	.ascii	"  2)Instrucciones\n"
	.ascii	"  3)Configurar\n" 
	.ascii	"  4)Salir\n"
	.asciz	"\nSeleccione opcion: \n"
presiona: .asciz "Presiona una tecla para continuar.\n"
instrucciones:	
	.ascii	"\nEl juego pensara un numero de 3 o 4 digitos(dependiendo de la dificultad elegida) y el"
	.ascii	"jugador tendra que averiguarlos. Ademas de tener que " 		
	.asciz	"averiguar los numeros en cuestion\nDeberan estar en la posicion correcta, justo como lo penso el juego.\n" 
	
dificultad:
	.ascii	"Elija el nivel de dificultad: \n"
	.ascii 	"1)Facil\n"
	.asciz	"2)Dificil\n"
configuravidas:
	.asciz	"Elija el numero de vidas con el que va a jugar: "
		
limpia: .asciz "\33[2J\33[1;1H"

jugando:
	.asciz	"Introduzca un numero (cifra a cifra): "
iguales:
	.asciz	"\nLa cifra introducida es igual a otra o esta fuera del rango\n\n"
introSemilla: .asciz "Introduce un numero para generar la cifra a descubrir\n"
generando: .asciz "\nGenerando codigo... ("
ganador:	 .asciz "\nEnhorabuena, has ganado.\n"
perdedor: .asciz "\nLo siento, has perdido.\n"
mensajeAciertos:	.byte 10
			.asciz "Aciertos: "
mensajeCoincidencias:	.byte 10
			.asciz "Coincidencias: "
mensajeVidas:	.byte 10
		.asciz "Vidas: "
